#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ull unsigned long long

using namespace std;

/*
each one unit of W adds two to each value
for w = 1, a 3x3 cardboard square becomes 5x5

only thing i copied from editorial was "W can go up to 1e9" (which i
would've figured out from looking at WA).
*/

ull binpow(ull a, ull b)
{
    ull res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ull bs(vector<ull>& v, ull n, ull c)
{
    ull l{}, r = 1e9;
    ull ans{ ULLONG_MAX };
    while (l <= r)
    {
        ull mid = l + (r - l) / 2;

        ull sum{};
        for (int i = 0; i < v.size(); i++)
        {
            sum += binpow((v[i] + (mid * 2)), 2);
            if(sum > c)
                break;
        }

        if (sum == c)
            return mid;
        else if (sum > c)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;
    while (t--)
    {
        int n; ull c;
        cin >> n >> c;

        vector<ull> v(n);
        for (auto& x : v) cin >> x;

        cout << bs(v, n, c) << '\n';
    }
}
