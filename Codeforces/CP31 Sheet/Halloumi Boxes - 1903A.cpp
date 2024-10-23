#include <iostream>
#include <vector>
#include <algorithm>

// If K is greater or equal to two then you can always sort the array.
// Pretty much how bubble sort works.

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;
    while(t--)
    {
        int n{}; int k{};
        std::cin >> n >> k;

        std::vector<int> v(n);
        for(auto& x : v) std::cin >> x;

        if(std::is_sorted(v.begin(), v.end()) || k >= 2)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}