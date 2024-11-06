#include <iostream>
#include <string>
typedef unsigned long long ull;

// number of time the substring occurs is the amount of characters you have to remove

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;

    while(t--)
    {
        int n{}; std::string s{};
        std::cin >> n >> s;

        int cnt{};

        for(int i = 0; i < n - 2; i++)
        {
            if((s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p') || (s[i] == 'p' && s[i+1] == 'i' && s[i+2] == 'e'))
            {
                cnt++;
                i += 2;
            }
        }

        std::cout << cnt << '\n';
    }
}
