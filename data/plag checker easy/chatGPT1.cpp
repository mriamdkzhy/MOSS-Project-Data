#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> numSet;

    for (int num : nums) {
        // If the number is already in the set, we found a duplicate
        if (numSet.find(num) != numSet.end()) {
            return true;
        }
        // Otherwise, insert the number into the set
        numSet.insert(num);
    }

    // No duplicates found
    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};

    if (containsDuplicate(nums)) {
        std::cout << "Duplicate found!" << std::endl;
    } else {
        std::cout << "No duplicates." << std::endl;
    }

    return 0;
}
