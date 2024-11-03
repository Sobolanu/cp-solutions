#include <iostream>
#include <vector>

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

        std::vector<int> v(n);
        for(auto& x : v) std::cin >> x;

        std::vector<int> b(n); std::vector<int> c(n);

        auto mx = std::max_element(v.begin(), v.end());
        auto mn = std::min_element(v.begin(), v.end());

        int score{};

        if(*mx - *mn == 1)
        {
            for(int i = 0; i < n; i++)
            {
                b[i] = *mn;

                (i == 0) ? c[i] = *mn : c[i] = *mx;
                score += (c[i] - b[i]);
            }
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                c[i] = *mx;

                (i == 0) ? b[i] = *mx : b[i] = *mn;
                score += (c[i] - b[i]);
            }
        }

        std::cout << score << '\n';
    }
}