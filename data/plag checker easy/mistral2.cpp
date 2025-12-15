#include <iostream>
#include <vector>
#include <unordered_set>

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
    std::vector<int> nums = {1, 2, 3, 4, 5};
    if (containsDuplicate(nums)) {
        std::cout << "The array contains duplicates." << std::endl;
    } else {
        std::cout << "The array does not contain duplicates." << std::endl;
    }

    std::vector<int> nums2 = {1, 2, 3, 4, 5, 1};
    if (containsDuplicate(nums2)) {
        std::cout << "The array contains duplicates." << std::endl;
    } else {
        std::cout << "The array does not contain duplicates." << std::endl;
    }

    return 0;
}
