#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ull unsigned long long
#define ll long long
const int mod = 1e9 + 7;

using namespace std;

/*
mouf cuts grid in halves or slightly greater basically
fouad moves monster to any cell within the remaining grid

mouf wants to minimize turns, fouad wants to maximize
how many turns will it take? (duel keeps going until grid contains one cell only)

for mouf to minimize, he must cut near the monster and he should cut the maximum amount of cells possible
for fouad to maximize, he must be in the center (or closest thing to it) in the grid

    if monster is at (a, b), then the cells that will be removed (provided A and B are within bounds) are
    max((a - 1) * b, (n - a) * b, (b - 1) * a, (m - b) * a)

after cells are removed, i modify N, M and now modify A and B relative to n and m

yoinked from editorial, had the right idea just bad implementation
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, m, a, b;
        cin >> n >> m >> a >> b;

        vector<pair<ll,ll>> rec = {{
                { a,      m     },
                { n - a + 1, m  },
                { n,      b     },
                { n,    m - b + 1}
            }
        };

        ll best = LLONG_MAX;
        for (auto [n1, m1] : rec)
        {
            ll turns = 0;
            while (n1 > 1)
            {
                ++turns;
                n1 = (n1 + 1) / 2;
            }
            while (m1 > 1)
            {
                ++turns;
                m1 = (m1 + 1) / 2;
            }
            best = min(best, turns);
        }

        cout << best + 1 << '\n';
    }
}

