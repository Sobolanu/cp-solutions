#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ull unsigned long long
#define ll long long
const int mod = 1e9 + 7;

using namespace std;

/*
count number of beautiful pairs, a pair is beautiful if
(a[i] + a[j] % x == 0) && (a[i] - a[j] % y == 0)
result of subtraction can be negative

a[i] + a[j] ≡ 0 (mod x)
a[i] - a[j] ≡ 0 (mod y)
leads to
a[i] ≡ -a[j] (mod x)
a[j] ≡ a[i] (mod y)

Used GPT to help me code however i figured out the idea on my own. Pretty cool.
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;

        vector<ll> a(n);
        for(auto& x : a) cin >> x;

        map<pair<ll, ll>, ll> freq;
        ll cnt{};

        for (int i = 0; i < n; i++)
        {
            ll mx = (-a[i] % x + x) % x;
            ll my = a[i] % y;

            cnt += freq[{mx, my}];
            freq[{a[i] % x, a[i] % y}]++;
        }

        cout << cnt << '\n';
    }
}

