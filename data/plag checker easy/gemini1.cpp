//Gemini 1.5 Flash
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}