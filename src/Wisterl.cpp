#include <extern.h>
#include <file.h>
#include <io.h>

#include <algorithm>
#include <cctype>
#include <complex>
#include <cstdio>
#include <map>
#include <random>
#include <string>
#include <thread>
#include <vector>

// 全局函数区
// 函数列表
std::map<std::string, function> command;
// 当前用户名
std::string username = "Guest";

// 功能类

// 打开网页
void OpenWeb(const std::string &url) {
    std::string command[2] = {"start " + url, "xdg-open " + url};
#if _WIN32
    system(command[0].c_str());
#else
#endif
#if __linux__
    system(command[1].c_str());
#endif
}

// 添加命令
void AddCommand(const std::string &name, void (*func)(), std::string describe) {
    command[name] = {func, describe};
}

// 运行命令
void RunCommand(const std::string &name) {
    if (command.contains(name)) {
        command[name].function();
    } else {
        printf("未找到命令: %s\n", name.c_str());
    }
}

// 打印输出命令
void OutputCommand() {
    printf("%-22s%s\n", "命令", "描述");
    for (auto i : command)
        printf("%-20s%s\n", i.first.c_str(), i.second.describe.c_str());
}

void AllToUpper(std::string *str) {
    for (auto &c : *str) {
        c = static_cast<char>(toupper(c));
    }
}

// 计算
namespace Calc {
// 加法
std::string add(const std::string &addendA, const std::string &addendB) {
    std::string ans;
    size_t lenA = addendA.length(), lenB = addendB.length(), f = 0;
    while (lenA || lenB) {
        const int numA = lenA ? addendA[--lenA] - '0' : 0;
        const int numB = lenB ? addendB[--lenB] - '0' : 0;
        const size_t addAns = numA + numB + f;
        ans += std::to_string(addAns % 10);
        f = addAns / 10;
    }
    // 反转字符串
    std::ranges::reverse(ans);
    return ans;
}

// 减法
std::string sub(const std::string &minuend, const std::string &subtrahend) {
    std::string ans;
    size_t lenA = minuend.length(), lenB = subtrahend.length(), borrow = 0;
    while (lenA || lenB) {
        const int numA = lenA ? minuend[--lenA] - '0' : 0;
        const int numB = lenB ? subtrahend[--lenB] - '0' : 0;
        int subAns = static_cast<int>(numA - numB - borrow);
        if (subAns < 0) {
            subAns += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        ans += std::to_string(subAns % 10);
    }
    std::ranges::reverse(ans);
    ans.erase(0, ans.find_first_not_of('0'));
    return ans;
}

// 乘法

using cd = std::complex<double>;
const double PI = acos(-1);

void fft(std::vector<cd> &a, bool invert) {
    int n = a.size();
    if (n <= 1) return;

    std::vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * 3.14 / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));

    for (int i = 0; i < n / 2; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

std::string mul(const std::string &a, const std::string &b) {
    if (a == "0" || b == "0") return "0";

    std::vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    for (auto &c : fa) c -= '0';
    for (auto &c : fb) c -= '0';

    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);

    std::string result;
    int carry = 0;
    for (int i = a.size() + b.size() - 2; i >= 0; i--) {
        int num = round(fa[i].real()) + carry;
        carry = num / 10;
        result.push_back(num % 10 + '0');
    }
    if (carry) result.push_back(carry + '0');

    reverse(result.begin(), result.end());
    return result.empty() ? "0" : result;
}
}  // namespace Calc

// 应用类
void calc() {
    printf("欢迎使用计算器\n请输入算式: ");
    std::string expression;
    IO::scanfs(expression);
    if (expression.find('+') != std::string::npos) {
        const size_t add = expression.find('+');
        const std::string right = expression.substr(0, add);
        const std::string left =
            expression.substr(add + 1, expression.length());
        printf("%s + %s = %s\n", right.c_str(), left.c_str(),
               Calc::add(right, left).c_str());
    }
    if (expression.find('-') != std::string::npos) {
        const size_t sub = expression.find('-');
        const std::string right = expression.substr(0, sub);
        const std::string left =
            expression.substr(sub + 1, expression.length());
        printf("%s - %s = %s\n", right.c_str(), left.c_str(),
               Calc::sub(right, left).c_str());
    }
    if (expression.find('*') != std::string::npos) {
        const size_t sub = expression.find('*');
        const std::string right = expression.substr(0, sub);
        const std::string left =
            expression.substr(sub + 1, expression.length());
        printf("%s * %s = %s\n", right.c_str(), left.c_str(),
               Calc::mul(right, left).c_str());
    }
    if (expression.find('/') != std::string::npos) {
        int right = 0, left = 0;
        try {
            const size_t lc = expression.find('/');
            right = stoi(expression.substr(0, lc));
            left = stoi(expression.substr(lc + 1, expression.length()));
        } catch (const std::exception &e) {
            printf("程序出现错误, 错误为 %s, 可能原因: 算数过大\n", e.what());
        }
        printf("%d / %d = %d\n", right, left, right / left);
    }
}

void notes() {
    puts("文本编辑器");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    printf("\033[2J\033[1;1H");
    printf("这是一个文本自由写作器，可以在这里写作，最后要敲'|'+ enter结束\n");
    std::string text;
    IO::scanfA(text, '|');
    IO::ClearCache();
    printf("是否要保存[y/n]: ");
    getchar();
    if (getchar() == 'y') {
        printf("请输入文件名称: ");
        std::string filename;
        getchar();
        IO::scanfA(filename, '\n');
        // if (FILE *file = fopen(filename.c_str(), "w+")) {
        //   if (!text.empty() && text[0] == '\n')
        //     text.erase(0, text.find_first_not_of('\n'));
        //   fprintf(file, "%s", text.c_str());
        //   fclose(file);
        // } else {
        //   printf("无法打开文件");
        // }
        File file(filename);
        if (!file.Write(text)) {
            printf("无法写入文件\n");
        }
    }
}

// 未来信箱
void mail() {
    puts("你自己的未来信箱");
    std::string name, things, fut;
    printf("输入你的名字：");
    IO::scanfA(name, '\n');
    printf("输入你未来想做的职业：");
    IO::scanfA(things, '\n');
    printf("输入你的愿望: ");
    IO::scanfA(fut, '\n');
    puts("已发送！");
    puts("是否查看信件(y/n)");
    if (getchar() == 'n') {
        IO::ClearCache();
        return;
    } else {
        printf("来自以前的 %s 的一封信:", name.c_str());
        puts(" ");
        printf(
            "你好，未来的 %s ，我希望你成为一名 %s ，我想你 %s "
            "，希望你能完成！！！\n\n",
            name.c_str(), things.c_str(), fut.c_str());
        printf("          ----------------- 从前的 %s\n", name.c_str());
    }
}

// 扫雷游戏
void MineSweeper() {
    printf("编写者： BlocksFunction\n");
    bool tg = false;
    int w, h;
    printf("请输入行数: ");
    scanf("%d", &w);
    printf("请输入列数: ");
    scanf("%d", &h);
    std::vector<std::vector<char>> minemap(h, std::vector<char>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 1; j < w + 1; ++j) {
            minemap[i][j] = '.';
        }
    }
    int Minecou = static_cast<int>(h * w * 0.15);
    if (0 < Minecou) {
        int ls = 0;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> wrd(0, w - 1);
        std::uniform_int_distribution<> hrd(0, h - 1);
        int i = 0;
        do {
            int wl, hl;
            do {
                wl = wrd(gen);
                hl = hrd(gen);
            } while (minemap[hl][wl] == '*');
            minemap[hl][wl] = '*';
            ++ls;
            ++i;
        } while (i < Minecou);
    }
    bool cail = false;
    puts("当前地图:");
    for (int i = 0; i < h; ++i) {
        if (i == 0) {
            printf("   ");
            for (int j = 1; j < w + 1; ++j) {
                printf("%d ", j);
            }
            printf("\n");
        }
        printf("%d |", i);
        for ([[maybe_unused]] auto i1 : minemap[i]) {
            printf(". ");
        }
        printf("\n");
    }
    do {
        tg = true;
        int ww, hh;
        printf("请输入你要扫的坐标的所属列: ");
        scanf("%d", &ww);
        printf("请输入你要扫的坐标的所属行: ");
        scanf("%d", &hh);
        if (minemap[ww - 1][hh - 1] != '*') {
            minemap[ww - 1][hh - 1] = '1';
            printf("你很幸运 没中雷\n");
            for (int i = 0; i < h; ++i) {
                if (i == 0) {
                    printf("   ");
                    for (int j = 1; j < w + 1; ++j) {
                        printf("%d ", j);
                    }
                    printf("\n");
                }
                printf("%d |", i);
                for (auto &tx : minemap[i]) {
                    if (tx == '1')
                        printf("1 ");
                    else
                        printf(". ");
                }
                printf("\n");
            }
        } else {
            cail = true;
            break;
        }
        for (auto &rw : minemap) {
            for (char tx : rw) {
                if (tx == '.') {
                    tg = false;
                    break;
                }
            }
            if (!tg) break;
        }
    } while (!tg);
    if (cail) {
        printf("BOOM! 你中雷了\n");
        for (int i = 0; i < h; ++i) {
            if (i == 0) {
                printf("   ");
                for (int j = 1; j < w + 1; ++j) {
                    printf("%d ", j);
                }
                printf("\n");
            }
            printf("%d |", i);
            for (const auto &tx : minemap[i]) {
                printf("%c ", tx);
            }
            printf("\n");
        }
        return;
    }
    printf("恭喜你成功通关\n");
    for (int i = 0; i < h; ++i) {
        if (i == 0) {
            printf("   ");
            for (int j = 1; j < w + 1; ++j) {
                printf("%d ", j);
            }
            printf("\n");
        }
        printf("%d |", i);
        for (auto &tx : minemap[i]) {
            printf("%c ", tx);
        }
        printf("\n");
    }

    getchar();
}

// 输出终末之诗

void EndPoem() {
    const char *name = username.c_str();
    printf("\n");
    IO::PrintfBlue("I see the player you mean.\n");
    IO::PrintfGreen(name);
    IO::PrintfGreen("?\n");
    IO::PrintfBlue(
        "Yes. Take care. It has reached a higher level now. It can read "
        "our thoughts.\n");
    IO::PrintfGreen(
        "That doesn't matter. It thinks we are part of the game.\n");
    IO::PrintfBlue("I like this player. It played well. It did not give up.\n");
    IO::PrintfGreen(
        "It is reading our thoughts as though they were words on a screen.\n");
    IO::PrintfBlue(
        "That is how it chooses to imagine many things, when it is deep "
        "in the dream of a game.\n");
    IO::PrintfGreen(
        "Words make a wonderful interface. Very flexible. And less "
        "terrifying than staring at the reality behind the screen.\n");
    IO::PrintfBlue(
        "They used to hear voices. Before players could read. Back in "
        "the days when those who did not play called the players "
        "witches, and warlocks. And players dreamed they flew through "
        "the air, on sticks powered by demons.\n");
    IO::PrintfGreen("What did this player dream?\n");
    IO::PrintfBlue(
        "This player dreamed of sunlight and trees. Of fire and water. "
        "It dreamed it created. And it dreamed it destroyed. It dreamed "
        "it hunted, and was hunted. It dreamed of shelter.\n");
    IO::PrintfGreen(
        "Hah, the original interface. A million years old, and it still "
        "works. But what true structure did this player create, in the "
        "reality behind the screen?\n");
    IO::PrintfGreen(
        "It worked, with a million others, to sculpt a true world in a "
        "fold of\n");
    IO::PrintfBlue(
        "the <Error> and created a <Error> for <Error> in the <Error>\n");
    IO::PrintfGreen("It cannot read that thought.\n");
    IO::PrintfBlue(
        "No. It has not yet achieved the highest level. That, it "
        "must achieve in "
        "the long dream of life, not the short dream of a game.\n");
    IO::PrintfGreen(
        "Does it know that we love it? That the universe is kind?\n");
    IO::PrintfBlue(
        "Sometimes, through the noise of its thoughts, it hears the "
        "universe, yes.\n");
    IO::PrintfGreen(
        "But there are times it is sad, in the long dream. It creates "
        "worlds that have no summer, and it shivers under a black sun, "
        "and it takes its sad creation for reality.\n");
    IO::PrintfBlue(
        "To cure it of sorrow would destroy it. The sorrow is part of "
        "its own private task. We cannot interfere.\n");
    IO::PrintfGreen(
        "Sometimes when they are deep in dreams, I want to tell them, "
        "they are building true worlds in reality. Sometimes I want to "
        "tell them of their importance to the universe. Sometimes, when "
        "they have not made a true connection in a while, I want to "
        "help them to speak the word they fear.\n");
    IO::PrintfBlue("It reads our thoughts.\n");
    IO::PrintfGreen(
        "Sometimes I do not care. Sometimes I wish to tell them, this "
        "world you take for truth is merely <Error> and <Error> I wish "
        "to tell them that they are <Error> in the <Error> I wish to "
        "tell them that they are <Error> in the <Error> They see so "
        "little of reality, in their long dream.\n");
    IO::PrintfBlue("And yet they play the game.\n");
    IO::PrintfGreen("But it would be so easy to tell them...\n");
    IO::PrintfBlue(
        "Too strong for this dream. To tell them how to live is to prevent\n");
    IO::PrintfGreen("them living.\n");
    IO::PrintfGreen("I will not tell the player how to live.\n");
    IO::PrintfBlue("The player is growing restless.\n");
    IO::PrintfGreen("I will tell the player a story.\n");
    IO::PrintfBlue("But not the truth.\n");
    IO::PrintfGreen(
        "No. A story that contains the truth safely, in a cage of "
        "words. Not the naked truth that can burn over any distance.\n");
    IO::PrintfBlue("Give it a body, again.\n");
    IO::PrintfGreen("Yes. Player…\n");
    IO::PrintfBlue("Use its name.\n");
    IO::PrintfGreen(name);
    IO::PrintfGreen(". Player of games.");
    IO::PrintfBlue("\nGood.\n");
    IO::PrintfGreen(
        "Take a breath, now. Take another. Feel air in your lungs. Let your "
        "limbs return. Yes, move your fingers. Have a body again, under "
        "gravity, "
        "in air. Respawn in the long dream. There you are. Your body touching "
        "the universe again at every point, as though you were separate "
        "things. "
        "As though we were separate things.\n");
    IO::PrintfBlue(
        "Who are we? Once we were called the spirit of the mountain. "
        "Father sun, mother moon. Ancestral spirits, animal spirits. "
        "Jinn. Ghosts. The green man. Then gods, demons. Angels. "
        "Poltergeists. Aliens, extraterrestrials. Leptons, quarks. The "
        "words change. We do not change.\n");
    IO::PrintfGreen(
        "We are the universe. We are everything you think isn't you. You are "
        "looking at us now, through your skin and your eyes. And why does the "
        "universe touch your skin, and throw light on you? To see you, player. "
        "To know you. And to be known. I shall tell you a story.\n");
    IO::PrintfGreen("Once upon a time, there was a player.\n");
    IO::PrintfBlue(name);
    IO::PrintfGreen(
        "\nSometimes it thought itself human, on the thin crust of a spinning "
        "globe of molten rock. The ball of molten rock circled a ball of "
        "blazing "
        "gas that was three hundred and thirty thousand times more massive "
        "than "
        "it. They were so far apart that light took eight minutes to cross the "
        "gap. The light was information from a star, and it could burn your "
        "skin "
        "from a hundred and fifty million kilometres away.\n");
    IO::PrintfGreen(
        "Sometimes the player dreamed it was a miner, on the surface of "
        "a world that was flat, and infinite. The sun was a square of "
        "white. The days were short; there was much to do; and death "
        "was a temporary inconvenience.\n");
    IO::PrintfBlue("Sometimes the player dreamed it was lost in a story.\n");
    IO::PrintfGreen(
        "Sometimes the player dreamed it was other things, in other "
        "places. Sometimes these dreams were disturbing. Sometimes very "
        "beautiful indeed. Sometimes the player woke from one dream "
        "into another, then woke from that into a third.\n");
    IO::PrintfBlue(
        "Sometimes the player dreamed it watched words on a screen\n");
    IO::PrintfGreen("Let's go back.\n");
    IO::PrintfGreen(
        "The atoms of the player were scattered in the grass, in the rivers, "
        "in "
        "the air, in the ground. A woman gathered the atoms; she drank and ate "
        "and inhaled; and the woman assembled the player, in her body.\n");
    IO::PrintfGreen(
        "And the player awoke, from the warm, dark world of its "
        "mother's body, into the long dream.\n");
    IO::PrintfGreen(
        "And the player was a new story, never told before, written in letters "
        "of DNA. And the player was a new program, never run before, generated "
        "by a sourcecode a billion years old. And the player was a new human, "
        "never alive before, made from nothing but milk and love.\n");
    IO::PrintfBlue(
        "You are the player. The story. The program. The human. Made "
        "from nothing but milk and love.\n");
    IO::PrintfGreen("Let's go further back.\n");
    IO::PrintfGreen(
        "The seven billion billion billion atoms of the player's body were "
        "created, long before this game, in the heart of a star. So the "
        "player, "
        "too, is information from a star. And the player moves through a "
        "story, "
        "which is a forest of information planted by a man called Julian, on a "
        "flat, infinite world created by a man called Markus, that exists "
        "inside "
        "a small, private world created by the player, who inhabits a universe "
        "created by…\n");
    IO::PrintfBlue(
        "Shush. Sometimes the player created a small, private world that "
        "was soft and warm and simple. Sometimes hard, and cold, and "
        "complicated. Sometimes it built a model of the universe in its "
        "head; flecks of energy, moving through vast empty spaces. "
        "Sometimes it called those flecks “electrons” and “protons”.\n");
    IO::PrintfGreen("Sometimes it called them “planets” and “stars”.\n");
    IO::PrintfGreen(
        "Sometimes it believed it was in a universe that was made of "
        "energy that was made of offs and ons; zeros and ones; lines of "
        "code. Sometimes it believed it was playing a game. Sometimes "
        "it believed it was reading words on a screen.\n");
    IO::PrintfBlue("You are the player, reading words…\n");
    IO::PrintfGreen(
        "Shush… Sometimes the player read lines of code on a screen. Decoded "
        "them into words; decoded words into meaning; decoded meaning into "
        "feelings, emotions, theories, ideas, and the player started to "
        "breathe "
        "faster and deeper and realised it was alive, it was alive, those "
        "thousand deaths had not been real, the player was alive\n");
    IO::PrintfBlue("You. You. You are alive.\n");
    IO::PrintfGreen(
        "and sometimes the player believed the universe had spoken to "
        "it through the sunlight that came through the shuffling leaves "
        "of the summer trees\n");
    IO::PrintfBlue(
        "and sometimes the player believed the universe had spoken to it "
        "through "
        "the light that fell from the crisp night sky of winter, where a fleck "
        "of light in the corner of the player's eye might be a star a million "
        "times as massive as the sun, boiling its planets to plasma in order "
        "to "
        "be visible for a moment to the player, walking home at the far side "
        "of "
        "the universe, suddenly smelling food, almost at the familiar door, "
        "about to dream again\n");
    IO::PrintfGreen(
        "and sometimes the player believed the universe had spoken to it "
        "through "
        "the zeros and ones, through the electricity of the world, through the "
        "scrolling words on a screen at the end of a dream\n");
    IO::PrintfBlue("and the universe said I love you\n");
    IO::PrintfGreen("and the universe said you have played the game well\n");
    IO::PrintfBlue("and the universe said everything you need is within you\n");
    IO::PrintfGreen("and the universe said you are stronger than you know\n");
    IO::PrintfBlue("and the universe said you are the daylight\n");
    IO::PrintfGreen("and the universe said you are the night\n");
    IO::PrintfBlue(
        "and the universe said the darkness you fight is within you\n");
    IO::PrintfGreen("and the universe said the light you seek is within you\n");
    IO::PrintfBlue("and the universe said you are not alone\n");
    IO::PrintfGreen(
        "and the universe said you are not separate from every other thing\n");
    IO::PrintfBlue(
        "and the universe said you are the universe tasting itself, "
        "talking to itself, reading its own code\n");
    IO::PrintfGreen("and the universe said I love you because you are love.\n");
    IO::PrintfBlue(
        "And the game was over and the player woke up from the dream. And the "
        "player began a new dream. And the player dreamed again, dreamed "
        "better. "
        "And the player was the universe. And the player was love.\n");
    IO::PrintfBlue("You are the player.\n");
    IO::PrintfGreen("Wake up.\n");
}

// 千万别点
void DontCLick() {
    printf(
        "Warning!"
        "本系统对“千万要点”所造成的bug和对电脑的伤害概不负责，是否继续操作? "
        "(Y/Y/Y)");
    char mode;
    scanf("%c", &mode);
    if (mode == 'y')
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 10; ++j) printf("乐滋");
            printf("\n");
        }
}

// 主函数
int main() {
    setbuf(stdout, nullptr);

    puts("请您先登陆");
    puts("请输入账号与密码");

    std::string username, password;

    IO::scanfs(username);
    AllToUpper(&username);
    // 如果是访客
    if (username == "GUEST") goto Run;

    IO::scanfs(password);
    AllToUpper(&password);

    if (username == "ED_WIS_GFZH" && password == "GH5TER") {
        bool IsNew = true;
        File userfile("username.list", &IsNew);

        if (!IsNew) {
            printf("请输入帐号名: ");
            IO::ClearCache();
            IO::scanfA(username, '\n');
            if (username.empty()) username = "Admin";
            if (!userfile.Write(username)) {
                printf("无法写入文件\n");
            } else {
                // bool IsNew = true;
                const File file("username.list");
                if (char buffer[16];
                    std::fgets(buffer, 15, file.GetFilePtr()) != nullptr) {
                    username = buffer;
                    printf("欢迎回来, %s", username.c_str());
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                }
            }
        }
    }

Run:
    AddCommand("End poem", EndPoem, "输出终末之诗");
    AddCommand(
        "leetcode",
        []() -> void {
            puts("力扣网站-----全世界人(精神病患者)的选择");
            IO::printfs(
                "请注意，本次的编程之旅，可能会引起夜间盗汗，使用之前务必咨"
                "询相关医生"
                "使用！！！\n",
                30);
            printf("确定？(Y/N)");

            char c = static_cast<char>(getchar());

            IO::ClearCache();

            if (c == 'Y') {
                puts("你确定的话，我就不管你了");

                std::this_thread::sleep_for(std::chrono::seconds(1));

                OpenWeb("https://www.leetcode.cn/");
            } else {
                return;
            }
        },
        "打开Leetcode");
    AddCommand(
        "exit",
        []() -> void {
            printf("感谢使用");

            exit(0);
        },
        "退出程序");
    AddCommand("Minesweeper", MineSweeper, "扫雷");
    AddCommand("help", OutputCommand, "获取命令列表");
    AddCommand("calc", calc, "一个计算器");

    std::string input_command;

    OutputCommand();

    while (true) {
        input_command.clear();

        printf("请输入命令: ");

        IO::scanfA(input_command, '\n');

        RunCommand(input_command);
    }
    return 0;
}
