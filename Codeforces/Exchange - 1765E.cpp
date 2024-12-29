#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;

/*
simple observation problem, if a > b then you can just
get infinite coins
else, it doesn't pay off to exchange silver coins for gold coins so just save up gold coins until you can buy
the new weapon
also fuck floating point values
*/

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;
    while(t--)
    {
        int n{}, a{}, b{};
        std::cin >> n >> a >> b;

        if(a > b)
            std::cout << "1\n";
        else
        {
            double ans = (double)n / a;
            std::cout << std::fixed << std::setprecision(0) << std::ceil(ans) << '\n';
        }
    }
}
