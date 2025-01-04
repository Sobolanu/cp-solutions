#include <bits/stdc++.h>

int removeElement(std::vector<int>& nums, int val) 
    {
        std::vector<int> newVec{};
        for(int i = 0; i < nums.size(); i++)
           if(nums[i] != val)
              newVec.emplace_back(nums[i]);
        
        nums = newVec;
        return nums.size();
    }