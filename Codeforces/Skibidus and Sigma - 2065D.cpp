#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ull unsigned long long
#define int long long
using namespace std;

/*
sort arrays by their sums and do what the problem says
*/

bool cmp(vector<int>& a, vector<int>& b)
{
    int sum1 = accumulate(all(a), 0);
    int sum2 = accumulate(all(b), 0);

    return sum1 > sum2;
}

main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid{};

        while (n--)
        {
            vector<int> b(m);
            for (auto& x : b) cin >> x;
            grid.emplace_back(b);
        }

        sort(all(grid), cmp);

        int ans{}; int pref{};
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < m; j++)
            {
                pref += grid[i][j];
                ans += pref;
            }

        cout << ans << '\n';
    }
}
