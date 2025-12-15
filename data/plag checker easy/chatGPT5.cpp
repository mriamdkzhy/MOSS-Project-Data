#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> uniqueElements;
    
    // Iterate through the array
    for (int num : nums) {
        // If the number is already in the set, return true
        if (uniqueElements.find(num) != uniqueElements.end()) {
            return true;
        }
        // Otherwise, insert the number into the set
        uniqueElements.insert(num);
    }
    
    // If no duplicates were found, return false
    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 2};  // Test case
    if (containsDuplicate(nums)) {
        std::cout << "Array contains duplicates." << std::endl;
    } else {
        std::cout << "No duplicates in the array." << std::endl;
    }

    return 0;
}
