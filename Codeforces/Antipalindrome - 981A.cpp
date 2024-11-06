#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

bool isPalindrome(std::string& s)
{
    std::string sSub = s;
    std::reverse(sSub.begin(), sSub.end());

    return (s == sSub) ? true : false;
}

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    std::string s{};
    std::cin >> s;

    if(std::all_of(s.begin(), s.end(), [first = s[0]](char c) { return c == first; }) == true)
        std::cout << 0;
    else if(!isPalindrome(s))
        std::cout << s.length();
    else
        std::cout << s.length() - 1;
}
