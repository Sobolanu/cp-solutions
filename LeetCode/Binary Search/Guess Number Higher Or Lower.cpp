#include <bits/stdc++.h>

int guess(int val)
{
} // function left empty intentionally

int guessNumber(int n) 
 {
     int l{}, r = n;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (guess(mid) == 0)
            return mid;
        if (guess(mid) == 1)
            l = mid + 1;
        else
            r = mid - 1;
    }
    
    return 0;
}