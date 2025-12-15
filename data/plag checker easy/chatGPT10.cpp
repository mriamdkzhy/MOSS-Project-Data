#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> numSet; // Create a set to track seen numbers
    for (int num : nums) {
        if (numSet.find(num) != numSet.end()) {
            return true; // Duplicate found
        }
        numSet.insert(num); // Insert number into the set
    }
    return false; // No duplicates
}

int main() {
    std::vector<int> nums = {1, 2, 3, 1}; // Example array
    if (containsDuplicate(nums)) {
        std::cout << "The array contains duplicates.\n";
    } else {
        std::cout << "The array does not contain duplicates.\n";
    }
    return 0;
}
