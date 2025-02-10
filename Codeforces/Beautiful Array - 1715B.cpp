#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

/*
nice problem, ad-hocy for sure
tl:dr start with an array of zeroes, final element is sum
it has a certain beauty, if it's beauty is greater than
what we're looking for, we set the element before it to
(k - 1) so we don't impact the sum, but reduce the beauty.
reduce it step-by-step until you get answer
*/

/*
beauty of array is the sum of all (a[i] / k)

find the array A, such that:
the beauty is equal to B
the sum of elements is equal to S

elements of final array can be >= 0.

idea:
start with n zeroes and the final element should be s
if the beauty of that is smaller than B, no ans exists
if the beauty is greater than B, then the element before it should be
equal to B-1

we'd check from the decreasing ind to n - 1.
repeat until answer
*/

main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k, b, s;
        cin >> n >> k >> b >> s;

        vector<int> ans(n, 0); int ind = n - 1;
        ans[n - 1] = s;

        int potAns{};

        bool flag{ false };
        for (int i = ind; i <= n - 1;)
        {
            potAns = floor(ans[n - 1] / k);
            if (potAns == b)
            {
                flag = true;
                break;
            }
            else if (potAns < b)
                break; // does not exist
            else
            {
                if (ind - 1 < 0)
                    break; // does not exist

                ans[n-1] -= (k - 1);
                ind--;
                ans[ind] = k - 1;
            }
        }

        if (flag)
        {
            for (auto& x : ans) cout << x << " ";
            cout << '\n';
        }
        else
            cout << -1 << '\n';
    }
}
