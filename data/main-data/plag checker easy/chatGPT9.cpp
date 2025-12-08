#include <iostream>
#include <unordered_set>
#include <vector>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) {
            return true; // Duplicate found
        }
        seen.insert(num);
    }
    return false; // No duplicates
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 1}; // Example input
    if (containsDuplicate(nums)) {
        std::cout << "True" << std::endl; // Duplicates exist
    } else {
        std::cout << "False" << std::endl; // No duplicates
    }
    return 0;
}
