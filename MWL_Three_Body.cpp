#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#define float double
using namespace std;
string name;

void Slow(string s, int k = 30) {
	int l = s.length();
	for (int i = 0; i < l; i++) {
		printf("%c", s[i]);
		Sleep(k);
	}
}

int toint(float a) {
	return ((int)(a * 10 + 5)) / 10;
}

void Setpos(float x, float y) {
	COORD pos;
	pos.X = toint(y * 2), pos.Y = toint(x);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Color(int a) {
	if (a % 12 == 0)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		                        FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	if (a % 12 == 1)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		                        FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	if (a % 12 == 2)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		                        FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	if (a % 12 == 3)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		                        FOREGROUND_INTENSITY | FOREGROUND_RED);
	if (a % 12 == 4)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		                        FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	if (a % 12 == 5)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		                        FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	if (a % 12 == 6)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		                        FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	if (a % 12 == 7)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		                        FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	if (a % 12 == 8)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	if (a % 12 == 9)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	if (a % 12 == 10)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		                        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	if (a % 12 == 11)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
}

struct node {
	float x, y, z;
	float vx, vy, vz;
	float r, m;
	bool life;
} Sun[1000001];
int a = 1, b, T, More = 40, Speed = 1;
bool flag = 0;

void Push(int a, int b) {
	float Ax = Sun[a].x - Sun[b].x;
	float Ay = Sun[a].y - Sun[b].y;
	float Dis2 = Ax * Ax + Ay * Ay;
	float Dis = sqrt(Dis2);
	if (Dis < 1) {
		return;
	}
	float dt = More / 10.0f;
	Sun[a].vx -= Sun[b].m * Ax * dt / (Dis2 * Dis);
	Sun[a].vy -= Sun[b].m * Ay * dt / (Dis2 * Dis);
	Sun[b].vx += Sun[a].m * Ax * dt / (Dis2 * Dis);
	Sun[b].vy += Sun[a].m * Ay * dt / (Dis2 * Dis);
}


void Move() {
	const int substeps = 10;
	double sub_dt = (More / 10.0) / substeps;
	double eps = 5.0;
	if (flag) {
		for (int i = 1; i <= b; i++) {
			Setpos(Sun[i].x / More, Sun[i].y / More);
			cout << "  ";
		}
	}
	for (int step = 0; step < substeps; step++) {
		for (int i = 1; i <= b; i++) {
			for (int j = i + 1; j <= b; j++) {
				double dx = Sun[i].x - Sun[j].x;
				double dy = Sun[i].y - Sun[j].y;
				double r2 = dx * dx + dy * dy;
				double denom = r2 + eps * eps;
				double denom_sqrt = sqrt(denom);
				double factor = sub_dt / (denom * denom_sqrt);
				Sun[i].vx -= Sun[j].m * dx * factor;
				Sun[i].vy -= Sun[j].m * dy * factor;
				Sun[j].vx += Sun[i].m * dx * factor;
				Sun[j].vy += Sun[i].m * dy * factor;
			}
		}
		for (int i = 1; i <= b; i++) {
			Sun[i].x += Sun[i].vx * sub_dt;
			Sun[i].y += Sun[i].vy * sub_dt;
		}
	}
	for (int i = 1; i <= b; i++) {
		if (Sun[i].x < 0 || Sun[i].x > 12000 || Sun[i].y < 0 || Sun[i].y > 24000)
			continue;
		Setpos(Sun[i].x / More, Sun[i].y / More);
		Color(i);
		cout << "●";
	}
}

int rand(int a) {
	return rand() % a;
}

void Start(int a) {
	Sun[a].x = 6000 + 6000 - (rand() % 12001), Sun[a].y = 12000 + 12000 - (rand() % 24001),
	      Sun[a].vx = (6000 - (rand() % 12001)) / 1000.0,
	            Sun[a].vy = (1000 - (rand() % 2001)) / 2000.0, Sun[a].m = 10000;
}//(rand(20)+1)*100;}

void Three_Body_Round() {
	name = "三体运动（圆周）（v=sqrt(M/sqrt(3)R)/sqrt(2)）";
	double s = sqrt(1 / sqrt(3)) / sqrt(8);
	b++;
	Sun[a].x = 4000, Sun[a].y = 12000, Sun[a].vx = 0 * s,
	      Sun[a].vy = 2 * s, Sun[a].m = 1000;
	a = 2;
	b++;
	Sun[a].x = 7000, Sun[a].y = 12000 - sqrt(3) * 1000.0, Sun[a].vx = -sqrt(3) * s,
	      Sun[a].vy = -1 * s, Sun[a].m = 1000;
	a = 3;
	b++;
	Sun[a].x = 7000, Sun[a].y = 12000 + sqrt(3) * 1000.0, Sun[a].vx = sqrt(3) * s,
	      Sun[a].vy = -1 * s, Sun[a].m = 1000;
}

void Three_Body_Mass() {
	name = "三体运动（《三体》中大家喜闻乐见的东西）（其实很难产生稳定的三星系统，99% 的情况会出现有一颗恒星被加速到逃逸速度然后就回不来了，还有 0.9% 会四颗星一起朝某个方向移动也回不来了）";
	b++;
	Sun[a].x = 6000 + 2000 - (rand() % 4001), Sun[a].y = 12000 + 2000 - (rand() % 4001),
	      Sun[a].vx = (2000 - (rand() % 4001)) / 1000.0,
	            Sun[a].vy = (1000 - (rand() % 2001)) / 2000.0, Sun[a].m = 2000;
	a = 2;
	b++;
	Sun[a].x = 6000 + 2000 - (rand() % 4001), Sun[a].y = 12000 + 2000 - (rand() % 4001),
	      Sun[a].vx = (2000 - (rand() % 4001)) / 1000.0,
	            Sun[a].vy = (1000 - (rand() % 2001)) / 2000.0, Sun[a].m = 2000;
	a = 3;
	b++;
	Sun[a].x = 6000 + 2000 - (rand() % 4001), Sun[a].y = 12000 + 2000 - (rand() % 4001),
	      Sun[a].vx = (2000 - (rand() % 4001)) / 1000.0,
	            Sun[a].vy = (1000 - (rand() % 2001)) / 2000.0, Sun[a].m = 2000;
	a = 4;
	b++;
	Sun[a].x = 6000 + 2000 - (rand() % 4001), Sun[a].y = 12000 + 2000 - (rand() % 4001),
	      Sun[a].vx = (2000 - (rand() % 4001)) / 1000.0,
	            Sun[a].vy = (1000 - (rand() % 2001)) / 2000.0, Sun[a].m = 4;
}

void Three_Body_Round_Plus() {
	name = "稳定三星系统中的行星";
//  炸了，稳定三星系统变成了不稳定三星系统，然后某一次运动之后行星被抛出去了。本来并没有达到逃逸速度，但是恒星被另一颗恒星带走了，然后它就飞了。
	double s = sqrt(1 / sqrt(3)) / sqrt(8);
	b++;
	Sun[a].x = 4000, Sun[a].y = 12000, Sun[a].vx = 0 * s,
	      Sun[a].vy = 2 * s, Sun[a].m = 1000;
	a = 2;
	b++;
	Sun[a].x = 7000, Sun[a].y = 12000 - sqrt(3) * 1000.0, Sun[a].vx = -sqrt(3) * s,
	      Sun[a].vy = -1 * s, Sun[a].m = 1000;
	a = 3;
	b++;
	Sun[a].x = 7000, Sun[a].y = 12000 + sqrt(3) * 1000.0, Sun[a].vx = sqrt(3) * s,
	      Sun[a].vy = -1 * s, Sun[a].m = 1000;
	a = 4;
	b++;
	Sun[a].x = 3000, Sun[a].y = 12000,
	      Sun[a].vx = 0,
	            Sun[a].vy = 2 * s + 1, Sun[a].m = 1;
}

void Two_Body_Round_Plus() {
	name = "双星系统中的行星";
	b++;
	Sun[a].x = 4000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = 1, Sun[a].m = 8000;
	a = 2;
	b++;
	Sun[a].x = 8000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = -1, Sun[a].m = 8000;
	a = 3;
	b++;
	Sun[a].x = 3000, Sun[a].y = 12000,
	      Sun[a].vx = 0,
	            Sun[a].vy = 1 + 2 * sqrt(2), Sun[a].m = 1;
}

void Single_Body_Plus_Round() {
	name = "小质量行星绕恒星转动（圆形版，v=sqrt(M/R)）";
	b++;
	Sun[a].x = 4000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = sqrt(2) / 2.0, Sun[a].m = 1;
	a = 2;
	b++;
	Sun[a].x = 6000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = 0, Sun[a].m = 1000;
}

void Single_Body_Plus() {
	name = "小质量行星绕恒星转动（椭圆版，v<sqrt(M/R)）";
	b++;
	Sun[a].x = 4000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = 0.5, Sun[a].m = 1;
	a = 2;
	b++;
	Sun[a].x = 6000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = 0, Sun[a].m = 1000;
}

void Single_Body_Plus_Away() {
	name = "小质量行星达到逃逸速度（抛物线，v=sqrt(2M/R)）";
	b++;
	Sun[a].x = 4000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = 1, Sun[a].m = 1;
	a = 2;
	b++;
	Sun[a].x = 6000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = 0, Sun[a].m = 1000;
}

void Single_Body_Plus_Mass() {
	name = "小质量行星绕恒星转动（随机）";
	b++;
	Sun[a].x = 6000 + 2000 - (rand() % 4001), Sun[a].y = 12000 + 2000 - (rand() % 4001),
	      Sun[a].vx = (1000 - (rand() % 2001)) / 2000.0,
	            Sun[a].vy = (1000 - (rand() % 2001)) / 2000.0, Sun[a].m = 1;
	a = 2;
	b++;
	Sun[a].x = 6000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = 0, Sun[a].m = 1000;
}

void Single_Body_Plus_Plus_Round() {
	name = "多个小质量行星绕恒星转动（圆形版，v = sqrt(M / R)）";
	b++;
	Sun[a].x = 6000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = 0, Sun[a].m = 4000;
	a = 2;
	b++;
	Sun[a].x = 5000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = 2, Sun[a].m = 4;
	a = 3;
	b++;
	Sun[a].x = 4000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = sqrt(2), Sun[a].m = 4;
	a = 4;
	b++;
	Sun[a].x = 3000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = sqrt(4 / 3.0), Sun[a].m = 4;
	a = 5;
	b++;
	Sun[a].x = 2000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = 1, Sun[a].m = 4;
	a = 6;
	b++;
	Sun[a].x = 1000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = sqrt(0.8), Sun[a].m = 4;
}

void Single_Body_Plus_Plus_Mass() {
	name = "多个小质量行星绕恒星转动（随机）";
//  注意到不同行星之间回相互影响，这个在现实中其实不怎么会发生。我为了维护可视性，行星密度比现实高得多。
//  在这里你可能看到恒星质量太小，甚至被行星带走。
	b++;
	Sun[a].x = 6000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = 0, Sun[a].m = 1000;
	a = 2;
	b++;
	Sun[a].x = 6000 + 3000 - (rand() % 6001), Sun[a].y = 12000 + 3000 - (rand() % 6001),
	      Sun[a].vx = (1000 - (rand() % 2001)) / 2000.0,
	            Sun[a].vy = (1000 - (rand() % 2001)) / 2000.0, Sun[a].m = 1;
	a = 3;
	b++;
	Sun[a].x = 6000 + 3000 - (rand() % 6001), Sun[a].y = 12000 + 3000 - (rand() % 6001),
	      Sun[a].vx = (1000 - (rand() % 2001)) / 2000.0,
	            Sun[a].vy = (1000 - (rand() % 2001)) / 2000.0, Sun[a].m = 1;
	a = 4;
	b++;
	Sun[a].x = 6000 + 3000 - (rand() % 6001), Sun[a].y = 12000 + 3000 - (rand() % 6001),
	      Sun[a].vx = (1000 - (rand() % 2001)) / 2000.0,
	            Sun[a].vy = (1000 - (rand() % 2001)) / 2000.0, Sun[a].m = 1;
	a = 5;
	b++;
	Sun[a].x = 6000 + 3000 - (rand() % 6001), Sun[a].y = 12000 + 3000 - (rand() % 6001),
	      Sun[a].vx = (1000 - (rand() % 2001)) / 2000.0,
	            Sun[a].vy = (1000 - (rand() % 2001)) / 2000.0, Sun[a].m = 1;
}

void Earth_Moon() {
	name = "地月系统（如果你以地球为参考系，你可以看到月球绕地球做圆周运动）";
	b++;
	Sun[a].x = 6000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = 0, Sun[a].m = 50000;
	a = 2;
	b++;
	Sun[a].x = 4000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = 5, Sun[a].m = 50;
	a = 3;
	b++;
	Sun[a].x = 4000, Sun[a].y = 11900, Sun[a].vx = sqrt(0.5),
	      Sun[a].vy = 5, Sun[a].m = 1;
}

void Single_Body_Plus_Two_Body() {
	name = "以两颗行星的质心为参考系，行星都围绕两颗行星的质心做匀速圆周运动。两颗行星的质心围绕恒星做匀速圆周运动（我也不知道竖直速度 0.07 是怎么来的，算出来是 0.1，但是实验起来完全不对）";
	b++;
	Sun[a].x = 4000, Sun[a].y = 11900, Sun[a].vx = 0.072,
	      Sun[a].vy = sqrt(2), Sun[a].m = 4;
	a = 2;
	b++;
	Sun[a].x = 4000, Sun[a].y = 12100, Sun[a].vx = -0.072,
	      Sun[a].vy = sqrt(2), Sun[a].m = 4;
	a = 3;
	b++;
	Sun[a].x = 6000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = 0, Sun[a].m = 4000;
}

void Two_Body_Round() {
	name = "双星系统（v=sqrt(M/R)/2）";
	double s = 0.5;
	b++;
	Sun[a].x = 5000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = s, Sun[a].m = 1000;
	a = 2;
	b++;
	Sun[a].x = 7000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = -s, Sun[a].m = 1000;
}

void Two_Body_Round_Big() {
	name = "双星系统（放大版）";
	double s = 1;
	b++;
	Sun[a].x = 4000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = s, Sun[a].m = 8000;
	a = 2;
	b++;
	Sun[a].x = 8000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = -s, Sun[a].m = 8000;
}

void Two_Body() {
	name = "双星系统（v!=sqrt(M/R)/2，两个椭圆轨道）";
	double s = 1;
	b++;
	Sun[a].x = 4000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = s, Sun[a].m = 16000;
	a = 2;
	b++;
	Sun[a].x = 8000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = -s, Sun[a].m = 16000;
}

void Two_Body_Two_Round() {
	name = "双星系统（v=sqrt(M/2R)，两个圆轨道）";
	double s = 1;
	b++;
	Sun[a].x = 4000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = s, Sun[a].m = 8000 * sqrt(2);
	a = 2;
	b++;
	Sun[a].x = 8000, Sun[a].y = 12000, Sun[a].vx = 0,
	      Sun[a].vy = -s, Sun[a].m = 8000 * sqrt(2);
}

void Very_Mass() {
	name = "大乱斗";

	for (int i = 1; i <= 12; i++) {
		Start(i);
		b++;
	}
}

void Paint() {

	name = "冬日绘版（确信）";

	for (int i = 1; i <= 1000; i++) {
		Start(i);
		b++;
	}
}

void welcome() {
	Setpos(3, 5);
	Color(2);
	Slow(" -- 物 理 引 擎 V 2.1.0 -- ");
	Sleep(200);
	Color(0);
	Setpos(5, 7);
	Slow("1. 开始模拟");
	Sleep(10);
	Setpos(7, 7);
	Slow("2. 查看参数");
	Sleep(10);
	Setpos(9, 7);
	Slow("3. 来点高级的");
	Sleep(10);
	Setpos(11, 7);
	Slow("按下条目前方参数以进入");
get_num_1:
	char c = _getch();

	for (int i = 31; i >= 7; i--) {
		Setpos(11, i);
		printf("  ");
		Sleep(5);
	}

	for (int i = 20; i >= 7; i--) {
		Setpos(9, i);
		printf("  ");
		Sleep(5);
	}

	for (int i = 18; i >= 7; i--) {
		Setpos(7, i);
		printf("  ");
		Sleep(5);
	}

	for (int i = 18; i >= 7; i--) {
		Setpos(5, i);
		printf("  ");
		Sleep(5);
	}

	if (c == '3') {
		Setpos(5, 7);
		Slow("请输入比例尺的分母（默认 1/40）：");
		Setpos(6, 7);
		scanf("%d", &More);
		for (int i = 12; i >= 7; i--) {
			Setpos(6, i);
			printf("  ");
			Sleep(5);
		}
		for (int i = 40; i >= 7; i--) {
			Setpos(5, i);
			printf("  ");
			Sleep(5);
		}
	}

	if (c == '1' || c == '3') {
		Setpos(5, 7);
		Slow("请选择是否清空轨迹：");
		Sleep(10);
		Setpos(7, 7);
		Slow("1. 是");
		Sleep(10);
		Setpos(9, 7);
		Slow("2. 否");
get_num_2:
		char c = _getch();
		if (c == '1') {
			flag = 1;
		} else if (c != '2') {
			goto get_num_2;
		}
		for (int i = 12; i >= 7; i--) {
			Setpos(9, i);
			printf("  ");
			Sleep(5);
		}
		for (int i = 12; i >= 7; i--) {
			Setpos(7, i);
			printf("  ");
			Sleep(5);
		}
		for (int i = 27; i >= 7; i--) {
			Setpos(5, i);
			printf("  ");
			Sleep(5);
		}
		Setpos(5, 7);
		Slow("请选择恒星数量：");
		Sleep(10);
		Setpos(7, 7);
		Slow("1. 1 颗");
		Sleep(10);
		Setpos(9, 7);
		Slow("2. 2 颗");
		Sleep(10);
		Setpos(11, 7);
		Slow("3. 3 颗");
		Sleep(10);
		Setpos(13, 7);
		Slow("4. 作者太菜了，我要自己 DIY！");
		Sleep(10);
		Setpos(15, 7);
		Slow("5. 我要好多好多颗！");
		c = _getch();
		for (int i = 26; i >= 7; i--) {
			Setpos(15, i);
			printf("  ");
			Sleep(5);
		}
		for (int i = 46; i >= 7; i--) {
			Setpos(13, i);
			printf("  ");
			Sleep(5);
		}
		for (int i = 14; i >= 7; i--) {
			Setpos(11, i);
			printf("  ");
			Sleep(5);
		}
		for (int i = 14; i >= 7; i--) {
			Setpos(9, i);
			printf("  ");
			Sleep(5);
		}
		for (int i = 14; i >= 7; i--) {
			Setpos(7, i);
			printf("  ");
			Sleep(5);
		}
		for (int i = 23; i >= 7; i--) {
			Setpos(5, i);
			printf("  ");
			Sleep(5);
		}
		if (c == '1') {
			Setpos(5, 7);
			Slow("请选择具体形式");
			Sleep(10);
			Setpos(7, 7);
			Slow("1. 小质量行星绕恒星转动（圆形）");
			Sleep(10);
			Setpos(9, 7);
			Slow("2. 小质量行星绕恒星转动（椭圆）");
			Sleep(10);
			Setpos(11, 7);
			Slow("3. 小质量行星达到逃逸速度");
			Sleep(10);
			Setpos(13, 7);
			Slow("4. 小质量行星绕恒星转动（随机）");
			Sleep(10);
			Setpos(15, 7);
			Slow("5. 多个小质量行星绕恒星转动（圆形）");
			Sleep(10);
			Setpos(17, 7);
			Slow("6. 两颗行星的质心围绕恒星做匀速圆周运动");
			Sleep(10);
			Setpos(19, 7);
			Slow("7. 地月系统");
			Sleep(10);
			Setpos(21, 7);
			Slow("8. 多个小质量行星绕恒星转动（随机）");
get_num_3:
			c = _getch();
			if (c == '1') {
				Single_Body_Plus_Round();
			} else if (c == '2') {
				Single_Body_Plus();
			} else if (c == '3') {
				Single_Body_Plus_Away();
			} else if (c == '4') {
				Single_Body_Plus_Mass();
			} else if (c == '5') {
				Single_Body_Plus_Plus_Round();
			} else if (c == '6') {
				Single_Body_Plus_Two_Body();
			} else if (c == '7') {
				Earth_Moon();
			} else if (c == '8') {
				Single_Body_Plus_Plus_Mass();
			} else {
				goto get_num_3;
			}
		} else if (c == '2') {
			Setpos(5, 7);
			Slow("请选择具体形式");
			Sleep(10);
			Setpos(7, 7);
			Slow("1. 两颗恒星的质心围绕恒星做匀速圆周运动");
			Sleep(10);
			Setpos(9, 7);
			Slow("2. 两颗恒星的质心围绕恒星做匀速圆周运动（放大版）");
			Sleep(10);
			Setpos(11, 7);
			Slow("3. 两颗恒星分别做匀速圆周运动");
			Sleep(10);
			Setpos(13, 7);
			Slow("4. 两颗恒星分别做椭圆轨道运动");
			Sleep(10);
			Setpos(15, 7);
			Slow("5. 两颗恒星的质心围绕恒星做匀速圆周运动（带行星）");
get_num_4:
			c = _getch();
			if (c == '1') {
				Two_Body_Round();
			} else if (c == '2') {
				Two_Body_Round_Big();
			} else if (c == '3') {
				Two_Body_Two_Round();
			} else if (c == '4') {
				Two_Body();
			} else if (c == '5') {
				Two_Body_Round_Plus();
			} else {
				goto get_num_4;
			}
		} else if (c == '3') {
			Setpos(5, 7);
			Slow("请选择具体形式");
			Sleep(10);
			Setpos(7, 7);
			Slow("1. 三颗恒星的质心围绕恒星做匀速圆周运动");
			Sleep(10);
			Setpos(9, 7);
			Slow("2. 混沌三体系统（带行星）");
			Sleep(10);
			Setpos(11, 7);
			Slow("3. 三颗恒星的质心围绕恒星做匀速圆周运动（带行星）");
get_num_5:
			c = _getch();
			if (c == '1') {
				Three_Body_Round();
			} else if (c == '2') {
				Three_Body_Mass();
			} else if (c == '3') {
				Three_Body_Round_Plus();
			} else {
				goto get_num_5;
			}
		} else if (c == '4') {
			Setpos(5, 7);
			Slow("请你依输入天体的纵坐标，横坐标，横方向初速度，纵方向初速度，质量，连续输入 5 个 0 结束\n");
			a = 0;
			int x, y, vx, vy, m;
			while (scanf("%lf%lf%lf%lf%lf", &x, &y, &vx, &vy, &m)) {
				if (x == 0 && y == 0 && vx == 0 && vy == 0) {
					break;
				}
				++a, ++b;
				Sun[a].x = x;
				Sun[a].y = y;
				Sun[a].vx = vx;
				Sun[a].vy = vy;
				Sun[a].m = m;
			}
		} else if (c == '5') {
			Setpos(5, 7);
			Slow("请选择具体形式");
			Sleep(10);
			Setpos(7, 7);
			Slow("1. 大乱斗");
			Sleep(10);
			Setpos(9, 7);
			Slow("2. 冬日绘版（确信）");
get_num_6:
			c = _getch();
			if (c == '1') {
				Very_Mass();
			} else if (c == '2') {
				Paint();
			} else {
				goto get_num_6;
			}
		} else {
			goto get_num_2;
		}

	} else if (c == '2') {
		Setpos(5, 7);
		Slow("首先我们发现天体运动时可以认为它不受力或仅受到引力");
		Sleep(10);
		Setpos(7, 7);
		Slow("根据必修二我们又可知引力 F=GMm/r^2");
		Sleep(10);
		Setpos(9, 7);
		Slow("这里为了方便 G 取 1");
		Sleep(10);
		Setpos(11, 7);
		Slow("另外在 Dis<20 时为了防止参数爆炸我设置了引力软化");

	} else {
		goto get_num_1;
	}
	system("cls");
	Setpos(5, 7);

}

void warning() {
	Setpos(3, 5);
	Color(3);
	Slow("警 告 ！！！", 100);
	Color(0);
	Setpos(4, 5);
	Slow("请在使用前手动把屏幕缩到最小，再开始模拟");
	Setpos(10, 0);
	Sleep(500);
	Slow("按任意键以继续......");
	_getch();
	system("cls");
}

int main() {

//	Sleep(1500);

	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	srand((unsigned)time(NULL));

	welcome();

	warning();

//	double mn[102][102];
//	for (int i = 1; i <= b; i++) {
//		for (int j = 1; j <= b; j++) {
//			mn[i][j] = 30000;
//		}
//	}
	while (1) {
		Setpos(3, 5);
		Color(0);
		puts(name.c_str());
//		for (int i = 1; i <= b; i++) {
//			printf("%d:(%lf,%lf),(%lf,%lf)\n", i, Sun[i].x, Sun[i].y, Sun[i].vx, Sun[i].vy);
//		}
//		printf("        ");
//		for (int i = 1; i <= b; i++) {
//			printf("%-8d", i);
//		}
//		puts("");
//		for (int i = 1; i <= b; i++) {
//			printf("%-8d", i);
//			for (int j = 1; j <= b; j++) {
//				mn[i][j] = min(mn[i][j], sqrt(pow(Sun[i].x - Sun[j].x, 2) + pow(Sun[i].y - Sun[j].y, 2)));
//				printf("%-8.2lf", mn[i][j]);
//			}
//			puts("");
//		}
		T++;
		Move();
		Sleep(Speed);
	}
}