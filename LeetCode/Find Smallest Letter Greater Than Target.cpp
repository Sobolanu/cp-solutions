#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;

// essentially binary search but with characters and upper bound

char searchInsert(std::vector<char>& v, char target)
{
    int l{}, r = v.size() - 1;
    char possibleAns{'{'}; // junk value that cannot be reached

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] < target || v[mid] == target)
            l = mid + 1;
        else if(v[mid] > target)
        {
            r = mid - 1;
            if(v[mid] < possibleAns)
               possibleAns = v[mid];
        }
    }
    if(possibleAns == '{')
        return v[0];
    else
        return possibleAns;
}

int main()
{
    std::vector<char> v{'x', 'x', 'y', 'y'};

    std::cout << searchInsert(v, 'z');
}
