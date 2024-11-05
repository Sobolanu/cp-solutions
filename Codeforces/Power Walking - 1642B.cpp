#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

/*
yoinked from editorial, thought of using a cnt array however
i forgot std::map exists and is way better for this kind of purpose.
10^9 ints is 4GB, which is definitely outside of mem limit

My answer that i didn't know how to implement went like this:
Let X be the number of unique elements,
we would print out X, X times and then we would just +1 for each
recurrence of an element.
*/

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;

    while(t--)
    {
        int n{}, cnt{};
        std::cin >> n;

        std::map<int, int> d{};
        for(int i = 0; i < n; i++)
        {
            int x{};
            std::cin >> x;
            d[x]++;
        }

        for(auto x : d) cnt++;

        for(int k = 1; k <= n; k++) // this type of thing was on my mind!
            std::cout << std::max(k, cnt) << " ";

        std::cout << '\n';
    }
}
