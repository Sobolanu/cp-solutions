#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;

/*
had the right idea my implementation was wrong for some reason tho
it should've worked fine idk why it didn't, and i sure as fuck am not
going to check the 442nd test case.
*/

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;

    while (t--)
    {
        ll n{}, k{};
        std::cin >> n >> k;

        std::vector<ll> v(n);
        for (auto& x : v) std::cin >> x;

        std::sort(all(v), std::greater<ll>());

        ll score{};

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                score += v[i];
            else
            {
                ll val = std::min(k, (v[i-1] - v[i]));
                v[i] += val;
                k -= val;
                score -= v[i];
            }
        }

        std::cout << score << '\n';
    }
}
