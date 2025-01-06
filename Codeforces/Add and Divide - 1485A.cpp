#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef unsigned long long ull;

// cool little simple problem, fairly low constraints so not that hard

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;
    while(t--)
    {
        int a{}, b{};
        std::cin >> a >> b;

        if(b > a)
        {
            std::cout << 1 << '\n';
            continue;
        }
        if(a == b)
        {
            std::cout << 2 << '\n';
            continue;
        }
        else
        {
            int mn{INT_MAX};
            for(int i = b; ; i++)
            {
                int cmp = a, opNum{i - b};

                if(i == 1)
                {
                    opNum++;
                    i++;
                }
                while(cmp != 0)
                {
                    cmp /= i;
                    opNum++;
                }

                if(opNum < mn)
                    mn = opNum;

                if(i <= std::sqrt(a))
                    continue;
                else
                    break;
            }

            std::cout << mn << '\n';
        }
    }
}