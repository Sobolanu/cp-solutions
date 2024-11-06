#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

/*
yoinked from editorial - you can always make a right angle
by placing the beginning of both points at 0, just at varying
X and Y coordinates.
*/

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;

    while(t--)
    {
        int x{}; int y{}; int k{};
        std::cin >> x >> y >> k;

        int m = std::min(x, y);
		std::cout << "0 0 " << m << " " << m << '\n';
		std::cout << "0 " << m << " " << m << " 0" << '\n';
    }
}
