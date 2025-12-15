#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> count;
    for (int num : nums) {
        count[num]++;
        if (count[num] > 1) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 3, 4};

    cout << "nums1 contains duplicates: " << containsDuplicate(nums1) << endl;
    cout << "nums2 contains duplicates: " << containsDuplicate(nums2) << endl;

    return 0;
}