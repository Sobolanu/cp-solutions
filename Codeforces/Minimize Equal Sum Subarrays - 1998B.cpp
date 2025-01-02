    #include <bits/stdc++.h>
    #define all(x) x.begin(), x.end()
     
    typedef unsigned long long ull;
     
    int main()
    {
        std::ios::sync_with_stdio(false); std::cin.tie(0);
     
        int t{};
        std::cin >> t;
        while(t--)
        {
            int n{};
            std::cin >> n;
     
            std::vector<int> v(n);
            for(auto& x : v) std::cin >> x;
     
            for(int i = 1; i < n; i++)
                std::cout << v[i] << " ";
     
            std::cout << v[0] << '\n';
        }
    }