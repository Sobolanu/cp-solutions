#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;
typedef unsigned long long ull;

const int mod = 1e9 + 7;
// const int mod = 998'244'353;

using namespace std;

/*
one of two operations:
    - choose a position i and make everything left equal to a[i], cost is (i-1) * a[i]
    - choose a position i and make everything right equal to a[i], cost is (n-i) * a[i]

min cost to make all elements of array equal?

how to minimize a[i]?
*/

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
        for (auto& x : a) cin >> x;

        if(count(all(a), a[0]) == n)
        {
            cout << 0 << '\n';
            continue;
        }

       ll i = 0;
       ll ans = 1e18;

       while(i < n)
       {
           ll j = i;
           while(j < n && a[j] == a[i])
                j++;

           ans = min(ans, (i + n - j) * a[i]);
           i = j;
       }

       cout << ans << '\n';
    }
}

/*
my original code was similar but obviously the editorial author
gave a formal proof, just that mine was slightly off, here it is:

while (i < n)
{
    int costL = 1e9, costR = 1e9;

    costL = i * a[i];

    while (a[j] == a[i])
    {
        if (j == n - 1)
            break;

        costR = (n - j - 1) * a[j];
        j++;
    }

    ans = min(ans, costL + costR);
    i++;
    j = i;
}

cout << ans << '\n';
*/