#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    int t{};
    std::cin >> t;

    while (t--)
    {
        int n{};
        std::cin >> n;

        std::vector<int> v(n); std::set<int> invalidVals{};
        for (auto& x : v) std::cin >> x;

        int val{ 1 };

        for (int i = 0; i < n; i++)
        {
            if (invalidVals.find(v[i]) == invalidVals.end())
            {
                std::cout << v[i] << " ";
                invalidVals.insert(v[i]);
            }
            else
            {
                while (invalidVals.find(val) != invalidVals.end())
                    val++;

                invalidVals.insert(val);
                std::cout << val << " ";
            }
        }

        std::cout << '\n';
    }
}