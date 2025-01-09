#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef unsigned long long ull;

/*
took from editorial but yeah my failed sol had a similar concept
just that i for some reason chose to divide the array into two parts
instead of just doing this
*/
int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;

    while(t--)
    {
        int n{};
        std::cin >> n;

        std::vector<int> v(n*2);
        for(auto& x : v) std::cin >> x;

        std::sort(all(v));
        std::cout << v[n] - v[n - 1] << '\n';
    }
}