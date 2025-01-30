#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

/*
wanted to do some fancy optimization shit but got 3 WA verdicts as
a result
tl:dr wanted to break the vector up into chunks however that got
WA.
*/
main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k, d;
        cin >> n >> k >> d;

        vector<int> v(n);
        for (auto& x : v) cin >> x;

        int ans{ LONG_LONG_MAX };

        for (int i = 0; i < n; i++)
        {
            std::set<int> shows{};
            if (i + d <= n)
            {
                for (int j = i; j < i + d; j++)
                    shows.insert(v[j]);
            }

            else if (i + d > n)
            {
                for (int j = n - d; j < n; j++)
                    shows.insert(v[j]);

                if (shows.size() < ans)
                   ans = shows.size();

                break;
            }

            if (shows.size() < ans)
                ans = shows.size();
        }

        cout << ans << '\n';
    }
}