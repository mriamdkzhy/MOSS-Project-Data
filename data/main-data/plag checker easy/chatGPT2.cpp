#include <iostream>
#include <unordered_set>
#include <vector>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> seen;
    
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;  // Duplicate found
        }
        seen.insert(num);
    }
    
    return false;  // No duplicates
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 2};  // Example array
    if (containsDuplicate(nums)) {
        std::cout << "Duplicate found!" << std::endl;
    } else {
        std::cout << "No duplicates!" << std::endl;
    }
    
    return 0;
}
