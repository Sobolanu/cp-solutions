#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef unsigned long long ull;

/*
Fun little problem, the std::min{} abomination was something done to save on space.
The break condition in this code messed up a ton of stuff so i had to keep track of the amount of times
the loop ran (which would be a max of 30 times, because worst-case scenario for any triplet i'd check log2(v[i]) times

In general, if a problem is tagged "math" then i should always start with a brute-force solution, then a formula of some kind.
*/

int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);

    int t{};
    std::cin >> t;

    while (t--)
    {
        int n{};
        std::cin >> n;

        std::vector<int> v(n);
        for (auto& x : v) std::cin >> x;

        if (std::set(all(v)).size() == 1 && v[0] != 0)
            std::cout << "NO\n";
        else
        {
            for (int i = 1; i <= n - 2; i++)
            {
                int cnt{};
                while (true)
                {
                    if(cnt > 30)
                        break;
                    if (v[i - 1] == 0 || v[i] - 2 < 0)
                        break;
                    if (v[i + 1] == 0)
                    {
                        i += 2;
                        break;
                    }

                    int mn = std::min({(v[i-1] + 1) / 2, (v[i] + 1) / 2, (v[i + 1] + 1) / 2 });

                    v[i - 1] -= mn;
                    v[i + 1] -= mn;
                    v[i] -= (mn * 2);

                    cnt++;
                }
            }

            std::set<int> vals = std::set(all(v));
            if (vals.size() == 1 && vals.count(0))
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
    }
}