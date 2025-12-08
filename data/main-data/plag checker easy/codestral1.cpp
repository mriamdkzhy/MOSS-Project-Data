#include <set>
#include <vector>

bool containsDuplicate(std::vector<int>& nums) {
    std::set<int> s(nums.begin(), nums.end());
    return s.size() < nums.size();
}
