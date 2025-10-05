#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define x first
#define y second

typedef long long ll;
typedef unsigned long long ull;

const int mod = 1e9 + 7;

using namespace std;

/*
you can move one monster to any cell that isn't already occupied
then you select one rectangle and all monsters in it will be destroyed
1 coin for each cell, min coins needed?

the amount of coins needed generally is
(max x - min x) * (max y - min y)

find bottom left most, upper right most, bottom right most
and upper right most, because when you destroy all monsters
the area that gets destroyed is rectangle shaped

so:
    - upper left-most (lowest x and highest y)
    - upper right-most (highest x and highest y)
    - bottom left-most (lowest x and lowest y)
    - bottom right-most (highest x and lowest y)

then move each to the most optimal spot
for the upper mosts, it is most optimal to move to the next cell below them
for lower mosts, it is most optimal to move to the next cell above them
for right mosts, move to the next cell left of them and for left move to right

i understood the idea almost instantly just that the implementation is pain-staking
so i took it from the editorial
*/

struct min_max{
    ll mx1, mx2, mn1, mn2;

    void fix_mx(){
        if(mx1 < mx2){
            swap(mx1, mx2);
        }
    }
    void fix_mn(){
        if(mn1 > mn2){
            swap(mn1, mn2);
        }
    }

    min_max(int a, int b){
        mx1 = mn1 = a;
        mx2 = mn2 = b;
        fix_mx();
        fix_mn();
    }

    void add(ll x){
        mx2 = max(mx2, x);
        mn2 = min(mn2, x);
        fix_mx();
        fix_mn();
    }

    ll get_seg(ll x){
        pair<ll, ll> res = {mn1, mx1};
        if(x == mn1) res.x = mn2;
        if(x == mx1) res.y = mx2;
        return res.y - res.x + 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<ll, ll>> coord(n);
        for(auto &e: coord)
        {
            cin >> e.x >> e.y;
        }
        if(n <= 2)
        {
            cout << n << '\n';
            continue;
        }

        min_max xc(coord[0].x, coord[1].x), yc(coord[0].y, coord[1].y);
        
        for(int i = 2; i < n; ++i)
        {
            xc.add(coord[i].x);
            yc.add(coord[i].y);
        }

        ll ans = xc.get_seg(-1) * yc.get_seg(-1);
        for(int i = 0; i < n; ++i)
        {
            ll x = xc.get_seg(coord[i].x);
            ll y = yc.get_seg(coord[i].y);
            if(x * y == n - 1)
            {
                ans = min(ans, min((x + 1) * y, x * (y + 1)));
            }
            else
            {
                ans = min(ans, x * y);
            }
        }
        cout << ans << '\n';
    }
}

