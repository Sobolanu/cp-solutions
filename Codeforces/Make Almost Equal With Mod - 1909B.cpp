#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ull unsigned long long
#define ll long long
const int mod = 1e9 + 7;

using namespace std;

/*
find some value k such that, when we apply a[i] mod k to the array
it will contain 2 distinct values, at least one such k exists

a[i] % 2 would be great if the array has both even and odd values
what if it's only evens or only odds?

multiples of two probably?
"multiples of two" came about when i saw my WA from before, so yeah
i did figure it was something to do with two's though.

got like 6 WA's and i had to switch
ull val = (2 << (i - 1))
to
ull val = (2ULL << (i - 1));
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ull> a(n);
        for (auto& x : a) cin >> x;

        for (int i = 1; i <= 57; i++)
        {
            set<ull> mods{};
            ull val = (2ULL << (i - 1));
            for (int j = 0; j < n; j++)
                mods.insert(a[j] % val);

            if (mods.size() == 2)
            {
                cout << val << '\n';
                break;
            }
        }
    }
}
