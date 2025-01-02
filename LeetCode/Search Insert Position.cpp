#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;

// normal bin search but if we don't find the value, then the value should be at position L or R

int searchInsert(std::vector<int>& v, int target)
{
    int l{}, r = v.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] == target)
            return mid;
        if (v[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    std::vector<int> v{1, 3, 5, 6};

    std::cout << searchInsert(v, 5);
}