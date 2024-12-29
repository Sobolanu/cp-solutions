#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;

int mexTable(char& a, char& b)
{
    if (a != b) return 2;
    else if (a == '1' && b == '1') return 0;
    else return 1;
}

/*
fun little problem, just an annoying amount of case work
oh and my internet went out for like 5 min so yeah LMAO was a bit slow
*/

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;
    while (t--)
    {
        int n{};
        std::cin >> n;

        std::string s1{}, s2{};
        std::cin >> s1 >> s2;

        int cnt{};
        for (int i = 0; i < n; i++)
        {
            if((s1[i] == '1' && s2[i] == '1') && (s1[i + 1] == '0' && s2[i + 1] == '0') || (s1[i] == '0' && s2[i] == '0') && (s1[i + 1] == '1' && s2[i + 1] == '1'))
            {
                cnt += 2;
                i++;
            }
            else
               cnt += mexTable(s1[i], s2[i]);
        }

        std::cout << cnt << '\n';
    }
}
