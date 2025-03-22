#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long

using namespace std;

/*
if no 0's in array, ans is (1, n)
if we do have zeroes, we want to "eliminate" them

we eliminate them by pairing any other element with them
the MEX of (0, v) where V is any val is always going to be 1, unless V is 1
we can break it down two elements at a time tbf

so goal is: eliminate all zeroes then just sweep across the array
*/

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto& x : a) cin >> x;

        vector<pair<int, int>> ans{};
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 0)
            {
                if (i == 0)
                {
                    if (a[i + 1] == 0 || a[i + 1] >= 2)
                    {
                        a[i] = 1;
                        a.erase(a.begin() + (i + 1));
                        ans.emplace_back(make_pair(i+1, i+2));
                    }
                    else if (a[i + 1] == 1)
                    {
                        a[i] = 2;
                        a.erase(a.begin() + (i + 1));
                        ans.emplace_back(make_pair(i+1, i+2));
                    }
                }
                else if (i == a.size() - 1)
                {
                    if (a[i - 1] == 0 || a[i - 1] >= 2)
                    {
                        a[i] = 1;
                        a.erase(a.begin() + (i - 1));
                        ans.emplace_back(make_pair(i, i + 1));
                    }
                    else if (a[i - 1] == 1)
                    {
                        a[i] = 2;
                        a.erase(a.begin() + (i - 1));
                        ans.emplace_back(make_pair(i, i + 1));
                    }
                }
                else
                {
                    if (a[i + 1] == 0 || a[i + 1] >= 2)
                    {
                        a[i] = 1;
                        a.erase(a.begin() + (i + 1));
                        ans.emplace_back(make_pair(i+1, i+2));
                    }
                    else if (a[i + 1] == 1)
                    {
                        a[i] = 2;
                        a.erase(a.begin() + (i + 1));
                        ans.emplace_back(make_pair(i+1, i+2));
                    }
                    else if (a[i - 1] == 0 || a[i - 1] >= 2)
                    {
                        a[i] = 1;
                        a.erase(a.begin() + (i - 1));
                        ans.emplace_back(make_pair(i, i + 1));
                    }
                    else if (a[i - 1] == 1)
                    {
                        a[i] = 2;
                        a.erase(a.begin() + (i - 1));
                        ans.emplace_back(make_pair(i, i + 1));
                    }
                }
            }
        }

        ans.emplace_back(make_pair(1, a.size()));
        cout << ans.size() << '\n';

        for(auto& [x, y] : ans)
            cout << x << " " << y << '\n';
    }
}
