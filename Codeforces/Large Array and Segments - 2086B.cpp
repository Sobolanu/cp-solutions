#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;
typedef unsigned long long ull;

const int mod = 1e9 + 7;
// const int mod = 998'244'353;
/*
array B is the array A repeated K times

given X, count the amount of positions L, for which R exists such that
sum of elements of B from [l, r] is **at least** x;

see binary search tag, monotonicity?
bool function: is sum of elements from L to R greater or equal to x? let's fix R to the end
a = 3 4 2 1 5, k = 3 and x = 10

  k = 1       k = 2       k = 3
3 4 2 1 5 | 3 4 2 1 5 | 3 4 2 1 5
T T T T T | T T T T T | T T F F F

45 42 38 36 35 |  30 27 23 21 20 | 15 12 8 6 5 |
T  T  T  T  T     T  T  T  T  T    T  T  F F F

    k = 1         k = 2             k = 3
5 6 7 12 15 | 20 21 23 27 30 | 35 36 38 42 45
F F F T  T    T  T  T  T  T    T  T  T  T  T

the answer would be the final L (not a[L], just L) if one exists

how to get value at a[l]?

3 4 2 1 5, for k = 2 and a[l] = 3 is 23

idea:
take total sum (45), for every k remove the sum of one array (15), then
subtract from the total sum the first n%k elements

now technically we'd also binary search over each k?
binary search over K, iterate for every L starting from the beginning of each array

impl. from editorial, idea worked
*/
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (accumulate(a.begin(), a.end(), 0ll) * k < x)
        {
            cout << 0 << '\n';
            continue;
        }

        ll l = 1, r = n * k;
        while(l <= r)
        {
            ll m = l + (r - l) / 2;
            ll cnt_a = (n * k - m + 1) / n;
            ll suff = (n * k - m + 1) % n;
            ll sum = cnt_a * accumulate(a.begin(), a.end(), 0ll);
            for (int i = n - suff; i < n; i++)
                sum += a[i];
            if (sum < x)
                r = m - 1;
            else
                l = m + 1;
        }

        cout << r << '\n';
    }
}

