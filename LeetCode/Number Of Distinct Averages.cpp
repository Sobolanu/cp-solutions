#include <bits/stdc++.h>

int distinctAverages(std::vector<int>& nums) {
       std::sort(nums.begin(), nums.end());

int l{}, r = nums.size() - 1;
std::set<double> s{};

while (l <= r)
{
    double avg = (static_cast<double>(nums[l]) + nums[r]) / 2;
    s.insert(avg);

    l++;
    r--;
}
   return s.size();
    }