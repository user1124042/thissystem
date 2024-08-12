#include <cstdio>
#include <random>

void saol() {
  printf("编写者： BlocksFunction\n");
  bool tg = false;
  int w, h, m, ls, al, tgcs = 0;
  printf("请输入行数: ");
  scanf("%d", &w);
  printf("请输入列数: ");
  scanf("%d", &h);
  char minemap[h][w];
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
    int minepld = 0, i = 0;
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
      printf("  ");
      for (int j = 0; j < w * 2; ++j) {
        putchar('-');
      }
      printf("\n");
    }
    i + 1 >= 10 ? printf("%d|", i + 1) : printf("%d |", i + 1);
    for (auto &tx : minemap[i]) {
      printf(". ");
    }
    printf("\n");
  }
  do {
    tg = true;
    tgcs = 0;
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
      for (char tx : rw) {
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
        printf("   ");
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
      printf("   ");
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

int main() {
  saol();
  return 0;
}
