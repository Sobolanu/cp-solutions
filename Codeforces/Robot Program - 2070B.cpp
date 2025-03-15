#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long

using namespace std;

/*
once the robot gets to point 0, it essentially is going to loop over and over again
however before it reaches 0, for the first time,
it may/may not loop, so that's going to be brute-forced (which is viable)

so plan is:
- brute force until it hits zero
- it will now loop, calculate via a formula or smthn
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long

using namespace std;

/*
once the robot gets to point 0, it essentially is going to loop over and over again
however before it reaches 0, for the first time,
it may/may not loop, so that's going to be brute-forced (which is viable)

so plan is:
- brute force until it hits zero
- it will now loop, calculate via a formula or smthn

had to rip impl. off of editorial, i HATE off-by-one errors
i'm not a big fan of them, 30-on-30
*/

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;
    while (t--)
    {
        ll n, x, k; string s;
        cin >> n >> x >> k >> s;

        for(int i = 0; i < n; i++)
        {
            x += ((s[i] == 'L') ? -1 : +1);
            k--;

            if(x == 0)
                break;
        }

        ll ans{};
        if(x == 0)
        {
            ans = 1;
            for(int i = 0; i < n; i++)
            {
                x += (s[i] == 'L' ? -1 : +1);
                if(x == 0)
                {
                    ans += k / (i + 1);
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}

