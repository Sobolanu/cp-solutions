    #include <iostream>
    #include <vector>

    // simple "difference between two elements of an array" problem

    int main()
    {
        std::ios_base::sync_with_stdio(false); std::cin.tie(0);
     
        int t{};
        std::cin >> t;
     
        while(t--)
        {
            int n{};
            std::cin >> n;
     
            std::vector<int> v(n); bool skip{false};
            for(auto& x : v) std::cin >> x;
     
            for(int i = 0; i < n - 1; i++)
            {
                if(std::abs(v[i] - v[i+1]) == 5 || std::abs(v[i] - v[i+1]) == 7)
                    continue;
                else
                {
                    skip = true;
                    std::cout << "NO\n";
                    break;
                }
            }
     
            if(!skip)
                std::cout << "YES\n";
        }
    }