//this is a wonderful windows 19.2.2
#include<bits/stdc++.h>
#include<windows.h>
#include<fstream>
using namespace std; 
//命令库：清屏：system("cls"); 
//等待：Sleep(); 
//声音：Beep(频率,时间); 
string s;
string o;
string c; 
int abc;

void Prints(string s,int speed)//自动换行 
{
	for(int i=0; i<s.size(); i++)
	{
		cout<<s[i];
		Sleep(speed);
	}
	cout<<endl;
	return ;
}
void wechat(){
	puts("加我微信！！！");
	puts("wx号：bgp20130427.验证信息请敲：LUOGU,UID=XXX(XXX为洛谷uid号)");
	puts("额额额，我是个xxs欸！");
	return ;
}
void gameku(){
	string ggg = "欢迎来到4399小游戏官网";
	Prints(ggg, 300);
	system("pause");
	system("start https://www.4399.com");
	return ;
}
void leetcode(){
	string wreerq = "请注意，本次的编程之旅，可能会引起夜间盗汗，使用之前务必咨询相关医生使用！！！";
	puts("力扣网站-----全世界人(精神病患者)的选择");
	Prints(wreerq, 300);
	puts("确定？(Y/N)");
	char c;
	cin >> c;
	if(c == 'Y'){
		puts("你确定的话，我就不管你了");
		Sleep(1000);
		system("start https://leetcode.cn/") ;
	} 
	else{
		return ;
	}
	return ;
}

void coutrlor(){
	puts("计算机，用作两数的运算，先输入符号，后输入两个数");
	int xv, zxcv;
	char yyy;
	cin >> yyy;
	cin >> xv >> zxcv;
	if(yyy = '+'){
		cout << xv + zxcv << endl;
	} 
	else if(yyy = '-'){
		cout << xv - zxcv << endl;
	}
	else if(yyy = '*'){
		cout << xv * zxcv << endl;
	}
	else if(yyy = '/'){
		cout << xv / zxcv << endl;
	}
	else{
		puts("无效符号");
		return ;
	}
} 
void CPS(){
	puts("测试你的游戏速度---------点击更多，游戏就开挂！！！");
	Sleep(1000);
	system("start https://clickpersecond.com/cn/1-second/");
	return ;
} 
void mail(){
	puts("你自己的未来信箱");
	string name, things, fut;
	int ededed;
	cout << "输入你的名字：";
	cin >> name;
	cout << "输入你未来想做的职业：";
	cin >> things; 
	cout << "输入你的愿望";
	cin >> fut;
	puts("已发送！") ;
	puts("是否查看信件(1/0)");
	cin >> ededed;
	if(ededed == 0){
		return ;
	} 
	else{
		cout << name << ":" << endl;
		cout << "你好，未来的" << name << "，我希望你成为一名" << things << "，我想你" << fut << "，希望你能完成！！";  
		puts("");
		cout << "                                                                                             " << name;
		cout << endl;
	}
	return ;
} 
void bd(){
	puts("百度一下");
	Sleep(1000);
	system("start https://www.baidu.com/");
	return ;
} 
void text(){
	puts("刷题时间到了，刷题吧！");
	Sleep(1000);
	int abc = rand()%(10120-1000)+1000;
	puts("请输入题号！"); 
	string qwe;
	cin >> qwe;
	string qwqw = "start https://www.luogu.com.cn/problem/" + qwe;
	system(qwqw.c_str());
//	puts("大更改的浏览器");
//	Sleep(3000);
//	string s;
//	puts("输入浏览网页网址:");
//	cin >> s;
//	s = "start " + s;
//	system(s.c_str());
//参照他的 wushaochen yi Edogawa_Conan
	return ;
}
static string nowtm(){
	time_t t = time(NULL);
	char ch[64] = {0};
	strftime(ch,sizeof(ch) - 1,"%Y-%m-%d %H:%M:%S",localtime(&t));
	return ch;
}
void presenter(){
	puts("朋友们大家好，现在的时间是：");
	cout << nowtm() << endl;
	cout << endl;
	puts("世界那么大，我想去看看");
	puts("来来来"); 
	system("start https://www.luogu.com.cn/team/71582");
	return ;
}
void ziyanfa(){
	puts("您已进入自研发解析");
	puts("名：TbS-FXS-endsts");
	int sxsxdsx;
	puts("请输入数字");
	puts("列表：");
	puts("0.退出 1.钟表 2.团队 3.简介 4.Administrator");
	while(1){
		cin >> sxsxdsx;
		if(sxsxdsx == 0){
			return ;
		}
		if(sxsxdsx == 1){
			cout << "时间" << nowtm() << endl; 
		}
		if(sxsxdsx == 2){
			puts("我们的研发团队: TBS-FXS团队");
			puts("详情见QQ群908658106");
			Prints("若想退出，请在这段文字结束后按 [0] 退出", 100);
		}
		if(sxsxdsx == 3){
			puts("系统已实现自研发！！！");
			puts("这是一个系统");
			puts("系统高效又好笑");
			Prints("若想退出，请在这段文字结束后按 [0] 退出", 100);
		}
		if(sxsxdsx == 4){
			puts("Administrator");
			puts("指令：");
			puts("按 [mkd] + 文件夹名字(只输入一个字母) 创建文件夹 按 [odd] + 文件夹名字 打开文件夹(只输入一个字母) 按[mkt] + 文件名字创建文件(只输入一个字母) 按 [o] 退出 (指令需要按回车，退出不用)");
			while(1){
				string one;
				char two; 
				char mkeddir[10001];
				cin >> one;
				if(one == "o"){
					break;
				}
				int y = 1;
				if(one == "mkd"){
					cin >> two;
					cout << "您创建了一个名为" << two << "的文件夹" << endl;
					y = 1;
					mkeddir[y] = two;
					y ++;
				}
				if(one == "odd"){
					puts("请输入您第几个创建-1的文件夹");
					cin >> y;
					cout << "这是一个名为" << mkeddir[y] << "的文件夹" << endl; 
					cout << "您打开了" << endl;
					break;
				}
				if(one == "mkt"){
					cin >> two;
					cout << "您创建了一个名为" << two << "的TXT文件" << endl;
					cout << "输入内容，按 [Q + 回车] 完成";
					string saving;
					for(int i = 0; i < 100001; i++){
						cin >> saving[i];
						if(saving[i] == 'Q'){
							Prints("完成完成！", 50);
							break;
						}
					}
					cout << "请您自己复制粘贴您的文件，注意Q" << endl; 
				}
			}
		}
	}
	return ;
}
void downcpp(){
	puts("来来来，下c++载来！");
	Sleep(2000);
	system("start https://www.onlinedown.net/soft/9500.htm");
	return ;
}
void chinajy(){
	puts("国家云教育平台");
	Sleep(2000);
	system("start https://basic.smartedu.cn/");
	return ;
}
void funnyth(){
	system("echo 神奇的事情");
	Sleep(2000);
	system("start https://lglg.top/61884"); 
	return ;
}
void codeforces(){
	system("echo CODEFORCES----百万编程人士的信赖");
	system("start https://codeforces.com/") ;
	return ;
}
void game(){
	string qwq = "想玩游戏了吗？和我来吧！";
	Prints(qwq, 50);
	system("echo 网友自制minecraft");
	system("pause");
	system("start http://ws.imc.re/");
	puts("哎呦我，老得劲了！！");
	return ; 
} 
void gametwo(){
	string qwer = "轻松时刻-------游戏时刻";
	Prints(qwer, 300);
	system("echo google小恐龙在线版本！！！");
	system("pause");
	system("start https://dinorunner.com/zh/");
	return ; 
} 
void txt(string q){
	puts("文本编辑器");
	Sleep(1000);
	system("cls"); 
	o = "这是一个文本自由写作器，可以在这里写作，最后要敲“/”+ enter结束，注意，需要最后自己复制文本的，没有任何东西监视你，请放心使用（好骂，大胆骂）";
	Prints(o,30);
	for(int i = 0;i <= 10000;i++){
		cin >> s[i]; 
		if(s[i] == '/'){
			break;
		} 
	}
	return ; 
}

void qwqw(){
	puts("系统之家---一键下载");
	Sleep(500);
	system("start https://windows.ycgxgy.cn/");
	return ;
} 

void cpu(){
	puts("CPU配置：Intel Core i7");
	puts("ip地址：223.101.195.145");
	return ;
} 
void copyright(){
	puts("copyright by longlong Co.,Ltd..");
	return ;
} 
void input_zll(){
	puts("智能指令开启网站！！！");
	puts("输入");
	string ssss;
	cin >> ssss; 
	ssss = "start " + ssss;
	system(ssss.c_str()); 
//	char str2[1024];
//cin.getline(str2,1024);//读入char数组
	return ;
}
void catstore()
{
	puts("由于技术原因，个人商店暂不支持在该版本上使用，只能用淘宝，望见谅。"); 
	puts("");
	puts("");
	puts("");
	puts("                                                          白格平");
	puts("                                                   2023年12月28日");
	return ;
}




void jd(){
	puts("来买东西吧！");
	Sleep(1000);
	ShellExecuteA(NULL, "open", (LPCSTR)"https://www.jd.com/", NULL, NULL, SW_MAXIMIZE);
}


void kfcid(){
	Prints("QQ腾讯网-----搜索更多的事情", 500);
	system("start https://www.qq.com/");
	Prints("66666", 500);
	Prints("666666666666666666666", 500);
	Prints("QQ腾讯网-----搜索更多的事情66666666666666666666666666", 500);
	Prints("QQ腾讯网-----搜索更多的事情66666666666666666666", 500);
	return ;
}
void fy(){
	puts("360翻译------难题翻译我最行！");
	system("start https://fanyi.so.com/#");
	puts("66666666666666666");
	Prints("666666666666666666666", 200);
	return ;
}
void address(){
	puts("We are in:");
	puts("中国辽宁省阜新市海州区中华路129-2-206科技有限公司");
	return ;
}
void state()
{
	puts("配置");
	puts("CPU：CNQXZ-C9000S 3.2THZ");
	puts("GPU：CNQXZ-G9000S 5GB存储 2.33THZ  30.2兆 图形渲染/秒");
	puts("RAM: 64GB  ROM: 12TB");
	puts("16位 DOS式系统     CN-QX-OS V12.1.2");
	puts("状态");
	cout<<"CPU "<<rand()%15<<"%"<<endl;
	cout<<"GPU "<<rand()%15<<"%"<<endl;
	cout<<"RAM "<<rand()%10<<"%"<<endl;
	cout<<"ROM 1%"<<endl;
	return ;
}
void prog(){
	puts("好用的编程软件--洛谷IDE");
	Sleep(3000);
	system("start https://www.luogu.com.cn/ide");
	return ;
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
	puts("2024-5-17  10.0.0 大更新163邮箱！同时更新微信介绍！") ; 
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
	return ;
}
void looking(){
	puts("大更改的浏览器");
	Sleep(3000);
	string s;
	puts("输入浏览网页网址:");
	cin >> s;
	s = "start " + s;
	system(s.c_str());
	return ;
}
void sd(){
	puts("苏达办公------线上工具");
	system("start https://bangong.360.cn/index.html#");
	return ;
}
void bat(){
	puts("如果你不介意的话，你能让我关一下你的电脑吗(yes/no)");
	string qeew;
	cin >> qeew;
	if(qeew == "yes"){
		puts("ok bye");
		system ("shutdown -s -t 10");
	} 
	else if(qeew == "no"){
		puts("no你必须同意");
		system ("shutdown -s -t 10");
	} 
	return ;
} 
void about_windows(){
	puts("我们的系统搞笑又高效，可以从各种条件下运行！为编程人士打造的题库系统"); 
	puts("建议运行系统：Windows 10"); 
	puts("建议运行CPU：intel Core i7"); 
	puts("系统类别：基于ubuntu的指令操作系统"); 
	puts("名称：alanbecker's-first-PC"); 
	return ;
}
void pblktct(){
	puts("alanbecker代码输出，sunyuhao负责编辑，tongyifeng负责试用。此版权为sunyuhao与alanbecker所有，请勿在未获得权限");
	puts("的情况下私自在各网站上发布，谢谢");
	puts("洛谷网站                        alanbecker联系洛谷alanbecker");
	puts("www.luogu.com.cn                sunyuhao联系洛谷stzhl"); 
	puts("Copyright by sunyuhao and alanbecker C");
	return ;
}
void look(){
	puts("浏览");
	Sleep(1000);//43.6 is lowest 
	system("start https://hao.360.com/");
	return ;
}
void taotao(){
	string sss;
	puts("是否购物");
	cin >> sss;
	if(sss == "no"){
		cout << "谢谢惠顾";
		return ; 
	}
	else{
		system("echo 66666666666666666666");
		Sleep(2000);
		system("start https://www.taobao.com/");
	}
	return ;
}
void hzhz(){
	puts("Hydro Online Judge，原名H，是世界知名的OJ"); 
	Sleep(1000); 
	string sssss;
	cout << "输入题号！！！"; 
	cin >> sssss;
	string qwaszxc = "start https://hydro.ac/p/" + sssss;
	system(qwaszxc.c_str());
	Prints("Its OK!", 300);
	return; 
}
void kkk(){
	puts("累了吗？刷会视频吧！"); 
	Sleep(1000); 
	system("start https://www.ixigua.com/");
	return; 
}
void ybt(){

	puts("信息学奥赛在线练习网站！！！");
	Sleep(2000);
	puts("开发者 sunyuhao") ;
	Sleep(2000);
	system("start http://ybt.ssoier.cn:8088/ ") ;
	return ;
}
void TBS(){
	puts("我们TBS公司成立于2023年");
	puts("内由三名成员组成");
	puts("分别是：alanbecker(总代码输出)");
	puts("sunyuhao：总编辑(同时负责部分代码输出 )");
	puts("Tongyifeng：第一试用者");
	puts("此系统由2023-12-23 开始编译，制作不易，请勿抄袭，谢谢！");
	puts("sunyuhao 致敬");
	return;	
}
void ys(){
	puts("来添加一个163邮箱吧！！");
	Sleep(1000);
	system("start https://mail.163.com/"); 
	return;
}
void ajy(){
	puts("想刷剧了吗？来爱奇艺吧！");
	Sleep(1000) ;
	system("start https://www.iqiyi.com/ ");
	return;
}
void jjxrb(){
	puts("狙击小日本无敌版！");
	Sleep(1000);
	puts("那叫一个爽爽爽！！！！！！真解恨！！！！！"); 
	ShellExecuteA(NULL, "open", (LPCSTR)"https://www.2344.com/flash/28135.htm", NULL, NULL, SW_MAXIMIZE);
}
int main(){
	system("color 17");
	puts("请您先登陆");
	puts("请输入账号与密码");
	string qaz, wsx;
	cin >> qaz >> wsx;
	if(qaz == "alanyufeng" && wsx == "bgp20130427"){
		system("cls");
		system("color 17");
		puts("为防止屏幕太小而导致您的体验结果，请放大屏幕");
		Sleep(5000);
		system("cls");
		system("color 17");
		srand(time(0));
		cout << "开机时间：" << nowtm() << endl;
		Sleep(1000);
		system("cls"); 
		system("color 17");
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
		Sleep(5000);
		system("cls");
		Sleep(1);
		s="";
		Beep(550,400);
		Beep(605,400);
		Beep(660,400);
		Beep(715,400);
		Beep(770,400);
		s="loading......";
		for(int i=0; i<s.size(); i++)
		{
			cout<<s[i];
			Sleep(100);
		}
		Sleep(500);
		for(int i=1; i<=100; i+=1)
		{
			system("CLS");
			system("color 17");
			for(int j=1; j<=i; j++)
			{
				cout<<"-";
			}
			cout<<endl;
			cout<<i;
			puts("%");
			Sleep(rand()%15);
		}
		system("cls");
		system("color 17");
		s="本系统采用了终端操作系统，能有效的在多种情况↓运行，使用命令控制。请勿恶意使用这个操作系统，否则你的电脑将出现卡顿，运行慢等情况。严禁抄袭！！严禁抄袭！！！"; 
		Prints(s,50);
		Sleep(5000);
		system("CLS"); 
		system("color 17");
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
		while(1)
		{
			cout<<"TBS-FXS19.1.2(weveDIR)>>>";
			cin>>s;
			if(s=="shut")
			{
				system("cls");
				system("color 17");
				break;
			}
			if(s=="st"){
				cpu();
				continue;
			}
			if(s=="catstore")
			{
				catstore();
				continue;
			}
			if(s=="pblktct")
			{
				pblktct();
				continue;
			}
			if(s=="weyf")
			{
				ziyanfa();
				continue;
			}
			if(s=="jd")
			{
				jd();
				continue;
			}
			if(s=="qq")
			{
				kfcid();
				continue;
			}
			if(s=="ML")
			{
				mail();
				continue;
			}
			if(s=="CPS")
			{
				CPS();
				continue;
			}
			if(s=="hzhz")
			{
				hzhz();
				continue;
			}
			if(s=="game")
			{
				game();
				continue;
			}
			if(s=="jjxrb")
			{
				jjxrb();
				continue;
			}
			if(s=="looking")
			{
				looking();
				continue;
			}
			if(s=="sllfy")
			{
				fy();
				continue;
			}
			if(s=="cnjy")
			{
				chinajy();
				continue;
			}
			if(s=="ctl")
			{
				coutrlor();
				continue;
			}
			if(s=="leetcode")
			{
				leetcode();
				continue;
			}
			if(s=="sd")
			{
				sd();
				continue;
			}
			if(s=="4399game")
			{
				gameku();
				continue;
			}
			if(s=="xtzj")
			{
				qwqw();
				continue;
			}
			if(s=="input_zll")
			{
				input_zll();
				continue;
			}
			if(s=="bat")
			{
				bat();
				continue;
			}
			if(s=="game2")
			{
				gametwo();
				continue;
			}
			if(s=="maimaimai")
			{
				taotao();
				continue;
			}
			if(s=="downloadcpp"){
				downcpp();
				continue;
			} 
			if(s=="state")
			{
				state();
				continue;//0lQAQl0
			} 
			if(s=="update")
			{
				update(); 
				continue;
			} 
			if(s=="address")
			{
				address(); 
				continue;
			} 
			if(s=="fn"){
				funnyth();
				continue;
			}
			if(s=="CODEFORCES"){
				codeforces();
				continue;
			}
			if(s == "copy"){
				copyright();
				continue;
			}if(s=="showshow"){
				presenter();
				continue;
			}
			if(s=="write"){
				txt(c);
				continue;
			} 
			if(s=="tct"){
				text();
				continue;
			}
			if(s=="look"){
				look();
				continue;
			}
			if(s=="prog"){
				prog();
				continue;
			}
			if(s=="wct"){
				wechat();
				continue;
			}
			if(s=="baidu"){
				bd();
				continue;
			}//My friend is wushaochen
			
			if(s=="aboutthe"){
				about_windows();
				continue;
			}
			if(s=="kkk"){
				kkk();
				continue;
			}
			if(s=="ybt") {
				ybt();
				continue;
			}
			if(s=="TBS"){
				TBS();
				continue;
			} 
			if(s=="ys"){
				ys();
				continue;
			} 
			if(s=="ajy"){
				ajy();
				continue;
			} 	
			cout << s << "不是一个指令" << endl;
			Beep(750,100);
		}
		system("color 17");
		Prints("MADE IN CHINA,BAIGEPING",75);
		Prints("                       ",100);
		Prints("Closeing·······",300);
		Sleep(1000);
	}
	else{
		system("color 17");
		puts("由于你是危险人物，我们强行退出");
		return 0; 
	}
	return 0;
}
