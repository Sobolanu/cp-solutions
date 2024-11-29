#include <iostream>
#include <vector>
typedef unsigned long long ull;

// am 99% confident i took this from editorial
int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;

    while(t--)
    {
        int n{}, k{};
        std::cin >> n >> k;

        std::vector<int> c(n);
        for(auto& x : c) std::cin >> x;

        int left = 0, right = 0, i = 0, j = n - 1;
        int k_left = k, k_right = k;

        if (c[0] == c[n - 1])
        {
            k_left = k / 2;
            k_right = k - k_left;
        }
        for(; i < n && left < k_left; i++)
            if(c[i] == c[0]) left++;
        for(; j >= 0 && right < k_right; j--)
            if(c[j] == c[n - 1]) right++;

        if((i - 1) < (j + 1))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}