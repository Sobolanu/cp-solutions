#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;

/*
took some code from editorial but overall most of my code was correct
i had the fundamental idea down (iterate through array until AND becomes zero, update value if AND became zero)
but didn't update the answer after finishing the array iterations.
Overall pretty happy given it's my first time working with bitwise operators.
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
        for(auto& x : v) std::cin >> x;

        int val = v[0], ans{1};
        for(int i = 0; i < n; i++)
        {
            val &= v[i];
            if(val == 0)
            {
                if(i == n-1)
                    break;

                ans++;
                val = v[i+1];
            }
        }
        if(val != 0)
            ans--;

        std::cout << std::max(ans, 1) << '\n';
    }
}
