#include <bits/stdc++.h>
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

/*
i hate division
my idea would've worked if it wasn't for a few tricky test cases that exploited
the "blind spots" in my code
*/

ull func(ull a)
{
    while(a % 2 == 0)
        a /= 2;

    return a;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;
    while (t--)
    {
        ull a, b;
        cin >> a >> b;

        if(a > b)
            swap(a, b);

        ull r = func(a);
        if(func(b) != r)
            cout << -1 << '\n';
        else
        {
            int ans{0};
            b /= a;

            while(b >= 8)
            {
                b /= 8;
                ans++;
            }

            if(b > 1)
                ans++;

            cout << ans << '\n';
        }
    }
}
