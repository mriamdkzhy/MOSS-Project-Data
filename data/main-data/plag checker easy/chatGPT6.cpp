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
        // Insert the number into the set
        numSet.insert(num);
    }
    
    // No duplicates found
    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 1}; // Change this array to test different inputs
    if (containsDuplicate(nums)) {
        std::cout << "Array contains duplicates.\n";
    } else {
        std::cout << "Array does not contain duplicates.\n";
    }
    
    return 0;
}
