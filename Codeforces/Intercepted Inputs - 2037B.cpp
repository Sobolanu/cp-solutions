#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;

// nice little two pointers problem
// finally got bits/stdc++.h to work

void numPair(std::vector<int>& v, int target)
{
    int l{}, r = v.size() - 1;

    while(l <= r)
    {
        int prod = v[l] * v[r];

        if(prod == target)
        {
           std::cout << v[l] << " " << v[r] << '\n';
           return;
        }
        else if(prod < target)
            l++;
        else if(prod > target)
            r--;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;
    while(t--)
    {
        int n{};
        std::cin >> n;
        std::vector<int> v(n);

        for(auto& x : v) std::cin >> x;
        std::sort(all(v));

        numPair(v, n - 2);
    }
}