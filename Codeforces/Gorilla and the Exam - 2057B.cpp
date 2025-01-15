#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef unsigned long long ull;

/*
stole from editorial, my intuition was correct about it being
"base state of ans is the num of unique elements, to get minimum value of f(a) we reduce
the number of unique elements", just that my implementation was incorrect.
*/

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;
    while (t--)
    {
        int n{}, k{};
        std::cin >> n >> k;

        std::vector<int> v(n);
        for(auto& x : v) std::cin >> x;

        std::sort(all(v));
        std::vector<int> cnt = {1};
        for (int i = 1; i < n; i++)
        {
            if (v[i] == v[i - 1])
                cnt.back()++;
            else
                cnt.emplace_back(1);
        }
        std::sort(all(cnt));
        int m = cnt.size(); bool chk{false};
        for (int i = 0; i < m - 1; i++)
        {
            if (cnt[i] > k)
            {
                std::cout << m - i << "\n";
                chk = true;
                break;
            }
            k -= cnt[i];
        }
        if(!chk)
           std::cout << 1 << "\n";
    }
}