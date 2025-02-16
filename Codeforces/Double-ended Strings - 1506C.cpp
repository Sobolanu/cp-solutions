#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

/*
given two strings of equal/nonequal lengths, you can delete
the first character of any of them in any order, or the last character of them
see the minimum num of operations to make the two strings equal

look for longest common substring, then the answer is

s1.length - sub.length + s2.length - sub.length

note to self: never copy from GeeksForGeeks, their code is horrible
my implementation idea was right, however it was so needlessly complicated compared to the
editorial's naive implementation of LCS.
*/

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        int n = s1.length();
        int m = s2.length();

        int ans{};
        for(int l = 1; l <= min(n, m); l++)
            for(int i = 0; i + l <= n; i++)
               for(int j = 0; j + l <= m; j++)
                  if(s1.substr(i, l) == s2.substr(j, l))
                     ans = max(ans, l);

        cout << s1.length() + s2.length() - 2 * ans << '\n';
    }
}
