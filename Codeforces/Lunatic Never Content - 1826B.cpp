#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long

using namespace std;

/*
ripped from editorial, knew you had to keep a left pointer and a right pointer tho
for optimal palindrome checking
*/

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int palindrome(vector<int>& a)
{
    int l{}, r = a.size() - 1;

    int mod{0};
    while(l < r)
    {
        mod = gcd(mod, (abs(a[l] - a[r])));
        l++;
        r--;
    }

    return mod;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for(auto& x : v) cin >> x;

        if(set(all(v)).size() == 1)
            cout << 0 << '\n';
        else
            cout << palindrome(v) << '\n';
    }
}
