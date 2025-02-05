#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

/*
liked this problem, it's basically
static range sum query + two pointers, very cool
*/
main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n{};
        cin >> n;

        vector<int> v(n);
        for(auto& x : v) cin >> x;

        vector<int> p(n + 1, 0);
        for(int i = 1; i <= n; i++)
            p[i] = p[i-1] + v[i-1];

        string s;
        cin >> s;

        int l{}, r = s.length() - 1, ans{};
        while (l <= r)
        {
            bool flag{ false };
            if (s[l] == 'L' && s[r] == 'R')
            {
                ans += p[r + 1] - p[l];
                flag = true;
                r--;
            }

            if (s[r] != 'R' && !flag)
                r--;
            else
                l++;
        }

        cout << ans << '\n';
    }
}
