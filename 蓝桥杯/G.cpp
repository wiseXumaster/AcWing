#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int y, m, d;
int month[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int flag1, flag2;
// 普通回文
bool check_1(int yy, int mm, int dd)
{
	int x1, x2, x3, x4, x5, x6, x7, x8;
	x1 = yy / 1000;
	x2 = yy / 100 % 10;
	x3 = yy / 10 % 10;
	x4 = yy % 10;
	x5 = mm / 10;
	x6 = mm % 10;
	x7 = dd / 10;
	x8 = dd % 10;
	if (x1 == x8 && x2 == x7 && x3 == x6 && x4 == x5)
		return true;
	return false;
}

// ABABBABA
bool check_2(int yy, int mm, int dd)
{
	int x1, x2, x3, x4, x5, x6, x7, x8;
	x1 = yy / 1000;
	x2 = yy / 100 % 10;
	x3 = yy / 10 % 10;
	x4 = yy % 10;
	x5 = mm / 10;
	x6 = mm % 10;
	x7 = dd / 10;
	x8 = dd % 10;
	if (x1 == x3 && x1 == x6 && x1 == x8 && x2 == x4 && x2 == x5 && x2 == x7)
		return true;
	return false;
}

int isYear(int year)
{
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
		return 1;
	return 0;
}

void up()
{
	day[2] += isYear(y);
	d++;
	if (d > day[m])
	{
		d = 1;
		m += 1;
	}

	if (m == 13)
	{
		m = 1;
		y += 1;
	}
	day[2] = 28;
}
int main()
{
	int t;
	cin >> t;
	y = t / 10000;
	m = t % 10000 / 100;
	d = t % 100;

	// 题目说了下一个回文日期，所以直接加一天
	while (1)
	{
		up();
		if (check_1(y, m, d) && !flag1)
		{
			flag1 = 1;
			cout << y;
			if (m < 10)
				cout << 0 << m;
			else
				cout << m;
			if (d < 10)
				cout << 0 << d;
			else
				cout << d;
			up();
			puts("");
		}

		if (check_2(y, m, d) && !flag2 && flag1)
		{
			flag2 = 1;
			cout << y;
			if (m < 10)
				cout << 0 << m;
			else
				cout << m;
			if (d < 10)
				cout << 0 << d;
			else
				cout << d;
			up();
		}

		if (flag1 && flag2)
		{
			system("pause");
			return 0;
		}
	}
	system("pause");
	return 0;
}
