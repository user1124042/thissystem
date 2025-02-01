#ifndef _IO_H
#define _IO_H

#include <cstdio>
#include <string>
#include <thread>

namespace IO {
// 字符串输入
inline void scanfs(std::string &str) {
    char tmp;
    while ((tmp = static_cast<char>(getchar())) != '\n' && tmp != ' ' &&
           tmp != EOF)
        str += tmp;
}

// 单字符停止
inline void scanfA(std::string &str, const char stopChar) {
    char tmp;
    while ((tmp = static_cast<char>(getchar())) != stopChar)
        str += tmp;
}

// 延迟输出
inline void printfs(const std::string &str, double speed) {
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
inline void ClearCache() { rewind(stdin); }

// 输出颜色
inline void PrintfBlue(const std::string &text) {
    putchar('\033');
    putchar('[');
    putchar('1');
    putchar(';');
    putchar('3');
    putchar('4');
    putchar('m');
    printfs(text, 5);
    putchar('\033');
    putchar('[');
    putchar('0');
    putchar('m');
}

inline void PrintfGreen(const std::string &text) {
    putchar('\033');
    putchar('[');
    putchar('1');
    putchar(';');
    putchar('3');
    putchar('2');
    putchar('m');
    if (text != "Wake up.\n")
        printfs(text, 5);
    else {
        printfs("W", 100);
        printfs("a", 150);
        printfs("k", 200);
        printfs("e", 250);
        printfs(" ", 300);
        printfs("u", 350);
        printfs("p", 400);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        printfs(".", 450);
        printf("\n");
    }
    putchar('\033');
    putchar('[');
    putchar('0');
    putchar('m');
}
} // namespace IO

#endif
