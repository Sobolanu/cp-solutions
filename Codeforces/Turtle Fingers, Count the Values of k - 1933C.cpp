#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;

// had to copy paste from GPT due to stupid evil overflow ffs

ull safePow(ull base, ull exp, ull limit)
{
    ull result = 1;
    while (exp > 0)
    {
        if (result > limit / base)
            return std::numeric_limits<ull>::max();

        result *= base;
        exp--;
    }
    return result;
}

std::vector<ull> getFactors(ull l)
{
    std::vector<ull> factors;
    for (ull i = 1; i * i <= l; i++)
    {
        if (l % i == 0)
        {
            factors.push_back(i);
            if (i != l / i)
                factors.push_back(l / i);
        }
    }
    return factors;
}

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    int t;
    std::cin >> t;

    while (t--)
    {
        ull a, b, l;
        std::cin >> a >> b >> l;

        std::vector<ull> v = getFactors(l);
        std::sort(all(v));

        int ans{0};

        for (ull k : v)
        {
            if (l % k != 0)
                continue;

            for (int x = 0; ; x++)
            {
                ull ax = safePow(a, x, l);
                if (ax == std::numeric_limits<ull>::max() || ax > l / k)
                    break;

                for (int y = 0; ; y++)
                {
                    ull by = safePow(b, y, l);
                    if (by == std::numeric_limits<ull>::max() || ax * by > l / k)
                        break;

                    if (ax * by * k == l)
                    {
                        ans++;
                        goto next_factor;
                    }
                }
            }
next_factor:
            ;
        }

        std::cout << ans << '\n';
    }
}