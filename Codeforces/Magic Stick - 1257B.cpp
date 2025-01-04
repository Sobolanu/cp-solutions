#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef unsigned long long ull;

// just a lot of case work, some numbers fall into a cycle
// tl:dr some numbers fall into a cycle where they can't grow larger
// every other number can go up then be reduced to target value

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;

    while(t--)
    {
        ull x{}, y{};
        std::cin >> x >> y;

        if((x == 3 && y > 3) || (x == 1 && y > 1) || (x == 2 && y > 3))
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
    }
}
