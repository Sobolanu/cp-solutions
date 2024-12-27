#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;

/*
one of my favorite number theory problems for sure, solved it 100% on my own aswell
tl:dr numbers with the same parity add up to a composite number, only opposite parities can give you a prime
therefore, you can print out first odds then evens however you have to check that the last odd + any even number gives you a composite value
*/

bool isPrime(long long number)
{
    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(long long i=3; (i*i)<=number; i+=2)
        if(number % i == 0 )
            return false;

    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int t{};
    std::cin >> t;

    while (t--)
    {
        int n{};
        std::cin >> n;

        std::vector<int> evens{}, odds{};

        for(int i = 1; i <= n; i++)
        {
            if(i % 2 == 0)
                evens.emplace_back(i);
            else
                odds.emplace_back(i);
        }


        int largestOdd = odds[odds.size() - 1], ans{-1};

        for(int i = 0; i < evens.size(); i++)
        {
            if(!isPrime(largestOdd + evens[i]))
            {
                ans = evens[i];
                break;
            }
        }

        if(ans == -1)
            std::cout << ans;
        else
        {
            for(auto& x : odds)
                std::cout << x << " ";

            std::cout << ans << " ";

            for(auto& x : evens)
            {
                if(x != ans)
                    std::cout << x << " ";
            }
        }

        std::cout << '\n';
    }
}