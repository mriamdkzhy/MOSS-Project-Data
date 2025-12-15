#include <set>
#include <vector>

bool containsDuplicate(std::vector<int>& nums) {
    std::set<int> s;
    for(int num : nums) {
        s.insert(num);
    }
    return s.size() < nums.size();
}
