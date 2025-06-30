#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;
typedef unsigned long long ull;

const int mod = 1e9 + 7;
// const int mod = 998'244'353;

/*
card I beats card J if i > j, with one exception: card 1 always beats card n

as long as they have cards:
    - alice picks a card and places it face up on the table
    - bob picks his (optimal choice) card and places it face up
    - if alice's beats bob's then she takes both cards, else bob takes them

a player may use a card they took from before
game continues as long as both have at least one card, loser is the one without any cards

if player P has both card 1 and card n, they win
if player P has neither card, always lose

if alice has card 1 and bob has card n
alice loses unless bob's only card is card n, in which case she wins

if alice has card n, and bob has card 1 - alice must have card n-1 to win

edge case is n = 2, in which case the winner is whoever owns s[0]

tedious casework, did it on my own tho
*/

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n; string s;
        cin >> n >> s;

        if(n == 2 || s[0] == s[n-1])
        {
            (s[0] == 'A') ? cout << "Alice\n" : cout << "Bob\n";
            continue;
        }

        if(s[0] == 'A' && s[n-1] == 'B')
        {
            bool flag{true};

            for(int i = 1; i < n-1; i++)
            {
                if(s[i] == 'B')
                {
                    flag = false;
                    break;
                }
            }

            (!flag) ? cout << "Bob\n" : cout << "Alice\n";
            continue;
        }

        if(s[0] == 'B' && s[n-1] == 'A')
            (s[n-2] == 'A') ? cout << "Alice\n" : cout << "Bob\n";
    }
}

