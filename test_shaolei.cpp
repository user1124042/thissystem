#include <cstdio>
#include <random>

int main()
{
    int w, h, m, ls, al;
    printf("请输入行数: ");
    scanf("%d", &w);
    printf("请输入列数: ");
    scanf("%d", &h);
    char minemap[h][w];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w;++j)
        {
            minemap[i][j] = '.';
        }
    }
    int Minecou = static_cast<int>(h * w * 0.15);
    if (0 < Minecou)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> wrd(0, w - 1);
        std::uniform_int_distribution<> hrd(0, h - 1);
        int minepld = 0, i = 0;
        do
        {
            int wl, hl;
            do
            {
                wl = wrd(gen);
                hl = hrd(gen);
            } while (minemap[hl][wl] == '*');
            minemap[hl][wl] = '*';
            ++ls;
            ++i;
        } while (i < Minecou);        
    }
    bool cail = false;
    do
    {
        int ww, hh;
        printf("请输入你要扫的坐标的所属列: ");
        scanf("%d", &ww);
        printf("请输入你要扫的坐标的所属行: ");
        scanf("%d", &hh);
        if (minemap[ww - 1][hh - 1] != '*')
        {
            minemap[ww - 1][hh - 1] = 'k';
            printf("你很幸运 没中雷\n");
            for (auto& rw : minemap)
            {
                for (char tx : rw)
                {
                    if (tx == 'k')
                    {
                        printf("1");
                    } else {
                        printf("-");
                    }
                }
                printf("\n");
            }
        } else {
            printf("你中雷了!\n");
            for (auto& rw : minemap)
            {
                for (char tx : rw)
                {
                    printf("%c ", tx);
                }
                printf("\n");
            }
            cail = true;
            break;
        }
    } while (!cail);
    if (cail)
    {
        printf("很不幸运 你中雷了");
    }
    return 0;
}