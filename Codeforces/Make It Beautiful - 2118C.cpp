#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;
typedef unsigned long long ull;

const int mod = 1e9 + 7;
// const int mod = 998'244'353;

using namespace std;

/*
the power of two located at the rightmost zero is ((i | (i+1)) - i) where i is some number

editorial solution is much more elegant and idk why i was trying to go for O(1) by finding rightmost bit
instead of just iterating through them, the time loss is like non-existent
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll ans = 0;
        vector<ll> a(n);
        for (ll &i : a)
        {
            cin >> i;
            ans += __builtin_popcountll(i);
        }

        for (int j = 0; j <= 60; j++)
        {
            ll bb = (1ll << j);
            for (ll x : a)
            {
                if (!(x & bb) && k >= bb)
                {
                    ans++;
                    k -= bb;
                }
            }
        }
        cout << ans << "\n";
    }
}

