#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long

using namespace std;

/*
ts was so obvious but i couldn't catch it
took from editorial

apparently you can use two pointers to see if
difference of elements becomes K, p. cool
*/

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(auto& x : a) cin >> x;

        sort(all(a));

        bool flag{};
        int l{}, r = 1;

        if(n == 1)
            flag = (a[0] == k);
        else
        {
            while(l < n && r < n)
            {
                if(a[l] + abs(k) == a[r])
                {
                    flag = true;
                    break;
                }
                else if(a[l] + abs(k) < a[r])
                    l++;
                else
                    r++;
            }
        }

        (flag) ? cout << "YES\n" : cout << "NO\n";
    }
}
