#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ull unsigned long long
#define ll long long
const int mod = 1e9 + 7;

using namespace std;

/*
score is: sum of p[i] for all i divisible by x - sum of p[i] for all i divisible by y
can't construct the permutation ofc, n goes up to 1e9

for each multiple of (x*y), the score will not be affected
otherwise, you'd find a permutation that:
    - maximizes the values p[i] for all x
    - minimizes the values p[i] for all y
we don't really care about the rest of the values, they don't impact the score

we will have n/x values for the x sum, and n/y values for the y sum
the n/x values should be the largest values we can pick (from n downwards)
and n/y values should be smallest values (from 1 upwards)

knew what to do, didn't know impl so i took from
person's sol
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

        ll c = n / lcm(x, y);
        ll a = n - n / x + c;
        ll b = n / y - c;

        cout << (n * (n + 1) - a * (a + 1) - b * (b + 1)) / 2 << '\n';
    }
}
