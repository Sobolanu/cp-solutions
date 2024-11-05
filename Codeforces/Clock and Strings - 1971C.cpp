#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

/*
Thought of the order of A's and B's however wasn't sure.
Totally off the mark, was thinking about some difference stuff.

Note to self - for Div 2, 3, 4 A and B problems they do not take much thinking.
You're overthinking basic stuff.
*/

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;

    while(t--)
    {
        int a{}, b{}, c{}, d{};
        std::cin >> a >> b >> c >> d;

        std::string s{};

        for(int i = 1; i <= 12; i++)
        {
            if(i == a || i == b)
                s += "a";
            if(i == c || i == d)
                s += "b";
        }

        if(s == "abab" || s == "baba")
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}