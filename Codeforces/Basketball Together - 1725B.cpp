#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

// you can increase power either by maximizing the largest element or
// by adding more of the smallest ones

/*
used two pointers and some edge cases had to be covered
*/

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, d;
    cin >> n >> d;

    vector<int> v(n);
    for (auto& x : v) cin >> x;

    sort(all(v));

    int l{}, r = n - 1;

    int ans{}, teamSize{2};
    if(v.size() == 1 && v[0] > d)
        ans = 1;
    else
    {
        while (l < r)
        {
            if(v[l] > d)
            {
                ans += v.size() - l;
                break;
            }
            else if(v[r] > d)
            {
                ans++;
                r--;
            }
            else if (teamSize * v[r] > d)
            {
                ans++;
                r--;
                l++;

                teamSize = 2;
            }
            else
            {
                teamSize++;
                if (teamSize > n)
                    break;

                l++;
            }
        }
    }

    cout << ans << '\n';
}
