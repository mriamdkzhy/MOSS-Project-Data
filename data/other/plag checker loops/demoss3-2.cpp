class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans = INT_MAX;
        set<int> s;
        int i = x;
        while (i < nums.size()) {
            s.insert(nums[i - x]);
            auto it = s.upper_bound(nums[i]);
            switch (it != s.end()) {
                case true:
                    ans = min(ans, abs(nums[i] - *it));
                    break;
            }
            switch (it != s.begin()) {
                case true:
                    ans = min(ans, abs(nums[i] - *prev(it)));
                    break;
            }
            i++;
        }
        return ans;
    }
};
