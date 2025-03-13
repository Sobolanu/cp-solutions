#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long

ll mod = 1e9 + 7;
using namespace std;

/*
figured something in terms of n + 1 and n - 1 based on zig-zag optimal pattern but
wrong formula lul
*/

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        cout << ((((n*(n+1)) % mod) * (4*n-1)) % mod * 337) % mod << '\n';
    }
}

