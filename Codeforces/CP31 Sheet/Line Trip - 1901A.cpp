#include <iostream>
#include <vector>

// Minimum amount of fuel needed will be either the largest difference between two points
// or the amount of fuel necessary to go from final point to end and back
// or in math terms, (end - finalPoint) * 2.

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;
    while(t--)
    {
        int n{}; int x{}; int diff{}; int prev{};
        std::cin >> n >> x;

        std::vector<int> v(n);
        for(int i = 0; i < n; i++)
        {
            std::cin >> v[i];
            diff = std::max(diff, v[i] - prev);
            prev = v[i];
        }

        diff = std::max(diff, 2* (x - prev));
        std::cout << diff << '\n';
    }
}
