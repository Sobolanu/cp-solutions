#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long

using namespace std;

/*
use binary search to find the value of H
the amount of water in one column is h - a[i],
and if a[i] >= h then no water there

let's assume that K is the position of the first element such that
a[k] >= h, that means that the total amount of water that's used up
would be equal to (h * k-1) - sum of all a[i] from 0 to k-1.
given that N is small enough and we're doing logN operations, i can just sum all a[i] from 0 to n
and i'd get NlogN.

figured out the idea, didn't know how to implement it
in general i should probably learn these binary search problems where
you return L and R instead of just mid
*/

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, w;
        cin >> n >> w;

        vector<int> a(n);
        for (auto& x : a) cin >> x;

        ll l{}, r = INT_MAX;
        while(l < r)
        {
            ll mid = l + (r - l + 1) / 2;
            ll sum{};
            for(int i = 0; i < n; i++)
                sum += max(mid - a[i], 0LL);

            if(sum <= w)
                l = mid;
            else
                r = mid - 1;
        }

        cout << l << '\n';
    }
}
