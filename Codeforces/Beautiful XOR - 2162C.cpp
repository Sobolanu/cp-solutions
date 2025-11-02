#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;
typedef unsigned long long ull;

const int mod = 1e9 + 7;
// const int mod = 998'244'353;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;

    while (t--)
    {
        int a{}, b{};
        cin >> a >> b;

        if (floor(log2(b)) > floor(log2(a)))
        {
            cout << -1 << '\n';
            continue;
        }

        if(a == b)
        {
            cout << 0 << '\n';
            continue;
        }

        int x = 1;
        vector<int> res{};

        for (int i = 0; i < 32; i++)
        {
            if (a == b)
            {
                cout << res.size() << '\n';

                for (auto& y : res)
                    cout << y << " ";

                cout << '\n';

                break;
            }

            if ((a & x) != (b & x))
            {
                a ^= x;
                res.emplace_back(x);
            }

            x *= 2;
        }
    }
}
