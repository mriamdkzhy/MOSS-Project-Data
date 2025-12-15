#include <unordered_set>
#include <vector>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> num_set;
    
    for (int num : nums) {
        if (num_set.find(num) != num_set.end()) {
            return true;
        }
        num_set.insert(num);
    }
    
    return false;
}