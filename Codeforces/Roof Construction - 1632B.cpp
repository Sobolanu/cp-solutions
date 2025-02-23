#include <bits/stdc++.h>
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

/*
had an idea that it had to do something with powers of two but i wasn't completely sure
and didn't act on it
*/

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;
    while (t--)
    {
       int n;
       cin >> n;

       int k{};

       while((1 << (k+1)) <= n - 1) k++;

       for(int i = (1 << k) - 1; i >= 0; i--)
          cout << i << " ";
       for(int i = (1 << k); i < n; i++)
          cout << i << " ";

       cout << '\n';
    }
}

