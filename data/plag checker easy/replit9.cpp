#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    if (containsDuplicate(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}