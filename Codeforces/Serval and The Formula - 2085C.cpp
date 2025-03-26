#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long

using namespace std;

/*
ripped from editorial btw
look for k such that
(x+k)+(y+k)=(x+k)⊕(y+k) 

above equation can be rewritten as
(x+k)&(y+k) = 0

and possible answer is 2^n - max(x, y)
*/
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        unsigned ll x, y;
        cin >> x >> y;

        unsigned ll mx = max(x, y);
        (x == y) ? cout << -1 << '\n' : cout << bit_ceil(mx) - mx << '\n';
    }
}
