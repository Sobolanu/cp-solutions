#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ull unsigned long long

using namespace std;


/*
yoinked from editorial. I thought all ans[i] had to be distinct
but apparently not... i'm so freaking stupid
*/

/*
for any i in ans, ans[i] will be some multiple of i
*/

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> ans(n + 1);
        bool ok{true};
        for(int i = 1; i <= n; i++)
        {
            ans[i] = ((l - 1) / i + 1) * i;
            ok = ok && ans[i] <= r;
        }

        if(ok)
        {
            cout << "YES\n";
            for(int x = 1; x <= n; x++)
                cout << ans[x] << " ";
        }
        else
            cout << "NO";

        cout << '\n';
    }
}
