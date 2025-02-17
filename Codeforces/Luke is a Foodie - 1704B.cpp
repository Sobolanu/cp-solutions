#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

/*
i thought of the possible range for the food affinity but my greedy
was wrong, copied from editorial
*/
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> v(n);
        for (auto& k : v) cin >> k;

        int ans{};
        int l = v[0], r = v[0];
        for(int i = 0; i < n; i++)
        {
            if(v[i] > r)
                r = v[i];
            if(v[i] < l)
                l = v[i];
            if(r - l > 2*x)
            {
                ans++;
                l = r = v[i];
            }
        }

        cout << ans << '\n';
    }
}
