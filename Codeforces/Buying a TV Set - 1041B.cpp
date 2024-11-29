#include <iostream>
#include <numeric>
typedef unsigned long long ull;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    ull a{}, b{}, x{}, y{};
    std::cin >> a >> b >> x >> y;

    ull gc = std::gcd(x, y);
    x /= gc;
    y /= gc;

    std::cout << std::min(a / x, b / y);
}