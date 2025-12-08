#include <iostream>
#include <unordered_set>
#include <vector>

bool containsDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true; // Duplicate found
        }
        seen.insert(num); // Add current number to the set
    }
    
    return false; // No duplicates found
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 1}; // Example input
    
    if (containsDuplicate(nums)) {
        std::cout << "Duplicate exists!" << std::endl;
    } else {
        std::cout << "No duplicates found!" << std::endl;
    }

    return 0;
}
