#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
set<pair<double, double>> s;
set<pair<double, double>> se;
set<pair<double, double>>::iterator it;
double A[N];
double B[N];

int main()
{
	int n, i, j, x, y;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		// 添加的时候去重
		s.insert(make_pair(x, y));
	}

	n = s.size();

	for (i = 0, it = s.begin(); it != s.end(); i++, it++)
	{
		A[i] = (*it).first;
		B[i] = (*it).second;
	}

	long long ans = 2;

	for (i = 1; i < n; i++)
	{
		for (j = i - 1; j >= 0; j--)
		{
			// 交点的横纵坐标
			double x = (B[j] - B[i]) / (A[i] - A[j]);
			double y = (A[j] * B[i] - A[i] * B[j]) / (A[j] - A[i]);
			// 去掉重复交点
			se.insert(make_pair(x, y));
		}

		//  新的部分=新的交点个数+1
		int m = se.size();
		ans += (m + 1);
	}

	cout << ans << endl;

	system("pause");
	return 0;
}
