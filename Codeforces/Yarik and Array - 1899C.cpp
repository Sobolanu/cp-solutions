#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ull unsigned long long

using namespace std;

/*
took from editorial, i got the idea but my implementation
was needlessly complicated and nightmare-ish
*/
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for(auto& x : v) cin >> x;

        int ans = v[0];
        int mn = min(0, v[0]), sum = v[0];
        for (int i = 1; i < n; i++)
        {
            if (abs(v[i] % 2) == abs(v[i - 1] % 2))
            {
                mn = 0;
                sum = 0;
            }
            sum += v[i];
            ans = max(ans, sum - mn);
            mn = min(mn, sum);
        }

        cout << ans << '\n';
    }
}
