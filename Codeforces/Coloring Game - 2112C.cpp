#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;
typedef unsigned long long ull;

const int mod = 1e9 + 7;
// const int mod = 998'244'353;

/*
alice picks 3 and colors them red
bob picks one and colors it blue (can re-color red ones)

alice wins if sum of her elements is greater than blue
how many ways can alice pick 3 elements in order to win **regardless** of bob?

array is sorted in increasing order

we need 3 elements such that:
    1. their sum is greater than the max element of the whole array
    2. taking the largest number out of said triple will still make the sum greater than the largest number that was taken

so, for indices x, y, z (assuming that x <= y <= z):

a[x] + a[y] + a[z] > a[n-1]
a[x] + a[y] > a[z]

or rather:
a[x] + a[y] + a[z] = max(a[z] * 2, a[n-1])

so, maybe an O(n^2 log n) solution?

n^2 loop for a[x] and a[y]
log n for binary search for z

or bin search for X and iterate for z and y

knew what to do, probably checked the editorial a bit too early
my intuition is spot on though

from now on, on practice problems i'll be doing
edu rounds, div3 and div4
*/

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> a(n);
        for(auto& x : a) cin >> x;

        ll ans{};

        for(int i = 0; i < n; i++) // i is z, j is y because x < y < z
        {
            for(int j = 0; j < i; j++)
            {
                ll x = max(a[n-1], a[i] * 2) - a[i] - a[j];
                ll k = upper_bound(a.begin(), a.begin() + j, x) - a.begin();

                ans += j - k;
            }
        }

        cout << ans << '\n';
    }
}

