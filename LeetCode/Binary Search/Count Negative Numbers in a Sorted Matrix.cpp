#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;

int countNegatives(std::vector<std::vector<int>>& grid)
    {
       int ans{};
       for (int i = 0; i < grid.size(); i++)
       {
           if (grid[i][0] < 0)
                ans += grid[i].size();
           else
           {
               int l{}, r = grid[i].size() - 1;
               int possibleValue{};
               while (l <= r)
               {
                   int mid = l + (r - l) / 2;

                   if (grid[i][mid] < 0)
                   {
                       if (grid[i].size() - mid > possibleValue)
                           possibleValue = grid[i].size() - mid;
                       r = mid - 1;
                   }
                   else if (grid[i][mid] >= 0)
                       l = mid + 1;
               }
               ans += possibleValue;
           }
       }

       return ans;
   }

int main()
{
    std::vector<std::vector<int>> grid{{1, -2, -3, -4}};

    std::cout << countNegatives(grid);
}