#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

/*
ripped from editorial, but i knew i had to
use another pointer for string T. Didn't know how to implement it,
becuase i'm very brainrotted today from regret (iykyk)
*/
main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string s, t;
        cin >> s >> t;

        int l{};

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '?')
            {
                if(l < t.size())
                    s[i] = t[l++];
                else
                    s[i] = 'a';
            }
            else if(s[i] == t[l])
                ++l;
        }

        if(l >= t.size())
            cout << "YES\n" << s << '\n';
        else
            cout << "NO\n";
    }
}
