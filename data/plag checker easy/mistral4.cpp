#include <iostream>
#include <unordered_set>
#include <vector>

bool containsDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> seen;

    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;
        }
        seen.insert(num);
    }

    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 1};
    std::cout << std::boolalpha << containsDuplicate(nums) << std::endl; // Output: true

    std::vector<int> nums2 = {1, 2, 3, 4};
    std::cout << std::boolalpha << containsDuplicate(nums2) << std::endl; // Output: false

    return 0;
}
