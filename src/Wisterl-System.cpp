// this is a wonderful windows 19.2.2
#include <chrono>
#include <cstdio> // 别用bits/stdc++
#include <cstring>
#include <map>
#include <random>
#include <string>
#include <thread>

using namespace std;

char username[15];
const string cpu_xh[5] = {"Intel", "AMD", "Loongson", "Qualcomm", "NVDIA"};
const string cpu_xhcore[12] = {"Core",       "Atom",     "Celeron", "Pentium",
                               "Xeon",       "Athlon",   "Sempron", "Sempron",
                               "Snapdragon", "Scorpion", "Krait",   "Grace"};
class Username_or_password_is_incorrect : public std::exception {
  virtual const char *what() const noexcept override {
    return "错误: 用户名或密码不正确";
  }
} PasswordorUsernameError; // Password or Username not right

void Clearce() {
  setbuf(stdin, NULL);
  setbuf(stdout, NULL);
}
auto strscanf(string &str, char stopt = '\n') -> void {
  char temp;
  while ((temp = getchar()) != stopt)
    str += temp;
  Clearce();
  return;
}
template <typename T> auto allx(T &arr) -> void {
  for (auto &i : *arr)
    if (i >= 'a' && i <= 'z')
      i -= 32;
}
void OpenWeb(const char *url) {
  char command[2][100];
  snprintf(command[0], sizeof(command[0]), "start %s", url);
  snprintf(command[1], sizeof(command[1]), "xdg-open %s", url);
#if _WIN32
  system(command[0]);
#else
#endif
#if __linux__
  system(command[1]);
#endif
}

void Prints(const char text[500], int speed) // 自动换行
{
  if (strlen(text) != 0) {
    for (size_t i = 0; i < strlen(text); ++i) {
      putchar(text[i]);
      std::fflush(stdout);
      std::this_thread::sleep_for(std::chrono::milliseconds(speed));
    }
  }
  return;
}
void wechat() {
  puts("加我微信！！！");
  puts("wx号：bgp20130427.验证信息请敲：LUOGU,UID=XXX(XXX为洛谷uid号)");
  puts("额额额，我是个xxs欸！");
  return;
}
void gameku() {
  Prints("欢迎来到4399小游戏官网", 300);
  while (getchar() != '\n')
    continue;
  getchar();
  OpenWeb("https://www.4399.com");
  return;
}
void leetcode() {
  puts("力扣网站-----全世界人(精神病患者)的选择");
  Prints("请注意，本次的编程之旅，可能会引起夜间盗汗，使用之前务必咨询相关医生"
         "使用！！！",
         30);
  puts("确定？(Y/N)");
  Clearce();
  char c = getchar();
  Clearce();
  if (c == 'Y') {
    puts("你确定的话，我就不管你了"); // eeeeeeeee6
    std::this_thread::sleep_for(std::chrono::seconds(1));
    OpenWeb("https://www.leetcode.cn/");
  } else {
    return;
  }
  return;
}

long long cifang(long long number, long long cishu) {
  if (cishu == 0)
    return 1;
  long long result = 1;
  while (cishu > 0) {
    if (cishu & 1) {
      result *= number;
    }
    number *= number;
    cishu >>= 1;
  }
  return result;
}

auto alpjsq() -> void { // vanvan
  string shuanshu, temp;
  printf("欢迎使用BlocksFunction(AuroraRealm)写的Alpha版计算器\n请输入算式: ");
  Clearce();
  char c;
  strscanf(shuanshu);
  if (shuanshu.find('+') != string::npos) {
    int left, right;
    try {
      size_t lc = shuanshu.find('+');
      temp = shuanshu.substr(0, lc);
      right = stoi(temp);
      temp = shuanshu.substr(lc + 1);
      left = stoi(temp);
    } catch (const std::exception &e) {
      printf("程序出现错误, 错误为 %s, 可能原因: 算数过大\n", e.what());
    }
    printf("%d + %d = %d\n", right, left, right + left);
  }
  if (shuanshu.find('-') != string::npos) {
    int right, left;
    try {
      size_t lc = shuanshu.find('-');
      temp = shuanshu.substr(0, lc);
      right = stoi(temp);
      temp = shuanshu.substr(lc + 1);
      left = stoi(temp);
    } catch (const std::exception &e) {
      printf("程序出现错误, 错误为 %s, 可能原因: 算数过大\n", e.what());
    }
    printf("%d - %d = %d\n", right, left, right - left);
  }
  if (shuanshu.find('*') != string::npos) {
    int right, left;
    try {
      size_t lc = shuanshu.find('*');
      temp = shuanshu.substr(0, lc);
      right = stoi(temp);
      temp = shuanshu.substr(lc + 1);
      left = stoi(temp);
    } catch (const std::exception &e) {
      printf("程序出现错误, 错误为 %s, 可能原因: 算数过大\n", e.what());
    }
    printf("%d * %d = %d\n", right, left, right * left);
  }
  if (shuanshu.find('/') != string::npos) {
    int right, left;
    try {
      size_t lc = shuanshu.find('/');
      temp = shuanshu.substr(0, lc);
      right = stoi(temp);
      temp = shuanshu.substr(lc + 1);
      left = stoi(temp);
    } catch (const std::exception &e) {
      printf("程序出现错误, 错误为 %s, 可能原因: 算数过大\n", e.what());
    }
    printf("%d / %d = %d\n", right, left, right / left);
  }
  if (shuanshu.find('^') != string::npos) {
    long long int right, left;
    size_t lc = shuanshu.find('^');
    temp = shuanshu.substr('^');
    right = stoi(temp);
    temp = shuanshu.substr(lc + 1);
    left = stoi(temp);
    printf("%lld ^ %lld = %lld\n", right, left, cifang(right, left));
  }
  if (shuanshu.find('s') != string::npos) {
    printf("求根运算可能不准确\n");
    // 以下这些代码选自游戏《Quake-III Arena》
    size_t lc = shuanshu.find('s');
    temp = shuanshu.substr(lc + 1);
    double n = stoi(temp);
    double j = n;
    if (n == 0)
      printf("sqrt(0) = 0\n");
    float result = n;
    float xhalf = 0.5f * result;
    int i = *(int *)&result;
    i = 0x5f3759df - (i >> 1);
    result = *(float *)&i;
    result = result * (1.5f - xhalf * result * result);
    result = result * (1.5f - xhalf * result * result);
    printf("sqrt(%lf) = %lf\n", j, 1.0f / result);
  }
  return;
}
void CPS() {
  printf("测试你的每秒点击速度---------点击更多，KB越小！！！\n");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  OpenWeb("https://www.clickpersecond.com/cn/1-second/");
  return;
}
void mail() {
  setvbuf(stdin, NULL, _IONBF, 0);
  puts("你自己的未来信箱");
  char name[20], things[50], fut[100];
  int yesorno;
  printf("输入你的名字：");
  fgets(name, 20, stdin);
  printf("输入你未来想做的职业：");
  fgets(things, 50, stdin);
  printf("输入你的愿望: ");
  fgets(fut, 100, stdin);
  puts("已发送！");
  puts("是否查看信件(1/0)");
  scanf("%d", &yesorno);
  if (yesorno == 0) {
    return;
  } else {
    printf("Dear %s:", name);
    puts(" ");
    printf("你好，未来的 %s ，我希望你成为一名 %s ，我想你 %s "
           "，希望你能完成！！！\n",
           name, things, fut);
    puts("");
    printf("          ----------------- %s\n", name);
  }
  return;
}

void bd() {
  printf("百度一下\n");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  OpenWeb("https://www.baidu.com/");
  return;
}

void ahaoj() { OpenWeb("https://www.acoj.com"); }

void text() {
  printf("刷题时间到了，刷题吧！\n");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  printf("请输入题号: ");
  char tihao[100], neir[133];
  scanf("%s", tihao);
  sprintf(neir, "https://www.luogu.com.cn/problem/%s", tihao);
  OpenWeb(neir);

  return;
}

char *nowtm() {
  std::chrono::time_point time = std::chrono::system_clock::now();
  time_t nowtime = std::chrono::system_clock::to_time_t(time);
  struct tm *locate = localtime(&nowtime);
  static char crte[9];
  sprintf(crte, "%02d:%02d:%02d", locate->tm_hour, locate->tm_min,
          locate->tm_sec);
  return crte;
}

void presenter() {
  printf("朋友们大家好，现在的时间是: %s", nowtm());
  puts("");
  puts("世界那么大，我想去看看");
  puts("来来来");
  OpenWeb("https://www.luogu.com.cn/team/71582");
  return;
}

void ziyanfa() {
  printf("您已进入自研发解析\n");
  puts("名：TbS-FXS-endsts");
  int sxsxdsx;
  puts("请输入数字");
  puts("列表：");
  puts("0.退出 1.钟表 2.团队 3.简介");
  while (true) {
    scanf("%d", &sxsxdsx);
    if (sxsxdsx == 0) {
      return;
    }
    if (sxsxdsx == 1) {
      printf("时间%s\n", nowtm());
    }
    if (sxsxdsx == 2) {
      puts("我们的研发团队: Wisterl团队");
      puts("详情见QQ群908658106");
      Prints("若想退出，请在这段文字结束后按 [0] 退出\n", 100);
    }
    if (sxsxdsx == 3) {
      puts("系统已实现自研发！！！");
      puts("这是一个系统");
      puts("系统高效又好笑");
      Prints("若想退出，请在这段文字结束后按 [0] 退出\n", 100);
    }
    return;
  }
}

void downcpp() {
  // puts("来来来，下c++载来！");
  printf("\n有四种选择:\n1. 下载DevC++(很老并且已停止更新的自带Mingw的IDE)\n2. "
         "下载MinGW\n3. 用微软的Visual Studio(或MSVC)\n4. "
         "下载Clang(和LLVM)\n请选择你的模式[D/M/V/L]");
  Clearce();
  char mode = getchar();
  Clearce();
  switch (mode) {
  case 'D':
    OpenWeb("https://www.onlinedown.net/soft/9500.htm");
    break;
  case 'M': {
    printf("还有两种选择:\n1. 下载Github上的MinGW编译版\n2. "
           "到MinGW64官网下载(Mingw32请自行下载)\n请选择你的模式[G/M]");
    mode = getchar();
    Clearce();
    switch (mode) {
    case 'G':
      OpenWeb("http://www.github.com/niXman/mingw-builds-binaries/releases");
      break;
    case 'M':
      OpenWeb("https://www.mingw-w64.org/");
      break;
    }
    break;
  } // 这里只能用括号包起来
  case 'V':
    OpenWeb("http://visualstudio.microsoft.com");
    break;
  case 'L':
    printf("访问可能比较慢, 请稍等\n我们将给你两个下载渠道 一个是Github "
           "一个是官网\n");
    OpenWeb("https://github.com/llvm/llvm-project/releases");
    OpenWeb("https://clang.llvm.org/");
    break;
  default:
    printf("错误: 模式 %c 不存在\n", mode);
    break;
  }
  // std::this_thread::sleep_for(std::chrono::seconds(2));
  // OpenWeb("https://www.onlinedown.net/soft/9500.htm");
  return;
}

void chinajy() {
  puts("国家云教育平台");
  std::this_thread::sleep_for(std::chrono::seconds(2));
  OpenWeb("https://basic.smartedu.cn/");
  return;
}

void funnyth() {
  printf("神奇的事情");
  std::this_thread::sleep_for(std::chrono::seconds(2));
  OpenWeb("https://www.lglg.top/61884");
  return;
}

void codeforces() {
  printf("CODEFORCES----百万编程人士的信赖");
  OpenWeb("https://www.codeforces.com/");
  return;
}

void game() {
  Prints("想玩游戏了吗？和我来吧！", 50);
  printf("网友自制minecraft");
  while (getchar() != '\n')
    continue;
  getchar();
  OpenWeb("https://ws.imc.re/");
  // puts("哎呦我，老得劲了！！"); sunyuhao你这写的太抽象了吧 --- 某A
  return;
}

void gametwo() {
  Prints("轻松时刻-------游戏时刻\n", 300);
  // system("echo google小恐龙在线版本！！！"); 666
  puts("google小恐龙在线版本\n");
  while (getchar() != '\n')
    continue;
  getchar();
  OpenWeb("dinorunner.com/zh/");
  return;
}

void txt() {
  puts("文本编辑器");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  printf("\033[2J\033[1;1H");
  printf("这是一个文本自由写作器，可以在这里写作，最后要敲'`'+ enter结束\n");
  string totext;
  strscanf(totext, '`');
  printf("是否要保存[y/n]: ");
  getchar();
  char yon = getchar();
  if (yon == 'y') {
    printf("请输入文件名称: ");
    string filename;
    getchar();
    strscanf(filename);
    FILE *file;
    file = fopen(filename.c_str(), "w+");
    if (totext[0] == '\n')
      fprintf(file, "%s", totext.c_str() + 1);
    else
      fprintf(file, "%s", totext.c_str());
    fclose(file);
  }
  return;
}

void cpu() {
  // random, start!
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 4);
  std::uniform_int_distribution<> dis2(0, 11);
  std::uniform_int_distribution<> dis3(100, 999);
  std::uniform_int_distribution<> dis4(1, 999);
  printf("cpuh配置: %s %s\n", cpu_xh[dis(gen)].c_str(),
         cpu_xhcore[dis2(gen)].c_str());
  // (:
  printf("ip地址：%d.%d.%d.%d\n", dis3(gen), dis3(gen), dis4(gen), dis4(gen));
  return;
}

void copyright() {
  puts("Copyright by sunyuhao and alanbecker C");
  return;
}

void input_zll() {
  puts("智能指令开启网站！！！");
  puts("输入");
  string url;
  strscanf(url);
  OpenWeb(url.c_str());
  //	char str2[1024];
  // cin.getline(str2,1024);//读入char数组
  return;
}

void catstore() {
  puts("由于技术原因，个人商店暂不支持在该版本上使用，只能用淘宝，望见谅。");
  puts("");
  puts("");
  puts("");
  puts("                                                          白格平");
  puts("                                                   2023年12月28日");
  return;
}

void jd() {
  puts("来买东西吧！");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  OpenWeb("https://www.jd.com/");
}

void kfcid() {
  Prints("QQ腾讯网-----搜索更多的事情", 500);
  OpenWeb("https://www.qq.com/");
  Prints("66666", 500);
  Prints("666666666666666666666", 500);
  // Prints("QQ腾讯网-----搜索更多的事情66666666666666666666666666", 500); //
  // 为什么要输很多"6" Prints("QQ腾讯网-----搜索更多的事情66666666666666666666",
  // 500);
  return;
}

void fy() {
  puts("Deepl翻译------难题翻译我最行！");
  OpenWeb("https://www.deepl.com/");
  puts("66666666666666666");
  Prints("666666666666666666666", 200);
  return;
}

void address() {
  puts("We are in:");
  puts("中国辽宁省阜新市海州区中华路129-2-206科技有限公司");
  return;
}

void state() {
  puts("配置");
  puts("cpu_xh：CNQXZ-C9000S 3.2THZ");
  puts("GPU：CNQXZ-G9000S 5GB存储 2.33THZ  30.2兆 图形渲染/秒");
  puts("RAM: 64GB  ROM: 12TB");
  puts("16位 DOS式系统     CN-QX-OS V12.1.2");
  puts("状态");
  printf("CPU使用率: %d", rand() % 15);
  printf("GPU使用率: %d", rand() % 15);
  printf("RAM使用率: %d", rand() % 10);
  printf("ROM使用率: %d", rand() % 5);
  return;
}

void prog() {
  puts("好用的在线编译网站--Programiz");
  std::this_thread::sleep_for(std::chrono::seconds(3));
  OpenWeb("https://www.programiz.com/");
  return;
}

void update() {
  puts("2023-12-23 1.0.0 梦开始的地方");
  puts("2023-12-24 1.0.1 更改了开场动画，增加了进度条，开始写了第一条命令");
  puts("2023-12-28 1.0.2 写了更多的命令和程序");
  puts("2023-12-31 1.0.3 更改了开场动画，写了更多的命令");
  puts("2023-12-31 1.0.4 写了更多的命令和程序");
  puts("2024-1-2   1.0.5 修改了许多bug");
  puts("2024-1-8   1.0.6 写了更多命令，and went to Harbin所以更新较晚");
  puts("2024-1-13  1.0.7 写了更多命令(考试成绩出来了吗？)");
  puts("2024-1-13  1.0.8 瞬间更新，加了baidu浏览器");
  puts("2023-1-14  1.0.9 更改了开场动画(搞笑)");
  puts("2024-1-14  1.1.0 写了更多命令");
  puts("2024-1-22  1.1.1 快看我微信！(嗨害嗨)");
  puts("2024-1-23  1.1.2 加了个下载c++");
  puts("2024-2-3   1.1.3 加了商品(需依赖外网)");
  puts("2024-4-26  1.1.4 发现开机动画有问题，改了一下(更新很晚，差点退洛谷)");
  puts("2024-4-26  1.1.5 不对，有问题！！(咋回事？为何没有关于本机？？)");
  puts("2024-4-26  1.1.6 微信又又又又改了一下");
  puts("2024-4-26  1.1.7 将pause改了，修了BuG");
  puts("2024-4-27  1.1.8 重新增加题库！！");
  puts("2024-4-27  1.1.9 改掉系统介绍，换成编程系统");
  puts("2024-4-27  1.2.0 改掉写字板，弄了个结构");
  puts("2024-4-27  1.2.1 把开机文字改掉，换了动画某个字，把金坷垃删了");
  puts("2024-4-27  1.2.2 写了个游戏指令");
  puts("2024-4-27  1.2.3 修改动画格式");
  puts("2024-5-10  1.2.4 又写了个游戏指令");
  puts("2024-5-10  1.2.5 改了个游戏指令");
  puts("2024-5-10  2.0.0 超级大更新系统，十分先进，加了一个半自动浏览网页装置");
  puts("2024-5-10  2.1.0 "
       "终于实现全部自动化关机！！！恭喜！！！！(所以改了一下版本)");
  puts("2024-5-11  2.1.1 得到了力扣网站！！！！！！！！！");
  puts("2024-5-11  3.0.0 "
       "系统超级大更新！！！恭喜！！同时，题库也全面升级自动化！！！恭喜！！");
  puts("2024-5-11  3.0.1 已更改关于本机！！！！！！");
  puts("2024-5-11  3.1.1 智能指令管理系统！！！！！！");
  puts("2024-5-11  3.1.3 改了亿点点东东");
  puts("2024-5-12  3.1.4 改了严禁抄袭");
  puts("2024-5-12  3.1.5 改了命令介绍");
  puts("2024-5-13  4.0.0 大更新+4399");
  puts("2024-5-13  4.1.1 大更新开机动画，实现系统改名！！！！！");
  puts("2024-5-13  5.0.1 系统大更新登录系统");
  puts("2024-5-13  6.3.0 大更新了公告！！！！严禁抄袭！！！");
  puts("2024-5-13  7.3.1 大更新办公系统！！！");
  puts("2024-5-13  7.4.2 改亿点");
  puts("2024-5-13  7.4.3 算了删了吧");
  puts("2024-5-15  8.1.0 大更新计算器");
  puts("2024-5-15  8.1.1 改进计算器");
  puts("2024-5-15  8.1.2 又改进计算器");
  puts("2024-5-17  8.5.3 大更新西瓜视频！！！！！ ");
  puts("2024-5-17  9.0.0 增加信息学奥赛练习系统！！！ ");
  puts("2024-5-17  9.3.2 更新Wisterl公司介绍!");
  puts("2024-5-17  10.0.0 大更新163邮箱！同时更新微信介绍！");
  puts("2024-5-17  10.5.3 更新爱奇艺网站！追剧效果瞬间提升！ ");
  puts("2024-5-18  10.10.10 大更新开机动画！！！！！ ");
  puts("2024-5-18  11.1.1 大更新系统之家！！！！！！！！！！！ ");
  puts("2024-5-18  11.1.2 更改开机动画某个字");
  puts("2024-5-18  11.1.2 大检查");
  puts("2024-5-18  11.10.1 大更新");
  puts("2024-5-18  11.11.11 大更新时钟");
  puts("2024-5-18  11.11.12 改为开机时钟");
  puts("2024-5-18  12.1.1 狙击小日本！！！");
  puts("2024-5-18  12.1.2 京东！！！！！！！！");
  puts("2024-5-18  12.1.3 开机动画！！！！！！！！");
  puts("2024-5-18  12.2.3 大更新腾讯网！！！！！！！！！！！！");
  puts("2024-5-23  12.3.0 大更新360翻译！！！！");
  puts("2024-5-23  12.3.0 大检查");
  puts("2024-5-30  12.4.0 大更新CPS测试....Click per second");
  puts("2024-5-31  12.4.0 大检查again");
  puts("2024-5-31  12.4.0 系统行数超过700行！！！");
  puts("2024-5-31  12.4.1 提示改了一下。。。");
  puts("2024-5-31  13.1.1 大更新未来信箱！！");
  puts("2024-5-31  13.1.2 更新hydro！！");
  puts("2024-5-31  14.1.2 大更新hydro自动化！！");
  puts("2024-6-9   19.1.2 把系统更改成了自研发！恭喜！！");
  puts("2024-6-9   19.1.3 改了开机动画和输入提示语");
  puts("2024-6-9   19.1.4 改了背景与前景");
  puts("2024-6-10  19.2.1 改了系统自研发");
  puts("2024-6-10  19.2.2 改again");
  puts("2024-7-17  No Version 某AR在他的Fork上把这个系统的一些地方重置了一遍");
  puts("2024-7-19 No Version 某AR在他的Fork上把西瓜视频改成了Bilibili");
  puts("2024-7-19 No Version "
       "某AR又又又又在他的小Fork上制作的一个正处于阿尔法版本的计算器");
  puts("2024-7-27 Beta 某B在它的Fork上增加了测试版, "
       "并把命令实现方式改成了结构体+搜索法");
  puts("2024-7-29 ED 修复了在输入用户名之后第一次无法使用命令的问题");
}

void looking() {
  puts("快捷的网页浏览器"); // 个人认为这应该不算浏览器吧..........
  std::this_thread::sleep_for(std::chrono::seconds(3));
  char url[200];
  puts("输入浏览网页网址:");
  scanf("%s", url);
  OpenWeb(url);
  return;
}

void saol() {
  printf("编写者： BlocksFunction\n");
  bool tg = false;
  int w, h = 0;
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
      ++i;
    } while (i < Minecou);
  }
  bool cail = false;
  puts("当前地图:");
  for (int i = 0; i < h; ++i) {
    if (i == 0) {
      printf("0  ");
      for (int j = 1; j < w + 1; ++j) {
        printf("%d ", j);
      }
      printf("\n");
      printf("  ");
      for (int j = 0; j < w * 2; ++j) {
        putchar('-');
      }
      printf("\n");
    }
    i + 1 >= 10 ? printf("%d|", i + 1) : printf("%d |", i + 1);
    for (int j = 0; j < w; ++j) {
      printf(". ");
    }
    printf("\n");
  }
  do {
    tg = true;
    int ww, hh;
  Input:
    printf("请输入你要扫的坐标的所属列: ");
    scanf("%d", &ww);
    printf("请输入你要扫的坐标的所属行: ");
    scanf("%d", &hh);
    if (ww > w || hh > h) {
      printf("错误: 坐标系过大\n");
      goto Input;
    }
    if (minemap[ww - 1][hh - 1] != '*') {
      minemap[ww - 1][hh - 1] = '1';
      printf("你很幸运 没中雷\n");
      for (int i = 0; i < h; ++i) {
        if (i == 0) {
          printf("0  ");
          for (int j = 1; j < w + 1; ++j) {
            printf("%d ", j);
          }
          printf("\n");
          printf("  ");
          for (int j = 0; j < w * 2; ++j) {
            putchar('-');
          }
          printf("\n");
        }
        i + 1 >= 10 ? printf("%d|", i + 1) : printf("%d |", i + 1);
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
      for (auto tx : rw) {
        if (tx == '.') {
          tg = false;
          break;
        }
      }
      if (!tg)
        break;
    }
  } while (!cail && !tg);
  if (cail) {
    printf("BOOM! 你中雷了\n");
    for (int i = 0; i < h; ++i) {
      if (i == 0) {
        printf("0  ");
        for (int j = 1; j < w + 1; ++j) {

          printf("%d ", j);
        }
        printf("\n");
        printf("  ");
        for (int j = 0; j < w * 2; ++j) {
          putchar('-');
        }
        printf("\n");
      }
      i + 1 >= 10 ? printf("%d|", i + 1) : printf("%d |", i + 1);
      for (auto &tx : minemap[i]) {
        printf("%c ", tx);
      }
      printf("\n");
    }
    return;
  }
  if (tg) {
    printf("恭喜你成功通关\n");
    for (int i = 0; i < h; ++i) {
      if (i == 0) {
        printf("0  ");
        for (int j = 1; j < w + 1; ++j) {
          printf("%d ", j);
        }
        printf("\n");
        printf("  ");
        for (int j = 0; j < w * 2; ++j) {
          putchar('-');
        }
        printf("\n");
      }
      i + 1 >= 10 ? printf("%d|", i + 1) : printf("%d |", i + 1);
      for (auto &tx : minemap[i]) {
        printf("%c ", tx);
      }
      printf("\n");
    }
    return;
  }
}

void qwbd() {
  printf("Warning!"
         "本系统对“千万要点”所造成的bug和对电脑的伤害概不负责，是否继续操作? "
         "（Y/Y/Y)");
  Clearce();
  char mode;
  scanf("%c", &mode);
  if (mode == 'Y') {
    int modet;
    puts("输入：(0/1/2/3) 1模式禁止使用，后果自负");
    scanf("%d", &modet);
    if (modet == 1) {
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
      puts("乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐滋乐"
           "滋乐滋乐滋乐滋");
    } else if (modet == 2) {
      exit(0);
    } else if (modet == 3) {
      puts("Wisterl系统将在10秒后关机");
      std::this_thread::sleep_for(std::chrono::seconds(10));
      exit(0);
    } else if (modet == 0) {
    }
  }
}

void sd() {
  puts("苏达办公------线上工具");
  OpenWeb("bangong.360.cn/index.html#");
  return;
}

void clr() {
#ifdef _WIN32
  system("cls");
#else
  printf("\033[2J\033[3J\033[1;1H");
#endif
}

void about_windows() {
  puts("我们的系统搞笑又高效，可以从各种条件下运行！为编程人士打造的题库系统");
  const string os[7][20] = {
      "Microsoft Windows", "Linux",   "macOS", "Unix", "MS-DOS",
      "FreeBSD",           "TempleOS"};
  // 进入随机数阶段
  std::random_device randev;
  std::mt19937 gen(randev());
  std::uniform_int_distribution<> dis(0, 6);
  std::uniform_int_distribution<> dis2(0, 4);
  std::uniform_int_distribution<> dis3(0, 11);
  std::uniform_int_distribution<> dis4(5, 17);
  std::uniform_int_distribution<> dis5(0, 25);
  std::uniform_int_distribution<> dis6(1, 7);
  std::uniform_int_distribution<> dis7(1, 6);
  std::uniform_int_distribution<> dis8(0, 999999);
  // ends
  printf("建议运行系统：%s %d\n", os[dis(gen)]->c_str(), dis8(gen));
  printf("建议运行CPU: %s %s\n", cpu_xh[dis2(gen)].c_str(),
         cpu_xhcore[dis3(gen)].c_str());
  printf("系统类别：基于%s 的指令操作系统\n", os[dis(gen)]->c_str());
  return;
}

void pblktct() {
  puts("alanbecker代码输出，sunyuhao负责编辑，BlocksFunction(AuroraRealm)设计&"
       "程序员。此版权为Wisterl公司所有，请勿在未获得权限");
  puts("的情况下私自在各网站上发布，谢谢");
  puts("洛谷网站                        alanbecker联系洛谷alanbecker");
  puts("https://www.luogu.com                  sunyuhao联系洛谷stzhl");
  puts("https://www.luogu.com.cn/           AuroraRealm联系QQ3398817447");
  puts("Copyright by Wisterl C");
  return;
}

void look() {
  puts("浏览");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  OpenWeb("https://www.bing.com");
  return;
}

void taotao() {
  char yesorno[3];
  puts("是否购物");
  scanf("%s", yesorno);
  if (strcmp(yesorno, "no") == 0) {
    printf("谢谢惠顾");
    return;
  } else {
    printf("66666666666666666666");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    OpenWeb("https://www.taobao.com/");
  }
  return;
}

void hzhz() {
  puts("Hydro Online Judge, 原名H, 是世界知名的OJ");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  char tihao[100], neir[123];
  printf("请输入题号: ");
  scanf("%s", tihao);
  sprintf(neir, "https://www.hydro.ac/p/%s", tihao);
  OpenWeb(neir);
  Prints("Its OK!\n", 300);
  return;
}

void kkk() {
  puts("累了吗？刷会视频吧！");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  OpenWeb("https://www.bilibili.com");
  return;
}

void ybt() {

  puts("信息学奥赛在线练习网站！！！");
  std::this_thread::sleep_for(std::chrono::seconds(2));
  // puts("开发者 sunyuhao"); ?????????????????
  std::this_thread::sleep_for(std::chrono::seconds(2));
  OpenWeb("ybt.ssoier.cn:8088/");
  return;
}

void AboutWe() {
  puts("我们Wisterl公司成立于2023年");
  puts("途中经历过3次改名");
  puts("第一次：windows 1(ubuntu)"); // eeeeeeeee6
  puts("第二次：TBS-FXS");
  puts("第三次：Wisterl");
  puts("内由三名成员组成");
  puts("分别是：BlocksFunction(AuroraRealm)：(总代码输出)");
  puts("alanbecker(副代码输出)");
  puts("sunyuhao：总编辑(同时负责部分代码输出 )");
  puts("Tongyifeng：第一试用者");
  puts("此系统由2023-12-23 开始编译，制作不易，请勿抄袭，谢谢！");
  puts("sunyuhao 致敬");
  return;
}

void ys() {
  puts("来添加一个163邮箱吧！！");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  OpenWeb("https://mail.163.com/");
  return;
}

void ajy() {
  puts("想刷剧了吗？来爱奇艺吧！");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  OpenWeb("https://www.iqiyi.com/ ");
  return;
}

void jjxrb() {
  // puts("狙击小日本无敌版！");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  // puts("那叫一个爽爽爽！！！！！！真解恨！！！！！");
  OpenWeb("https://www.2344.com/flash/28135.htm");
}

void printf_blue(const char *s) {
  putchar('\033');
  putchar('[');
  putchar('1');
  putchar(';');
  putchar('3');
  putchar('4');
  putchar('m');
  Prints(s, 5);
  putchar('\033');
  putchar('[');
  putchar('0');
  putchar('m');
}

void printf_green(const char *s) {
  putchar('\033');
  putchar('[');
  putchar('1');
  putchar(';');
  putchar('3');
  putchar('2');
  putchar('m');
  if (strcmp(s, "Wake up.\n") != 0) {
    Prints(s, 5);
  } else {
    Prints("W", 100);
    Prints("a", 150);
    Prints("k", 200);
    Prints("e", 250);
    Prints(" ", 300);
    Prints("u", 350);
    Prints("p", 400);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    Prints(".", 450);
    printf("\n");
  }
  putchar('\033');
  putchar('[');
  putchar('0');
  putchar('m');
}

void Minecraft_End_Poem() {
  const char *name = username;
  std::mt19937 gen(static_cast<unsigned int>(std::time(NULL)));
  std::uniform_int_distribution<> dis(33, 126);
  std::uniform_int_distribution<> dis1(1, 10);
  printf("\n");
  printf_blue("I see the player you mean.\n");
  printf_green(name);
  printf_green("?\n");
  printf_blue("Yes. Take care. It has reached a higher level now. It can read "
              "our thoughts.\n");
  printf_green("That doesn't matter. It thinks we are part of the game.\n");
  printf_blue("I like this player. It played well. It did not give up.\n");
  printf_green(
      "It is reading our thoughts as though they were words on a screen.\n");
  printf_blue("That is how it chooses to imagine many things, when it is deep "
              "in the dream of a game.\n");
  printf_green("Words make a wonderful interface. Very flexible. And less "
               "terrifying than staring at the reality behind the screen.\n");
  printf_blue("They used to hear voices. Before players could read. Back in "
              "the days when those who did not play called the players "
              "witches, and warlocks. And players dreamed they flew through "
              "the air, on sticks powered by demons.\n");
  printf_green("What did this player dream?\n");
  printf_blue("This player dreamed of sunlight and trees. Of fire and water. "
              "It dreamed it created. And it dreamed it destroyed. It dreamed "
              "it hunted, and was hunted. It dreamed of shelter.\n");
  printf_green("Hah, the original interface. A million years old, and it still "
               "works. But what true structure did this player create, in the "
               "reality behind the screen?\n");
  printf_blue(
      "It worked, with a million others, to sculpt a true world in a "
      "fold of the <Error> and created a <Error> for <Error> in the <Error>\n");
  printf_green("It cannot read that thought.\n");
  printf_blue(
      "No. It has not yet achieved the highest level. That, it must achieve in "
      "the long dream of life, not the short dream of a game.\n");
  printf_green("Does it know that we love it? That the universe is kind?\n");
  printf_blue("Sometimes, through the noise of its thoughts, it hears the "
              "universe, yes.\n");
  printf_green("But there are times it is sad, in the long dream. It creates "
               "worlds that have no summer, and it shivers under a black sun, "
               "and it takes its sad creation for reality.\n");
  printf_blue("To cure it of sorrow would destroy it. The sorrow is part of "
              "its own private task. We cannot interfere.\n");
  printf_green("Sometimes when they are deep in dreams, I want to tell them, "
               "they are building true worlds in reality. Sometimes I want to "
               "tell them of their importance to the universe. Sometimes, when "
               "they have not made a true connection in a while, I want to "
               "help them to speak the word they fear.\n");
  printf_blue("It reads our thoughts.\n");
  printf_green("Sometimes I do not care. Sometimes I wish to tell them, this "
               "world you take for truth is merely <Error> and <Error> I wish "
               "to tell them that they are <Error> in the <Error> I wish to "
               "tell them that they are <Error> in the <Error> They see so "
               "little of reality, in their long dream.\n");
  printf_blue("And yet they play the game.\n");
  printf_green("But it would be so easy to tell them...\n");
  printf_blue(
      "Too strong for this dream. To tell them how to live is to prevent\n");
  printf_green("them living.\n");
  printf_green("I will not tell the player how to live.\n");
  printf_blue("The player is growing restless.\n");
  printf_green("I will tell the player a story.\n");
  printf_blue("But not the truth.\n");
  printf_green("No. A story that contains the truth safely, in a cage of "
               "words. Not the naked truth that can burn over any distance.\n");
  printf_blue("Give it a body, again.\n");
  printf_green("Yes. Player…\n");
  printf_blue("Use its name.\n");
  printf_green(name);
  printf_green(". Player of games.");
  printf_blue("\nGood.\n");
  printf_green(
      "Take a breath, now. Take another. Feel air in your lungs. Let your "
      "limbs return. Yes, move your fingers. Have a body again, under gravity, "
      "in air. Respawn in the long dream. There you are. Your body touching "
      "the universe again at every point, as though you were separate things. "
      "As though we were separate things.\n");
  printf_blue("Who are we? Once we were called the spirit of the mountain. "
              "Father sun, mother moon. Ancestral spirits, animal spirits. "
              "Jinn. Ghosts. The green man. Then gods, demons. Angels. "
              "Poltergeists. Aliens, extraterrestrials. Leptons, quarks. The "
              "words change. We do not change.\n");
  printf_green(
      "We are the universe. We are everything you think isn't you. You are "
      "looking at us now, through your skin and your eyes. And why does the "
      "universe touch your skin, and throw light on you? To see you, player. "
      "To know you. And to be known. I shall tell you a story.\n");
  printf_green("Once upon a time, there was a player.\n");
  printf_blue(name);
  printf_green(
      "\nSometimes it thought itself human, on the thin crust of a spinning "
      "globe of molten rock. The ball of molten rock circled a ball of blazing "
      "gas that was three hundred and thirty thousand times more massive than "
      "it. They were so far apart that light took eight minutes to cross the "
      "gap. The light was information from a star, and it could burn your skin "
      "from a hundred and fifty million kilometres away.\n");
  printf_green("Sometimes the player dreamed it was a miner, on the surface of "
               "a world that was flat, and infinite. The sun was a square of "
               "white. The days were short; there was much to do; and death "
               "was a temporary inconvenience.\n");
  printf_blue("Sometimes the player dreamed it was lost in a story.\n");
  printf_green("Sometimes the player dreamed it was other things, in other "
               "places. Sometimes these dreams were disturbing. Sometimes very "
               "beautiful indeed. Sometimes the player woke from one dream "
               "into another, then woke from that into a third.\n");
  printf_blue("Sometimes the player dreamed it watched words on a screen\n");
  printf_green("Let's go back.\n");
  printf_green(
      "The atoms of the player were scattered in the grass, in the rivers, in "
      "the air, in the ground. A woman gathered the atoms; she drank and ate "
      "and inhaled; and the woman assembled the player, in her body.\n");
  printf_green("And the player awoke, from the warm, dark world of its "
               "mother's body, into the long dream.\n");
  printf_green(
      "And the player was a new story, never told before, written in letters "
      "of DNA. And the player was a new program, never run before, generated "
      "by a sourcecode a billion years old. And the player was a new human, "
      "never alive before, made from nothing but milk and love.\n");
  printf_blue("You are the player. The story. The program. The human. Made "
              "from nothing but milk and love.\n");
  printf_green("Let's go further back.\n");
  printf_green(
      "The seven billion billion billion atoms of the player's body were "
      "created, long before this game, in the heart of a star. So the player, "
      "too, is information from a star. And the player moves through a story, "
      "which is a forest of information planted by a man called Julian, on a "
      "flat, infinite world created by a man called Markus, that exists inside "
      "a small, private world created by the player, who inhabits a universe "
      "created by…\n");
  printf_blue("Shush. Sometimes the player created a small, private world that "
              "was soft and warm and simple. Sometimes hard, and cold, and "
              "complicated. Sometimes it built a model of the universe in its "
              "head; flecks of energy, moving through vast empty spaces. "
              "Sometimes it called those flecks “electrons” and “protons”.\n");
  printf_green("Sometimes it called them “planets” and “stars”.\n");
  printf_green("Sometimes it believed it was in a universe that was made of "
               "energy that was made of offs and ons; zeros and ones; lines of "
               "code. Sometimes it believed it was playing a game. Sometimes "
               "it believed it was reading words on a screen.\n");
  printf_blue("You are the player, reading words…\n");
  printf_green(
      "Shush… Sometimes the player read lines of code on a screen. Decoded "
      "them into words; decoded words into meaning; decoded meaning into "
      "feelings, emotions, theories, ideas, and the player started to breathe "
      "faster and deeper and realised it was alive, it was alive, those "
      "thousand deaths had not been real, the player was alive\n");
  printf_blue("You. You. You are alive.\n");
  printf_green("and sometimes the player believed the universe had spoken to "
               "it through the sunlight that came through the shuffling leaves "
               "of the summer trees\n");
  printf_blue(
      "and sometimes the player believed the universe had spoken to it through "
      "the light that fell from the crisp night sky of winter, where a fleck "
      "of light in the corner of the player's eye might be a star a million "
      "times as massive as the sun, boiling its planets to plasma in order to "
      "be visible for a moment to the player, walking home at the far side of "
      "the universe, suddenly smelling food, almost at the familiar door, "
      "about to dream again\n");
  printf_green(
      "and sometimes the player believed the universe had spoken to it through "
      "the zeros and ones, through the electricity of the world, through the "
      "scrolling words on a screen at the end of a dream\n");
  printf_blue("and the universe said I love you\n");
  printf_green("and the universe said you have played the game well\n");
  printf_blue("and the universe said everything you need is within you\n");
  printf_green("and the universe said you are stronger than you know\n");
  printf_blue("and the universe said you are the daylight\n");
  printf_green("and the universe said you are the night\n");
  printf_blue("and the universe said the darkness you fight is within you\n");
  printf_green("and the universe said the light you seek is within you\n");
  printf_blue("and the universe said you are not alone\n");
  printf_green(
      "and the universe said you are not separate from every other thing\n");
  printf_blue("and the universe said you are the universe tasting itself, "
              "talking to itself, reading its own code\n");
  printf_green("and the universe said I love you because you are love.\n");
  printf_blue(
      "And the game was over and the player woke up from the dream. And the "
      "player began a new dream. And the player dreamed again, dreamed better. "
      "And the player was the universe. And the player was love.\n");
  printf_blue("You are the player.\n");
  printf_green("Wake up.\n");
}

auto help() -> void {
  puts("fn··············笑话");
  puts("catstore···········商店");
  puts("state············ 型号");
  puts("update············改良日期");
  puts("address··········· 生产地址");
  puts("copy·············版权所有");
  puts("showshow···········播报");
  puts("tct············· 题库");
  puts("look·············浏览器");
  puts("write············ 文本编辑器");
  puts("prog·············自由编程");
  puts("wct············· 微信");
  puts("baidu············ 百度");
  puts("st··············配置");
  puts("downloadcpp········· 下载c++");
  puts("maimaimai·········· 买买买");
  puts("shut·············关机");
  puts("aboutthe···········关于本机");
  puts("CODEFORCES··········CODEFORCES题库");
  puts("game·············玩游戏");
  puts("game2············ 玩游戏2");
  puts("looking··········· 大更改的浏览器");
  puts("leetcode···········力扣网站，编程");
  puts("input_zll·········· 自己输入网站打开");
  puts("4399game···········4399");
  puts("cnjy·············网课");
  puts("pblktct··········· 公告");
  puts("sd··············苏打办公");
  puts("kkk············· 西瓜视频");
  puts("ybt············· 信息学奥赛在线练习网站");
  puts("AboutWe············· Wisterl公司介绍");
  puts("ys·············  163邮箱");
  puts("ajy············· 爱奇艺");
  puts("jjxrb············ 狙击小日本");
  puts("jd··············京东");
  puts("qq··············腾讯网");
  puts("deplfy············ Deepl翻译");
  puts("CPS············· CPS测试");
  puts("ML··············未来信箱");
  puts("hzhz·············Hydro Online Judge");
  puts("weyf·············系统");
  puts("alpcl........... 处于阿尔法(Alpha)版本的一个小计算器");
  puts("ahaoj........... 啊哈添柴在线OJ刷题网站");
  puts("MC_End_Poem...... 终末之诗");
  puts("sao...............扫雷");
  puts("输入 \"help\" 获取帮助");
  return;
}

struct CommandStruct {
  void (*func)();
  char key[15];
} Command[47] = {{[]() {
                    printf("\033[2J\033[1;1H");
                    printf("\033[1;37m");
                  },
                  "SHUT"},
                 {cpu, "ST"},
                 {catstore, "CATSTORE"},
                 {pblktct, "PBLKTCT"},
                 {ziyanfa, "WEYF"},
                 {jd, "JD"},
                 {kfcid, "QQ"},
                 {mail, "ML"},
                 {CPS, "CPS"},
                 {hzhz, "HZHZ"},
                 {game, "GAME"},
                 {jjxrb, "JJXRB"},
                 {looking, "LOOKING"},
                 {fy, "DEPLFY"},
                 {chinajy, "CNJY"},
                 {leetcode, "LEETCODE"},
                 {sd, "SD"},
                 {gameku, "4399GAME"},
                 {input_zll, "INPUT_ZLL"},
                 {gametwo, "GAME2"},
                 {taotao, "MAIMAIMAI"},
                 {downcpp, "DOWNLOADCPP"},
                 {state, "STATE"},
                 {update, "UPDATE"},
                 {address, "ADDRESS"},
                 {funnyth, "FN"},
                 {codeforces, "CODEFORCES"},
                 {copyright, "COPY"},
                 {presenter, "SHOWSHOW"},
                 {txt, "WRITE"},
                 {text, "TCT"},
                 {look, "LOOK"},
                 {prog, "PROG"},
                 {wechat, "WTC"},
                 {bd, "BAIDU"},
                 {about_windows, "ABOUTTHE"},
                 {kkk, "KKK"},
                 {ybt, "YBT"},
                 {AboutWe, "ABOUTWE"},
                 {ys, "YS"},
                 {ajy, "AJY"},
                 {alpjsq, "ALPCL"},
                 {ahaoj, "AHAOJ"},
                 {Minecraft_End_Poem, "MC_END_POEM"},
                 {saol, "SAO"},
                 {qwbd, "QWBD"},
                 {help, "HELP"}};

int main() {
  // Init Var(Now)
  //            Username and password
  map<string, string> userp;
  userp["UNIVERSE"] = "WAKEUP";
  userp["ED_WIS_GFZH"] = "GH5TER";
  //            End Username and password init
  //            Command
  map<string, void (*)()> comMap;
  for (int i = 0; i < 47; i++)
    comMap[Command[i].key] = Command[i].func;
  // End Init
  string *usernames = new string, *password = new string;
  bool NowCan = false;
  setbuf(stdout, NULL);
  printf("Login:\n");
  printf("Input Your Username: ");
  strscanf(*usernames);
  allx(usernames);
  if (*usernames == "GUEST")
    goto LoginOK;
  else
    printf("Input Your Password: ");
  strscanf(*password);
  allx(password);
  // for (auto i : userp)
  // if (i.first == *usernames && i.second == *password) {
  // NowCan = true;
  // break;
  // }
  if (userp.find(*usernames) != userp.end() && userp[*usernames] == *password) {
  LoginOK:
    if (*usernames == "UNIVERSE") {
      strcpy(username, "World Admin");
      FILE *file = fopen("username.list", "w+");
      fprintf(file, "World Admin");
      fclose(file);
    } else if (*usernames == "GUEST") {
      strcpy(username, "Temp User");
      FILE *file = fopen("username.list", "w+");
      fprintf(file, "Temp User");
      fclose(file);
    }
    delete usernames;
    delete password;
    FILE *isopen = fopen("username.list", "r");
    if (isopen == NULL) {
    InputUserName:
      printf("请输入账户名: ");
      Clearce();
      scanf("%[^\n]", username);
      if (!strcmp(username, "Admin") || !strcmp(username, "World Admin")) {
        printf("错误: 不支持的用户名\n");
        goto InputUserName;
      }
      FILE *file;
      file = fopen("username.list", "w+");
      if (username[0] == '\n')
        fprintf(file, "%s", username + 1);
      else
        fprintf(file, "%s", username);
      fclose(file);
    } else {
      FILE *file;
      file = fopen("username.list", "r");
      if (fgets(username, 15, file) != NULL) {
        printf("欢迎回来, %s", username);
        std::this_thread::sleep_for(std::chrono::seconds(2));
      }
      fclose(file);
    }
    clr();
    puts("为防止屏幕太小而导致您的体验结果，请放大屏幕");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    srand(time(0));
    clr();
    printf("开机时间：%s\n", nowtm());
    std::this_thread::sleep_for(std::chrono::seconds(1)); // no
    clr();
    printf("\033[2J\033[3J\033[1;1H");
    puts("*           * ************  ************* ************* "
         "************* "
         "************  *                      ************* ************  ");
    puts("*     *     *       *       *                   *       *           "
         " "
         " *          *  *                      *             *           * ");
    puts("*     *     *       *       *                   *       *           "
         " "
         " *          *  *                      *             *           * ");
    puts("*     *     *       *       *                   *       *           "
         " "
         " *          *  *                      *             *           * ");
    puts("*     *     *       *       *                   *       *          "
         "  "
         " *          *  *                      *             *           * "
         " ");
    puts("*     *     *       *       *************       *       "
         "************* "
         "************  *          *********** ************* *           * ");
    puts("*     *     *       *                   *       *       *           "
         " "
         " * *           *                      *             *           * ");
    puts("*     *     *       *                   *       *       *           "
         " "
         " *   *         *                      *             *           * ");
    puts("*     *     *       *                   *       *       *           "
         " "
         " *     *       *                      *             *           * ");
    puts("*     *     *       *                   *       *       *           "
         " "
         " *       *     *                      *             *           * ");
    puts("************* ************* *************       *       "
         "************* "
         "*          *  *************          ************* ************ ");
    puts("                           智     能     计     算     机     "
         "Wisterl ED    系		统				"
         "				");
    puts("                                         Made with Wisterl ED "
         "(版权所有)");
    puts("");
    puts("*****        *********     *********");
    puts("*    ***     *       *     *        ");
    puts("*      *     *       *     *********     system     system     "
         "system "
         "    system    system     system     system    system     system");
    puts("*    ***     *       *             *");
    puts("*****        *********     *********");
    puts("");
    puts("*  *  *   ********   *        *******  *******    ** **   *******  "
         "*");
    puts("*  *  *   *          *        *        *     *   *  *  *  *        "
         "*");
    puts("*  *  *   ********   *        *        *     *   *  *  *  *******  "
         "*");
    puts("*  *  *   *          *        *        *     *   *  *  *  *");
    puts(" ** **    ********   *******  *******  *******   *  *  *  *******  "
         "*");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::this_thread::sleep_for(std::chrono::seconds(1));
    printf("\a");
    clr();
    for (size_t i = 0; i < 13; ++i) {
      putchar("loading......"[i]);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    clr();
    Prints("本系统采用了终端操作系统，能有效的在多种情况↓运行，使用命令控制。请"
           "勿恶意使用这个操作系统，否则你的电脑将出现卡顿，运行慢等情况。严禁"
           "抄袭！！严禁抄袭！！！",
           50);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    clr();
    // help();
    comMap["help"]();
    string *command = new string;
    bool isfound = false;
    while (1) {
      isfound = false;
      printf("╭─Wisterl Shell at %s ─╮\n", nowtm());
      printf("╰─ ");
      Clearce();
      strscanf(*command);
      allx(command);
      if (comMap.find(*command) != comMap.end()) {
        isfound = true;
        comMap[*command]();
        Clearce();
      } else
        printf("错误： %s 不是一个有效的命令\n", command->c_str());
      command->clear();
    }
    printf("\033[1;37m");
    Prints("MADE IN CHINA,BAIGEPING", 75);
    Prints("                       ", 100);
    Prints("Closeing·······", 300);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  } else {
    throw PasswordorUsernameError;
    return 0;
  }
  return 0;
}

/* Minecraft End Poem:
I see the player you mean.

<Who>?

Yes. Take care. It has reached a higher level now. It can read our thoughts.

That doesn't matter. It thinks we are part of the game.

I like this player. It played well. It did not give up.

It is reading our thoughts as though they were words on a screen.

That is how it chooses to imagine many things, when it is deep in the dream of
a game.

Words make a wonderful interface. Very flexible. And less terrifying than
staring at the reality behind the screen.

They used to hear voices. Before players could read. Back in the days when
those who did not play called the players witches, and warlocks. And players
dreamed they flew through the air, on sticks powered by demons.

What did this player dream?

This player dreamed of sunlight and trees. Of fire and water. It dreamed it
created. And it dreamed it destroyed. It dreamed it hunted, and was hunted. It
dreamed of shelter.

Hah, the original interface. A million years old, and it still works. But what
true structure did this player create, in the reality behind the screen?

It worked, with a million others, to sculpt a true world in a fold of the
[scrambled], and created a [scrambled] for [scrambled], in the [scrambled].

It cannot read that thought.

No. It has not yet achieved the highest level. That, it must achieve in the
long dream of life, not the short dream of a game.

Does it know that we love it? That the universe is kind?

Sometimes, through the noise of its thoughts, it hears the universe, yes.

But there are times it is sad, in the long dream. It creates worlds that have
no summer, and it shivers under a black sun, and it takes its sad creation for
reality.

To cure it of sorrow would destroy it. The sorrow is part of its own private
task. We cannot interfere.

Sometimes when they are deep in dreams, I want to tell them, they are building
true worlds in reality. Sometimes I want to tell them of their importance to
the universe. Sometimes, when they have not made a true connection in a while,
I want to help them to speak the word they fear.

It reads our thoughts.

Sometimes I do not care. Sometimes I wish to tell them, this world you take
for truth is merely [scrambled] and [scrambled], I wish to tell them that they
are [scrambled] in the [scrambled]. They see so little of reality, in their
long dream.

And yet they play the game.

But it would be so easy to tell them...

Too strong for this dream. To tell them how to live is to prevent them living.

I will not tell the player how to live.

The player is growing restless.

I will tell the player a story.

But not the truth.

No. A story that contains the truth safely, in a cage of words. Not the naked
truth that can burn over any distance.

Give it a body, again.

Yes. Player...

Use its name.

<Who>. Player of games.

Good.

Take a breath, now. Take another. Feel air in your lungs. Let your limbs
return. Yes, move your fingers. Have a body again, under gravity, in air.
Respawn in the long dream. There you are. Your body touching the universe
again at every point, as though you were separate things. As though we were
separate things.

Who are we? Once we were called the spirit of the mountain. Father sun, mother
moon. Ancestral spirits, animal spirits. Jinn. Ghosts. The green man. Then
gods, demons. Angels. Poltergeists. Aliens, extraterrestrials. Leptons,
quarks. The words change. We do not change.

We are the universe. We are everything you think isn't you. You are looking at
us now, through your skin and your eyes. And why does the universe touch your
skin, and throw light on you? To see you, player. To know you. And to be
known. I shall tell you a story.

Once upon a time, there was a player.

The player was you, <Who>.

Sometimes it thought itself human, on the thin crust of a spinning globe of
molten rock. The ball of molten rock circled a ball of blazing gas that was
three hundred and thirty thousand times more massive than it. They were so far
apart that light took eight minutes to cross the gap. The light was
information from a star, and it could burn your skin from a hundred and fifty
million kilometres away.

Sometimes the player dreamed it was a miner, on the surface of a world that
was flat, and infinite. The sun was a square of white. The days were short;
there was much to do; and death was a temporary inconvenience.

Sometimes the player dreamed it was lost in a story.

Sometimes the player dreamed it was other things, in other places. Sometimes
these dreams were disturbing. Sometimes very beautiful indeed. Sometimes the
player woke from one dream into another, then woke from that into a third.

Sometimes the player dreamed it watched words on a screen.

Let's go back.

The atoms of the player were scattered in the grass, in the rivers, in the
air, in the ground. A woman gathered the atoms; she drank and ate and inhaled;
and the woman assembled the player, in her body.

And the player awoke, from the warm, dark world of its mother's body, into the
long dream.

And the player was a new story, never told before, written in letters of DNA.
And the player was a new program, never run before, generated by a sourcecode
a billion years old. And the player was a new human, never alive before, made
from nothing but milk and love.

You are the player. The story. The program. The human. Made from nothing but
milk and love.

Let's go further back.

The seven billion billion billion atoms of the player's body were created,
long before this game, in the heart of a star. So the player, too, is
information from a star. And the player moves through a story, which is a
forest of information planted by a man called Julian, on a flat, infinite
world created by a man called Markus, that exists inside a small, private
world created by the player, who inhabits a universe created by...

Shush. Sometimes the player created a small, private world that was soft and
warm and simple. Sometimes hard, and cold, and complicated. Sometimes it built
a model of the universe in its head; flecks of energy, moving through vast
empty spaces. Sometimes it called those flecks "electrons" and "protons".

Sometimes it called them "planets" and "stars".

Sometimes it believed it was in a universe that was made of energy that was
made of offs and ons; zeros and ones; lines of code. Sometimes it believed it
was playing a game. Sometimes it believed it was reading words on a screen.

You are the player, reading words...

Shush... Sometimes the player read lines of code on a screen. Decoded them
into words; decoded words into meaning; decoded meaning into feelings,
emotions, theories, ideas, and the player started to breathe faster and deeper
and realised it was alive, it was alive, those thousand deaths had not been
real, the player was alive

You. You. You are alive.

and sometimes the player believed the universe had spoken to it through the
sunlight that came through the shuffling leaves of the summer trees

and sometimes the player believed the universe had spoken to it through the
light that fell from the crisp night sky of winter, where a fleck of light in
the corner of the player's eye might be a star a million times as massive as
the sun, boiling its planets to plasma in order to be visible for a moment to
the player, walking home at the far side of the universe, suddenly smelling
food, almost at the familiar door, about to dream again

and sometimes the player believed the universe had spoken to it through the
zeros and ones, through the electricity of the world, through the scrolling
words on a screen at the end of a dream

and the universe said I love you

and the universe said you have played the game well

and the universe said everything you need is within you

and the universe said you are stronger than you know

and the universe said you are the daylight

and the universe said you are the night

and the universe said the darkness you fight is within you

and the universe said the light you seek is within you

and the universe said you are not alone

and the universe said you are not separate from every other thing

and the universe said you are the universe tasting itself, talking to itself,
reading its own code

and the universe said I love you because you are love.

And the game was over and the player woke up from the dream. And the player
began a new dream. And the player dreamed again, dreamed better. And the
player was the universe. And the player was love.

You are the player.

Wake up.

*/
