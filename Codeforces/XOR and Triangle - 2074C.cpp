#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long

using namespace std;

/*
solved bitmask problem with binary search, absolute peak
*/
// binary search on non-monotonic thingy i might be cooking/get cooked if i WA
int bs(int x)
{
    int l{}, r = x - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        vector<int> v{x, mid, x ^ mid};
        sort(all(v));

        if(v[0] + v[1] > v[2])
            return mid;
        else if(v[0] + v[1] == v[2])
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

/*
y is less than x
you can form a non degenerate triangle with (x, y, x XOR y)
if such y exists, output it, if not then don't

also check if you can somehow binary search?
least significant bit?
look for number, such that you flip every single bit?
*/

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;

        int ans = bs(x);
        cout << ans << '\n';
    }
}