#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ull unsigned long long
#define ll long long
const int mod = 1e9 + 7;

using namespace std;

/*
two cases:
    - if all elements in b are -1
        to make all elements in the same number, we go from making all elements equal to the max in the array
        until we "run out" of K to use
        for this, the answer is k - (max - min - 1)

    - if at least one element in b is >= 0
        then this means that there is a complementary array, and it's formed by making all elements equal to
        a[i] + b[i], where i is the index of the non-zero element
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);

        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        bool flag{ false }; int ind{};

        for (int i = 0; i < n; i++)
        {
            if (b[i] >= 0)
            {
                ind = i;
                flag = true;
                break;
            }
        }

        if (!flag)
            cout << k - (*max_element(all(a)) - *min_element(all(a)) - 1) << '\n';
        else
        {
            int ans{ 1 }, sum = a[ind] + b[ind];

            for (int i = 0; i < n; i++)
            {
                if (b[i] == -1)
                {
                    if (a[i] + k < sum || a[i] > sum)
                    {
                        ans = 0;
                        break;
                    }
                }
                else if (b[i] >= 0)
                {
                     if (a[i] + b[i] != sum)
                     {
                         ans = 0;
                         break;
                     }
                }
            }

            cout << ans << '\n';
        }
    }
}
