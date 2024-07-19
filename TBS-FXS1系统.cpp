// this is a wonderful windows 19.2.2
#include <bits/stdc++.h>
#include <unistd.h>
#include <fstream>
#ifdef _WIN32
#include <windows.h>
#else
#endif
#ifdef __linux__
	bool islinux = true;
#else
#endif

using namespace std;
// 命令库：清屏：printf("\033[2J\033[1;1H");
// 等待：sleep();
// 声音：Beep(频率,时间);
string commandor;
string o;
string c;
int abc;

struct PasswordorUsernameError : public exception
{
	const char *what() const throw()
	{
		return "用户名或密码错误";
	}
};

constexpr unsigned int str2int(const char *str, int h = 0)
{
	return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

void OpenWeb(string url)
{
	string command[2] = {"start " + url, "xdg-open " + url};
	#if _WIN32
		system(command[0].c_str());
	#else
	#endif

	#if __linux__
		system(command[1].c_str());
	#endif
}


void Prints(string s, int speed) // 自动换行
{
	for (int i = 0; i < s.size(); i++)
	{
		printf("%c", s[i]);
		sleep(speed / 1000);
	}
	puts("");
	return;
}
void wechat()
{
	puts("加我微信！！！");
	puts("wx号：bgp20130427.验证信息请敲：LUOGU,UID=XXX(XXX为洛谷uid号)");
	puts("额额额，我是个xxs欸！");
	return;
}
void gameku()
{
	Prints("欢迎来到4399小游戏官网", 300);
	while (getchar() != '\n')
		continue;
	getchar();
	OpenWeb("www.4399.com");
	return;
}
void leetcode()
{
	puts("力扣网站-----全世界人(精神病患者)的选择");
	Prints("请注意，本次的编程之旅，可能会引起夜间盗汗，使用之前务必咨询相关医生使用！！！", 300);
	puts("确定？(Y/N)");
	char c;
	cin >> c;
	if (c == 'Y')
	{
		puts("你确定的话，我就不管你了");
		sleep(1);
		OpenWeb("leetcode.cn/");
	}
	else
	{
		return;
	}
	return;
}

void coutrlor()
{
	puts("计算机，用作两数的运算，先输入符号，后输入两个数");
	int xv, zxcv;
	char yyy;
	cin >> yyy; // idk
	scanf("%d %d", &xv, &zxcv);
	if (yyy = '+')
	{
		printf("%d\n", xv + zxcv);
	}
	else if (yyy = '-')
	{
		printf("%d\n", xv - zxcv);
	}
	else if (yyy = '*')
	{
		printf("%d\n", xv * zxcv);
	}
	else if (yyy = '/')
	{
		printf("%d\n", xv / zxcv);
	}
	else
	{
		printf("无效符号\n");
		return;
	}
}
void CPS()
{
	printf("测试你的游戏速度---------点击更多，游戏就开挂！！！\n");
	sleep(1);
	OpenWeb("clickpersecond.com/cn/1-second/");
	return;
}
void mail()
{
	puts("你自己的未来信箱");
	string name, things, fut;
	int ededed;
	printf("输入你的名字：");
	cin >> name;
	printf("输入你未来想做的职业：");
	cin >> things;
	printf("输入你的愿望: ");
	cin >> fut;
	puts("已发送！");
	puts("是否查看信件(1/0)");
	cin >> ededed;
	if (ededed == 0)
	{
		return;
	}
	else
	{
		printf("%s:", name.c_str());
		printf("你好，未来的 %s ，我希望你成为一名 %s ，我想你 %s ，希望你能完成！！！\n", name.c_str(), things.c_str(), fut.c_str());
		puts("");
		printf("                                                                                             %s\n", name.c_str());
	}
	return;
}
void bd()
{
	printf("百度一下\n");
	sleep(1);
	OpenWeb("www.baidu.com/");
	return;
}
void text()
{
	printf("刷题时间到了，刷题吧！\n");
	sleep(1);
	int abc = rand() % (10120 - 1000) + 1000;
	printf("请输入题号: ");
	string tihao;
	cin >> tihao;
	string allurl = "https://www.luogu.com.cn/problem/" + tihao;
	OpenWeb(allurl);
	//	puts("大更改的浏览器");
	//	sleep(3000);
	//	string s;
	//	puts("输入浏览网页网址:");
	//	cin >> s;
	//	s = "start " + s;
	//	system(s.c_str());
	// 参照他的 wushaochen yi Edogawa_Conan
	// 某AR曰:
	// 我改了一下
	// 建议使用OpenWeb 怎么使用呢? 假如我要让它打开www.bing.com, 那么就OpenWeb("www.bing.com");
	// 用法 OpenWeb(目标网址)
	return;
}
static string nowtm()
{
	time_t t = time(NULL);
	char ch[64] = {0};
	strftime(ch, sizeof(ch) - 1, "%Y-%m-%d %H:%M:%S", localtime(&t));
	return ch;
}
void presenter()
{
	printf("朋友们大家好，现在的时间是:\n%s\n\n", nowtm().c_str());
	puts("");
	puts("");
	puts("世界那么大，我想去看看");
	puts("来来来");
	OpenWeb("www.luogu.com.cn/team/71582");
	return;
}
void ziyanfa()
{
	printf("您已进入自研发解析\n");
	puts("名：TbS-FXS-endsts");
	int sxsxdsx;
	puts("请输入数字");
	puts("列表：");
	puts("0.退出 1.钟表 2.团队 3.简介 4.Administrator");
	while (1)
	{
		cin >> sxsxdsx;
		if (sxsxdsx == 0)
		{
			return;
		}
		if (sxsxdsx == 1)
		{
			printf("时间%s", nowtm());
		}
		if (sxsxdsx == 2)
		{
			puts("我们的研发团队: TBS-FXS团队");
			puts("详情见QQ群908658106");
			Prints("若想退出，请在这段文字结束后按 [0] 退出", 100);
		}
		if (sxsxdsx == 3)
		{
			puts("系统已实现自研发！！！");
			puts("这是一个系统");
			puts("系统高效又好笑");
			Prints("若想退出，请在这段文字结束后按 [0] 退出", 100);
		}
		if (sxsxdsx == 4)
		{
			puts("Administrator");
			puts("指令：");
			puts("按 [mkd] + 文件夹名字(只输入一个字母) 创建文件夹 按 [odd] + 文件夹名字 打开文件夹(只输入一个字母) 按[mkt] + 文件名字创建文件(只输入一个字母) 按 [o] 退出 (指令需要按回车，退出不用)");
			while (1)
			{
				string one;
				string two;
				string mkeddir[10001];
				cin >> one;
				if (one == "o")
				{
					break;
				}
				int y = 1;
				if (one == "mkd")
				{
					cin >> two; // idk
					printf("您创建了一个名为 %s 的文件夹\n", two.c_str());
					y = 1;
					mkeddir[y] = two;
					y++;
				}
				if (one == "odd")
				{
					puts("请输入您第几个创建-1的文件夹");
					cin >> y;
					printf("这是一个名为 %s 的文件夹\n", mkeddir[y].c_str());
					cout << "您打开了" << endl;
					break;
				}
				if (one == "mkt")
				{
					cin >> two;
					printf("您创建了一个名为 %s 的TXT文件", two.c_str());
					printf("输入内容，按 [Q + 回车] 完成");
					string saving;
					for (int i = 0; i < 100001; i++)
					{
						cin >> saving[i];
						if (saving[i] == 'Q')
						{
							Prints("完成完成！", 50);
							break;
						}
					}
					cout << "请您自己复制粘贴您的文件，注意Q" << endl;
				}
			}
		}
	}
	return;
}
void downcpp()
{
	puts("来来来，下c++载来！");
	string mode;
	printf("\n有四种选择:\n1. 下载DevC++(很老并且已停止更新的自带Mingw的IDE)\n2. 下载MinGW\n3. 用微软的Visual Studio(或MSVC)\n4. 下载Clang(和LLVM)\n请选择你的模式[D/M/VC/CL]");
	cin >> mode;
	switch (str2int(mode.c_str()))
	{
	case str2int("D"):
		OpenWeb("www.onlinedown.net/soft/9500.htm");
		break;
	case str2int("M"):
	{
		printf("还有两种选择:\n1. 下载Github上的MinGW编译版\n2. 到MinGW64官网下载(Mingw32请自行下载)\n请选择你的模式[G/MG]");
		cin >> mode;
		switch (str2int(mode.c_str()))
		{
			case str2int("G"): OpenWeb("http://www.github.com/niXman/mingw-builds-binaries/releases"); break;
			case str2int("MG"): OpenWeb("https://www.mingw-w64.org/"); break;
		}
		break;
	} // 这里只能用括号包起来
	case str2int("VC"):
		OpenWeb("http://visualstudio.microsoft.com");
		break;
	case str2int("CL"):
		printf("访问可能比较慢, 请稍等\n我们将给你两个下载渠道 一个是Github 一个是官网\n");
		OpenWeb("https://github.com/llvm/llvm-project/releases");
		OpenWeb("https://clang.llvm.org/");
		break;
	default:
		printf("错误: 模式 %s 不存在", mode.c_str());
		break;
	}
	// sleep(2);
	// OpenWeb("www.onlinedown.net/soft/9500.htm");
	return;
}
void chinajy()
{
	puts("国家云教育平台");
	sleep(2);
	OpenWeb("basic.smartedu.cn/");
	return;
}
void funnyth()
{
	printf("神奇的事情");
	sleep(2);
	OpenWeb("lglg.top/61884");
	return;
}
void codeforces()
{
	printf("CODEFORCES----百万编程人士的信赖");
	OpenWeb("codeforces.com/");
	return;
}
void game()
{
	Prints("想玩游戏了吗？和我来吧！", 50);
	printf("网友自制minecraft");
	while (getchar() != '\n')
		continue;
	getchar();
	OpenWeb("ws.imc.re/");
	// puts("哎呦我，老得劲了！！"); sunyuhao你这写的太抽象了吧 --- 某A
	return;
}
void gametwo()
{
	Prints("轻松时刻-------游戏时刻", 300);
	system("echo google小恐龙在线版本！！！");
	while (getchar() != '\n')
		continue;
	getchar();
	OpenWeb("dinorunner.com/zh/");
	return;
}
void txt(string q)
{
	puts("文本编辑器");
	sleep(1);
	printf("\033[2J\033[1;1H");
	Prints("这是一个文本自由写作器，可以在这里写作，最后要敲“/”+ enter结束，注意，需要最后自己复制文本的，没有任何东西监视你，请放心使用（好骂，大胆骂）", 30);
	for (int i = 0; i <= 10000; i++)
	{
		cin >> s[i];
		if (s[i] == '/')
		{
			break;
		}
	}
	return;
}

void qwqw()
{
	puts("系统之家---一键下载");
	sleep(0.5);
	OpenWeb("windows.ycgxgy.cn/");
	return;
}

void cpu()
{
	puts("CPU配置：Intel Core i7");
	puts("ip地址：223.101.195.145");
	return;
}
void copyright()
{
	puts("copyright by longlong Co.,Ltd..");
	return;
}
void input_zll()
{
	puts("智能指令开启网站！！！");
	puts("输入");
	string url;
	cin >> url;
	OpenWeb(url);
	//	char str2[1024];
	// cin.getline(str2,1024);//读入char数组
	return;
}
void catstore()
{
	puts("由于技术原因，个人商店暂不支持在该版本上使用，只能用淘宝，望见谅。");
	puts("");
	puts("");
	puts("");
	puts("                                                          白格平");
	puts("                                                   2023年12月28日");
	return;
}

void jd()
{
	puts("来买东西吧！");
	sleep(1);
	system("https://www.jd.com/");
}

void kfcid()
{
	Prints("QQ腾讯网-----搜索更多的事情", 500);
	OpenWeb("www.qq.com/");
	Prints("66666", 500);
	Prints("666666666666666666666", 500);
	// Prints("QQ腾讯网-----搜索更多的事情66666666666666666666666666", 500); // 为什么要输很多"6"
	// Prints("QQ腾讯网-----搜索更多的事情66666666666666666666", 500);
	return;
}
void fy()
{
	puts("360翻译------难题翻译我最行！");
	OpenWeb("fanyi.so.com/#");
	puts("66666666666666666");
	Prints("666666666666666666666", 200);
	return;
}
void address()
{
	puts("We are in:");
	puts("中国辽宁省阜新市海州区中华路129-2-206科技有限公司");
	return;
}

void state()
{
	puts("配置");
	puts("CPU：CNQXZ-C9000S 3.2THZ");
	puts("GPU：CNQXZ-G9000S 5GB存储 2.33THZ  30.2兆 图形渲染/秒");
	puts("RAM: 64GB  ROM: 12TB");
	puts("16位 DOS式系统     CN-QX-OS V12.1.2");
	puts("状态");
	cout << "CPU " << rand() % 15 << "%" << endl;
	cout << "GPU " << rand() % 15 << "%" << endl;
	cout << "RAM " << rand() % 10 << "%" << endl;
	cout << "ROM 1%" << endl;
	return;
}
void prog()
{
	puts("好用的编程软件--洛谷IDE");
	sleep(3);
	OpenWeb("www.luogu.com.cn/ide");
	return;
}
void update()
{
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
	puts("2024-5-10  2.1.0 终于实现全部自动化关机！！！恭喜！！！！(所以改了一下版本)");
	puts("2024-5-11  2.1.1 得到了力扣网站！！！！！！！！！");
	puts("2024-5-11  3.0.0 系统超级大更新！！！恭喜！！同时，题库也全面升级自动化！！！恭喜！！");
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
	puts("2024-5-17  9.3.2 更新TBS公司介绍!");
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
	puts("2024-5-30  12.4.0 大更新CPS测试。。。Click per second");
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
	puts("2024-7-19 No Version 某AR又又又在他的Fork添加了下载Minecraft的功能");
}
void looking()
{
	puts("大更改的浏览器"); // 个人认为这应该不算浏览器吧..........
	sleep(3);
	string url;
	puts("输入浏览网页网址:");
	cin >> url;
	OpenWeb(url);
	return;
}
void sd()
{
	puts("苏达办公------线上工具");
	OpenWeb("bangong.360.cn/index.html#");
	return;
}
void bat()
{
	puts("如果你不介意的话，你能让我关一下你的电脑吗(yes/no)");
	string qeew;
	cin >> qeew;
	if (qeew == "yes")
	{
		puts("ok bye");
		#ifdef _WIN32
		ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 0);
		#elif __linux__
		system("sudo shutdown now");
		#elif
		#endif
	}
	else if (qeew == "no")
	{
		puts("你没得选(:");
		#ifdef _WIN32
		ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 0);
        #elif __linux__
		system("sudo shutdown now");
		#else
		#endif
	}
	return;
}
void about_windows()
{
	puts("我们的系统搞笑又高效，可以从各种条件下运行！为编程人士打造的题库系统");
	sleep(0.01);
	string os[7] = {"Windows", "Linux", "MacOS", "Unix", "MS-DOS", "FreeBSD", "TempleOS"};
	srand(time(NULL));
	int o = rand() % 7;
	sleep(0.01);
	srand(time(NULL));
	printf("建议运行系统：%s %d\n", os[o].c_str(), rand()); // 这里我写个彩蛋
	string cpu[5] = {"Intel", "AMD", "Loongson", "Qualcomm", "NVDIA"};
	string cpucore[12] = {"Core", "Atom", "Celeron", "Pentium", "Xeon", "Athlon", "Sempron", "Sempron", "Snapdragon", "Scorpion", "Krait", "Grace"};
	printf("建议运行CPU: %s %s\n", cpu[rand() % 5].c_str(), cpucore[rand() % 12].c_str());
	sleep(0.01);
	o = rand() % 7;
	printf("系统类别：基于%s 的指令操作系统\n", os[o].c_str());
	srand(time(NULL));
	string PCNAME = "";
    for (int i = 0; i < rand() % 12 + 5; ++i) {
        char rdc = 'a' + rand() % 26;
        PCNAME += rdc;
    }
	char rdc = 'a' + rand() % 26;
	PCNAME += "'";
	PCNAME += rdc;
	PCNAME += "-";
	for (int i = 0; i < rand() % 6 + 1; ++i) {
        char rdc = 'a' + rand() % 26; 
        PCNAME += rdc;
    }
	PCNAME += "-";
    for (int i = 0; i < rand() % 5 + 1; ++i) {
        char rdc = 'a' + rand() % 26; 
        PCNAME += rdc;
    }
	printf("名称: %s\n", PCNAME.c_str());
	return;
}
void pblktct()
{
	puts("alanbecker代码输出，sunyuhao负责编辑，tongyifeng负责试用。此版权为sunyuhao与alanbecker所有，请勿在未获得权限");
	puts("的情况下私自在各网站上发布，谢谢");
	puts("洛谷网站                        alanbecker联系洛谷alanbecker");
	puts("www.luogu.com                  sunyuhao联系洛谷stzhl");
	puts("Copyright by sunyuhao and alanbecker C");
	return;
}
void look()
{
	puts("浏览");
	sleep(1); // 43.6 is lowest
	OpenWeb("www.bing.com"); // 还是推荐用微软必应
	return;
}
void taotao()
{
	string sss;
	puts("是否购物");
	cin >> sss;
	if (sss == "no")
	{
		printf("谢谢惠顾");
		return;
	}
	else
	{
		printf("66666666666666666666");
		sleep(2);
		OpenWeb("www.taobao.com/");
	}
	return;
}
void hzhz()
{
	puts("Hydro Online Judge，原名H，是世界知名的OJ");
	sleep(1);
	string tihao;
	cout << "输入题号！！！";
	cin >> tihao;
	string allurl = "hydro.ac/p/" + tihao;
	OpenWeb(allurl);
	Prints("Its OK!", 300);
	return;
}
void kkk()
{
	puts("累了吗？刷会视频吧！");
	sleep(1);
	OpenWeb("www.bilibili.com"); // 建议Bilibili
	return;
}
void ybt()
{

	puts("信息学奥赛在线练习网站！！！");
	sleep(2);
	// puts("开发者 sunyuhao"); ?????????????????
	sleep(2);
	OpenWeb("ybt.ssoier.cn:8088/");
	return;
}
void TBS()
{
	puts("我们TBS公司成立于2023年");
	puts("内由三名成员组成");
	puts("分别是：alanbecker(总代码输出)");
	puts("sunyuhao：总编辑(同时负责部分代码输出 )");
	puts("Tongyifeng：第一试用者");
	puts("此系统由2023-12-23 开始编译，制作不易，请勿抄袭，谢谢！");
	puts("sunyuhao 致敬");
	return;
}
void ys()
{
	puts("来添加一个163邮箱吧！！");
	sleep(1);
	OpenWeb("mail.163.com/");
	return;
}
void ajy()
{
	puts("想刷剧了吗？来爱奇艺吧！");
	sleep(1);
	OpenWeb("www.iqiyi.com/ ");
	return;
}
void jjxrb()
{
	// puts("狙击小日本无敌版！");
	sleep(1);
	// puts("那叫一个爽爽爽！！！！！！真解恨！！！！！");
	OpenWeb("www.2344.com/flash/28135.htm");
}
int main()
{
	#ifdef _WIN32
	system("color 17");
	#elif __linux
	printf("使用Windows操作系统体验最佳\n");
	#endif
	puts("请您先登陆");
	puts("请输入账号与密码");
	string qaz, wsx;
	cin >> qaz >> wsx;
	if (qaz == "alanyufeng" && wsx == "bgp20130427")
	{
		#ifdef _WIN32
		system("color 17");
		#else
		#endif
		printf("\033[2J\033[3J\033[1;1H");
		puts("为防止屏幕太小而导致您的体验结果，请放大屏幕");
		sleep(5);
		#ifdef _WIN32
		system("color 17");
		#else
		#endif
		srand(time(0));
		printf("\033[2J\033[3J\033[1;1H");
		cout << "开机时间：" << nowtm() << endl;
		sleep(1);
		#ifdef _WIN32
		system("color 17");
		#else
		#endif
		printf("\033[2J\033[3J\033[1;1H");
		puts("************* ************  *************               ************* *          *  *************      **     *************     *************");
		puts("      *       *           * *                           *              *        *   *               *   *     *           *                 *");
		puts("      *       *           * *                           *               *      *    *             *     *     *           *                 *");
		puts("      *       *           * *                           *                *    *     *                   *     *           *                 *");
		puts("      *       *           * *                           *                 *  *      *                   *     *           *                 *");
		puts("      *       ************  ************* ************* *************      **       *************       *     *************     *************");
		puts("      *       *           *             *               *                 *  *                  *       *                 *     *");
		puts("      *       *           *             *               *                *    *                 *       *                 *     *");
		puts("      *       *           *             *               *               *      *                *       *                 *     *");
		puts("      *       *           *             *               *              *        *               *       *                 *  ** *");
		puts("      *       ************  *************               *             *          *  ************* *********** *************  ** *************");
		puts("                           智     能     计     算     机     TBS-FXS1系		统								");
		puts("                                         Made with BAIGEPING&SUNYUHAO V19.1.4(版权所有)");
		puts("");
		puts("*****        *********     *********");
		puts("*    ***     *       *     *        ");
		puts("*      *     *       *     *********     system     system     system     system    system     system     system    system     system");
		puts("*    ***     *       *             *");
		puts("*****        *********     *********");
		puts("");
		puts("*  *  *   ********   *        *******  *******    ** **   *******  *");
		puts("*  *  *   *          *        *        *     *   *  *  *  *        *");
		puts("*  *  *   ********   *        *        *     *   *  *  *  *******  *");
		puts("*  *  *   *          *        *        *     *   *  *  *  *");
		puts(" ** **    ********   *******  *******  *******   *  *  *  *******  *");
		sleep(5);
		#ifdef _WIN32
		system("color 17");
		#else
		#endif
		sleep(1);
		commandor = "";
		#ifdef _WIN32
		Beep(550,400);
		Beep(605,400);
		Beep(660,400);
		Beep(715,400);
		Beep(770,400);
		#else
		#endif
		printf("\033[2J\033[3J\033[1;1H");
		commandor = "loading......";
		for (int i = 0; i < s.size(); i++)
		{
			printf("%c", s[i]);
			sleep(100 / 1000);
		}
		sleep(500 / 1000);
		for (int i = 1; i <= 100; i += 1)
		{
			printf("\033[2J\033[3J\033[1;1H");
			#ifdef _WIN32
			system("color 17");
			#else
			#endif
			for (int j = 1; j <= i; j++)
			{
				printf("-");
			}
			printf("%d%", i);
			sleep((rand() % 15) / 1000);
		}
		#ifdef _WIN32
		system("color 17");
		#else
		#endif
		printf("\033[2J\033[3J\033[1;1H");
		Prints("本系统采用了终端操作系统，能有效的在多种情况↓运行，使用命令控制。请勿恶意使用这个操作系统，否则你的电脑将出现卡顿，运行慢等情况。严禁抄袭！！严禁抄袭！！！", 50);
		sleep(5);
		#ifdef _WIN32
		system("color 17");
		#else
		#endif
		printf("\033[2J\033[3J\033[1;1H");
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
		puts("bat············· 大更改的关机");
		puts("leetcode···········力扣网站，编程");
		puts("input_zll·········· 自己输入网站打开");
		puts("4399game···········4399");
		puts("cnjy·············网课");
		puts("pblktct··········· 公告");
		puts("sd··············苏打办公");
		puts("kkk············· 西瓜视频");
		puts("ybt············· 信息学奥赛在线练习网站");
		puts("TBS············· TBS公司介绍");
		puts("ys·············  163邮箱");
		puts("ajy············· 爱奇艺");
		puts("xtzj·············系统之家");
		puts("jjxrb············ 狙击小日本");
		puts("jd··············京东");
		puts("qq··············腾讯网");
		puts("sllfy············ 360翻译");
		puts("CPS············· CPS测试");
		puts("ML··············未来信箱");
		puts("hzhz·············Hydro Online Judge");
		puts("weyf·············系统");
		puts("downloadMinecraft..........下载Minecraft");
		while (1)
		{
			cout << "TBS-FXS19.1.2(weveDIR)>>>";
			cin >> commandor;
			switch (str2int(commandor.c_str()))
			{
			case str2int("shut"):
				printf("\033[2J\033[1;1H");
				printf("\033[1;37m");
				continue;
			case str2int("st"):
				cpu();
				continue;
			case str2int("catstore"):
				catstore();
				continue;
			case str2int("pblktct"):
				pblktct();
				continue;
			case str2int("weyf"):
				ziyanfa();
				continue;
			case str2int("jd"):
				jd();
				continue;
			case str2int("qq"):
				kfcid();
				continue;
			case str2int("ML"):
				mail();
				continue;
			case str2int("CPS"):
				CPS();
				continue;
			case str2int("hzhz"):
				hzhz();
				continue;
			case str2int("game"):
				game();
				continue;
			case str2int("jjxrb"):
				jjxrb();
				continue;
			case str2int("looking"):
				looking();
				continue;
			case str2int("sllfy"):
				fy();
				continue;
			case str2int("cnjy"):
				chinajy();
				continue;
			case str2int("ctl"):
				coutrlor();
				continue;
			case str2int("leetcode"):
				leetcode();
				continue;
			case str2int("sd"):
				sd();
				continue;
			case str2int("4399game"):
				gameku();
				continue;
			case str2int("xtzj"):
				qwqw();
				continue;
			case str2int("input_zll"):
				input_zll();
				continue;
			case str2int("bat"):
				bat();
				continue;
			case str2int("game2"):
				gametwo();
				continue;
			case str2int("maimaimai"):
				taotao();
				continue;
			case str2int("downloadcpp"):
				downcpp();
				continue;
			case str2int("state"):
				state();
				continue;
			case str2int("update"):
				update();
				continue;
			case str2int("address"):
				address();
				continue;
			case str2int("fn"):
				funnyth();
				continue;
			case str2int("CODEFORCES"):
				codeforces();
				continue;
			case str2int("copy"):
				copyright();
				continue;
			case str2int("showshow"):
				presenter();
				continue;
			case str2int("write"):
				txt(c);
				continue;
			case str2int("tct"):
				text();
				continue;
			case str2int("look"):
				look();
				continue;
			case str2int("prog"):
				prog();
				continue;
			case str2int("wtc"):
				wechat();
				continue;
			case str2int("baidu"):
				bd();
				continue; // My friend is wushaochen
			case str2int("aboutthe"):
				about_windows();
				continue;
			case str2int("kkk"):
				kkk();
				continue;
			case str2int("ybt"):
				ybt();
				continue;
			case str2int("TBS"):
				TBS();
				continue;
			case str2int("ys"):
				ys();
				continue;
			case str2int("ajy"):
				ajy();
				continue;
			case str2int("downloadMinecraft"):
			{
				puts("该功能用来下载Minecraft");
				printf("如果你没有正版, 请输入N\n如果你已经有正版, 请输入[N/Y]: ");
				string mode;
				mode.resize(1);
				scanf("%s", &mode);
				switch (str2int(mode.c_str()))
				{
				case str2int("N"):
				{
					puts("如果你没有正版账号, 那么最好去官网购买一个Minecraft");
					OpenWeb("www.minecraft.net");
					break;
				}
				case str2int("Y"):
				{
					puts("目前主流Minecraft启动器(或客户端)有很多");
					printf("你可以试试一些经典的\n1. 官方启动器\n2. Lunar Client\n3. LabyMod\n4. Badlion Client\n5. Feather Client\n请选择客户端[MS/L/LMD/B/F]: ");
					string mode;
					cin >> mode;
					switch (str2int(mode.c_str()))
					{
					case str2int("MS"):
						OpenWeb("www.minecraft.net/download");
						break;
					case str2int("L"):
						OpenWeb("www.lunarclient.com");
						break;
					case str2int("LMD"):
						OpenWeb("www.labymod.net");
						break;
					case str2int("B"):
						OpenWeb("www.badlion.net");
						break;
					case str2int("F"):
						OpenWeb("www.feathermc.com");
						break;
					default:
						break;
					}
				}
				default:
					break;
				}
			}
			default:
				break;
			}

			cout << s << "不是一个指令" << endl;
			#ifdef _WIN32
			Beep(750,100);
			#else
			#endif
		}
		printf("\033[1;37m");
		Prints("MADE IN CHINA,BAIGEPING", 75);
		Prints("                       ", 100);
		Prints("Closeing·······", 300);
		sleep(1);
	}
	else
	{
		// printf("\033[1;37m");
		// puts("由于你是危险人物，我们强行退出");
		throw PasswordorUsernameError();
		return 0;
	}
	return 0;
}