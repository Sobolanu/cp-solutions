#include <iostream>
#include <string.h>

/*
This, by all accounts should not pass because it is O(n^2) however it does.
I'd assume it's to do with "sum of N doesn't exceed 2 * 10^5" and
lucky testcase distribution.
*/
typedef unsigned long long ull;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;
    while(t--)
    {
        int n{}; std::string s{}; bool f{false};
        std::cin >> n >> s;

        for(int i = 0; i < n - 1; i++)
        {
            std::string s2 = s.substr(i, 2);
            if(s.find(s2, i+2) != std::string::npos)
            {
                std::cout << "YES\n";
                f = true;
                break;
            }
        }

        if(!f)
            std::cout << "NO\n";
    }
}