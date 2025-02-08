#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;

using namespace std;

int mod = 1000000007;

/*
Finally did my first DP problem (somewhat) on my own
I looked at the editorial on the codeforces blog but never really
thought about it, just took away a few key observations

Went from brute-recursion, to memoized DP to iterative DP. 
Memoized didn't work well due to large constraints, so i had
to go iterative.
*/
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n{};
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 6 && i - j >= 0; j++)
            dp[i] = (dp[i] % mod) + (dp[i - j] % mod);

    cout << dp[n] % mod << '\n';
}
