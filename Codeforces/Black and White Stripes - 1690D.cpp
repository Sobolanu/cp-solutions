#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

/*
yanked from editorial, but i get the idea: sliding window + prefix sums
*/
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;
    while (t--)
    {
        int n, k; string s{};
        cin >> n >> k >> s;

        vector<int> v(n+1);
        for(int i = 1; i <= n; i++)
            v[i] = v[i-1] + int(s[i-1] == 'W');
        int res = INT_MAX;
        for(int i = k; i <= n; i++)
            res = min(res, v[i] - v[i-k]);
        cout << res << '\n';
    }
}
