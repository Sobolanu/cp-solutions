#include <bits/stdc++.h>

bool isPerfectSquare(int num) 
    {
        unsigned long long l{}, r = num;

        while(l <= r)
        {
            unsigned long long mid = l + (r - l) / 2;

            if(mid * mid == num)
               return true;
            else if(mid * mid < num)
               l = mid + 1;
            else
               r = mid - 1;
        }

        return false;
    }