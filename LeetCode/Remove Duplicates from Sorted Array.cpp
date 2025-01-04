#include <bits/stdc++.h>

int removeDuplicates(std::vector<int>& nums) 
    {
        std::set<int> vals{};
        for(int i = 0; i < nums.size(); i++)
            vals.insert(nums[i]);

        nums = std::vector<int>(vals.begin(), vals.end());
        return vals.size();
    }