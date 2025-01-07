#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef unsigned long long ull;

/*
i solved this in a way similar to a difference array but almost like a difference element
instead where i kept track of diff and applied it to the next elements
because why should i update the whole range after I, when i don't care about the next few values and only
care about the next one i get?
*/

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;

    while (t--)
    {
        int n{};
        std::cin >> n;

        std::vector<int> v(n);
        for (auto& x : v) std::cin >> x;

        std::sort(all(v));
        int mx{ INT_MIN }, diff{};

        for (int i = 0; i < n; i++)
        {
            if (v[i] - diff > mx)
                mx = v[i] - diff;
            diff += (v[i] - diff);
        }

        std::cout << mx << '\n';
    }
}