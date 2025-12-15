#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> seen;  // to store the unique elements
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;  // duplicate found
        }
        seen.insert(num);
    }
    return false;  // no duplicates
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 1}; // Example array
    if (containsDuplicate(nums)) {
        std::cout << "Contains duplicates" << std::endl;
    } else {
        std::cout << "No duplicates" << std::endl;
    }
    return 0;
}
