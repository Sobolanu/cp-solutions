#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;

bool isBadVersion(int n)
{
    if(n < 4)
        return false;
    else
        return true;
}

int firstBadVersion(int n)
{
        int l{}, r = n;
        int ans{INT_MAX};
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid))
            {
                if(mid < ans)
                   ans = mid;

                r = mid - 1;
            }
            else
               l = mid + 1;
        }

        return ans;
}

int main()
{
    std::cout << firstBadVersion(5);
}