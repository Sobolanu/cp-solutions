#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long

using namespace std;

/*
MY FIRST DIV2 B SOLVE IN-CONTEST!!!!
p.s waited AFTER contest was over to upload this to my github
*/

/*
permutation is perfect if, for all I
the sum of the first i elements is not a perfect square

sum of all natural numbers is n(n+1) / 2, so if that's a perfect square then it will always be impossible
we could maybe check such thing for all n(n+1) as n approaches 1
*/

bool isPerfectSquare(ll n)
{
    ll squareRootN = (ll)round((sqrt(n)));
    return (squareRootN * squareRootN == n);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        if (n == 1 || isPerfectSquare((n * (n + 1)) / 2))
        {
            cout << -1 << '\n';
            continue;
        }

        vector<int> ans(n); ll sum{ 3 };
        ans[0] = 2;
        ans[1] = 1;

        int carry{};
        for (int i = 2; i < n; i++)
        {
            if (carry != 0)
            {
                ans[i] = carry;
                sum += carry;
                carry = 0;
            }
            else if (isPerfectSquare(sum + i + 1))
            {
                carry = i + 1;
                ans[i] = i + 2;
                sum += (i + 2);
            }
            else
            {
                ans[i] = i + 1;
                sum += i + 1;
            }
        }

        for (auto& x : ans) cout << x << " ";

        cout << '\n';
    }
}
