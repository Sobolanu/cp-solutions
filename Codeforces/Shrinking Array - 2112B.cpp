#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;
typedef unsigned long long ull;

const int mod = 1e9 + 7;
// const int mod = 998'244'353;

using namespace std;

/*
|b[i] - b[i+1]| <= a

as long as array contains two elements,
we can pick any i and i+1 in a
select any integer x between those two
remove those two integers and place a single X

the array must be greater size than two

we are looking for a pair of indices i and i+1, and selecting a number x such that
x is a[i-1] and a[i+2], or off by one

my impl. was far too stupid and editorial one is better
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

        vector<int> a(n);
        for(auto& x : a) cin >> x;

        bool flag{};

        for (int i = 1; i < n; i++)
        {
            if (abs(a[i - 1] - a[i]) <= 1)
            {
                cout << 0 << '\n';
                flag = true;
                break;
            }
        }

        if(!flag)
        {
            for (int i = 1; i + 1 < n; i++)
            {
                if (a[i - 1] < a[i] && a[i] > a[i + 1])
                {
                    cout << 1 << '\n';
                    flag = true;
                    break;
                }
                if (a[i - 1] > a[i] && a[i] < a[i + 1])
                {
                    cout << 1 << '\n';
                    flag = true;
                    break;
                }
            }
        }

        if(!flag)
            cout << -1 << '\n';
    }
}

