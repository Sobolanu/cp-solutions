#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long

using namespace std;

/*
valid ans is from [0, n] presumably
you could sort by value, and then cost of using that teleporter would be
value + i, where i is the index
perhaps sort such that value + i is minimized?

indeed, that was the correct way to do it
first time i had to write a custom comparator tho
*/

bool comp(pair<int, int> a, pair<int,int> b)
{
    int sum1 = a.first + a.second;
    int sum2 = b.first + b.second;

    return (sum1 == sum2) ? (a.first < b.first) : (sum1 < sum2);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, c;
        cin >> n >> c;

        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i + 1;
        }

        sort(all(a), comp);

        int ans{};
        for(int i = 0; i < n; i++)
        {
            if(c >= (a[i].first + a[i].second))
            {
                ans++;
                c -= (a[i].first + a[i].second);
            }
        }
        cout << ans << '\n';
    }
}
