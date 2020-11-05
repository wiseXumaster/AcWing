#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL dp[N];
LL pos[27];

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < 27; i++)
        pos[i] = -1;

    dp[0] = 1;
    pos[s[0] - 'a'] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + i - pos[s[i] - 'a'];
        pos[s[i] - 'a'] = i;
    }
    LL res = 0;
    for (int i = 0; i < n; i++)
        res += dp[i];
    cout << res << endl;
    system("pause");
    return 0;
}
