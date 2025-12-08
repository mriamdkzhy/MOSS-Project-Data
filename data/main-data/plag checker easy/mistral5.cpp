#include <iostream>
#include <unordered_set>
#include <vector>

bool containsDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true; // Found a duplicate
        }
        seen.insert(num);
    }
    return false; // No duplicates found
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 1};
    if (containsDuplicate(nums)) {
        std::cout << "The array contains duplicates." << std::endl;
    } else {
        std::cout << "The array does not contain duplicates." << std::endl;
    }
    return 0;
}
