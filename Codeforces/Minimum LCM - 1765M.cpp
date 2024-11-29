#include <iostream>
typedef unsigned long long ull;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;
    while(t--)
    {
        int n{};
        std::cin >> n;

        int a{1};
        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                a = n / i;
                break;
            }
        }

        std::cout << a << " " << n - a << '\n';
    }
}
