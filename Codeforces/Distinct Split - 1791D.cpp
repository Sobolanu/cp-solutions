#include <iostream>
#include <vector>
typedef unsigned long long ull;

/*
Had a similar line of thinking to this, just that my algorithm
was originally O(n^2 + k) however it became O(n^2) by removing
overhead. Overall a cool problem - very useful for teaching me
how to update "prefix" and "suffix" at the same time efficiently.
*/
int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int t{};
    std::cin >> t;

    while(t--)
    {
        int n{}; std::string s{};
        std::cin >> n >> s;

        std::vector<int> cnt(26, 0), p(26, 0);
        for(auto& x : s)
            cnt[x - 'a']++;

        int ans{};
        for(auto& x : s)
        {
            cnt[x - 'a']--;
            p[x - 'a']++;
            int cur{};
            for(int i = 0; i < 26; i++)
                cur += std::min(1, cnt[i]) + std::min(1, p[i]);

            ans = std::max(ans, cur);
        }

        std::cout << ans << '\n';
    }
}