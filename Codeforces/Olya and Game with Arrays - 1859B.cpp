#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

/*
honestly i'm decent at recognizing and figuring out how the
problem should be done, i just suck at implementing the solutions.
Yoinked implementation from editorial.
*/
main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    cin >> t;

    while (t--)
    {
        int n{};
        cin >> n;

        vector<vector<int>> g(n);
        int ans{LONG_LONG_MAX}, ans2{LONG_LONG_MAX}, ans3{};

        while(n--)
        {
            int m{};
            cin >> m;

            vector<int> v(m);
            for(auto& x : v) cin >> x;

            std::sort(all(v));
            if(v[0] < ans)
                ans = v[0];
            if(v[1] < ans2)
                ans2 = v[1];

            ans3 += v[1];
        }

        cout << ans - ans2 + ans3 << '\n';
    }
}
