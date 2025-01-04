#include <bits/stdc++.h>

// no int main func for this

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
    {
        for(int i = 0; i < matrix.size(); i++)
    {
        if(matrix[i][0] <= target && target <= matrix[i][matrix[i].size() - 1])
        {
            int l{}, r = matrix[i].size() - 1;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (matrix[i][mid] == target)
                    return true;
                if (matrix[i][mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
    }

    return false;
    }