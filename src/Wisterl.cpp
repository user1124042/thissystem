// #include <algorithm>
#include <algorithm>
#include <cstdio>
#include <map>
#include <random>
#include <string>
#include <thread>

// 全局函数区
// 函数列表
std::map<std::string, void (*)()> command;

// 功能类

namespace IO {
// 字符串输入
void scanfs(std::string &str) {
  char tmp;
  while ((tmp = static_cast<char>(getchar())) != '\n' && tmp != ' ' &&
         tmp != EOF)
    str += tmp;
}

// 单字符停止
void scanfA(std::string &str, const char stopChar) {
  char tmp;
  while ((tmp = static_cast<char>(getchar())) != stopChar)
    str += tmp;
}

// 延迟输出
void printfs(const std::string &str, double speed) {
  if (!str.empty()) {
    for (int i = 0; i < str.length(); ++i) {
      putchar(str[i]);
      std::fflush(stdout);
      std::this_thread::sleep_for(
          std::chrono::milliseconds(static_cast<int>(speed)));
    }
  }
}

// 清空缓冲区
void ClearCache() { scanf("%*[^\n]%*c"); }
} // namespace IO

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
void AddCommand(const std::string &name, void (*func)()) {
  command[name] = func;
}
namespace Calc {
  // 加法
  std::string Add(const std::string &addendA, const std::string &addendB) {
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
  std::string Sub(const std::string &minuend, const std::string &subtrahend) {
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
} // namespace Calc

// 应用类
void calc() {
  printf("欢迎使用计算器\n请输入算式: ");
  std::string expression;
  IO::scanfs(expression);
  if (expression.find('+') != std::string::npos) {
    const size_t Add = expression.find('+');
    const std::string right = expression.substr(0, Add);
    const std::string left = expression.substr(Add + 1, expression.length());
    printf("%s + %s = %s\n", right.c_str(), left.c_str(),
           Calc::Add(right, left).c_str());
  }
  if (expression.find('-') != std::string::npos) {
    const size_t Sub = expression.find('-');
    const std::string right = expression.substr(0, Sub);
    const std::string left = expression.substr(Sub + 1, expression.length());
    printf("%s - %s = %s\n", right.c_str(), left.c_str(),
           Calc::Sub(right, left).c_str());
  }
  if (expression.find('*') != std::string::npos) {
    int right = 0, left = 0;
    try {
      const size_t lc = expression.find('*');
      right = stoi(expression.substr(0, lc));
      left = stoi(expression.substr(lc + 1, expression.length()));
    } catch (const std::exception &e) {
      printf("程序出现错误, 错误为 %s, 可能原因: 算数过大\n", e.what());
    }
    printf("%d * %d = %d\n", right, left, right * left);
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
    if (FILE *file = fopen(filename.c_str(), "w+")) {
      if (!text.empty() && text[0] == '\n')
        text.erase(0, text.find_first_not_of('\n'));
      fprintf(file, "%s", text.c_str());
      fclose(file);
    } else {
      printf("无法打开文件");
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
    printf("你好，未来的 %s ，我希望你成为一名 %s ，我想你 %s "
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
      if (!tg)
        break;
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
}

// 版权输出

// 主函数
int main() {
  // calc();
  // notes();
  // mail();
  // saol();
  command["Hi"] = MineSweeper;
  command["Hi"]();
  return 0;
}