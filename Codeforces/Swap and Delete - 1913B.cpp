#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

/*
delete character from s - one coin
swap characters in s, free

what is minimum cost to make string good?
after applying an operation on S, you get a new string T.

T is good if t[i] != s[i]
you have to "flip" the bits in T to make it good

idea:

swap the ones and zeroes (1 -> 0, 0 -> 1) then remove the ones that overlap

i wonder if there was a simpler way to implement this...
*/

string invertedString(std::string& s)
{
    string comp;

    int zeroes{}, ones{};

        for(auto& x : s)
            (x == '0') ? zeroes++ : ones++;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '1' && zeroes > 0)
            {
                comp.push_back('0');
                zeroes--;
            }
            else
            {
                if(ones > 0)
                {
                    comp.push_back('1');
                    ones--;
                }
                else
                    comp.push_back('0');
            }
        }

    return comp;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        string t = invertedString(s);

        int ans{};
        if(s.length() == 0)
        {
            cout << 1 << '\n';
            continue;
        }

        for(int i = 0; i < t.length(); i++)
        {
            if(s[i] == t[i])
            {
                int segLength{};
                for(int j = i; j < t.length(); j++)
                    if(s[i] == t[j])
                        segLength++;

                t.erase(i, segLength);
                ans += segLength;
                i -= segLength;
            }
        }

        cout << ans << '\n';
    }
}
