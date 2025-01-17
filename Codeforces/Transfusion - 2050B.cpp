#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;

/*
neat little problem, similar to a one i did not so long ago (can't remember what it was tho)

tl:dr here, the answer was to see if it is possible to make all elements in the array be equal to the average
modifying the left value would automatically make the right value correct so i only updated the left value

had a WA on test 3 because i used int instead of long long, switched to long long and it worked fine right after.
A general optimization strategy for these kinds of problems is not to update values by one, but rather to derive a
formula that allows you to update a value instantly in O(1) essentially.
*/

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;
    while (t--)
    {
        ll n{}, avg{};
        std::cin >> n;

        std::vector<ll> v(n);
        for (auto& x : v)
        {
            std::cin >> x;
            avg += x;
        }

        avg /= v.size();

        for (int i = 1; i < n - 1; i++)
        {
            if (v[i - 1] > avg)
            {
                ll val = v[i-1] - avg;

                v[i - 1] -= val;
                v[i + 1] += val;
            }
            else if (avg > v[i - 1])
            {
                ll val = avg - v[i-1];
                v[i - 1] += val;
                v[i + 1] -= val;
            }
        }

        if (std::set(all(v)).size() == 1)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}
