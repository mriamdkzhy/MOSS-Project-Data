class Solution {
public:
    int maxSum(vector<int>& nums) {
        int res = -1, max_num[10] = {};
        int i = 0;
        while (i < nums.size()) {
            int num = nums[i];
            int max_d = 0;
            int v = num;
            while (v) {
                max_d = max(max_d, v % 10);
                v /= 10;
            }
            switch (max_num[max_d] != 0) {
                case true:
                    res = max(res, max_num[max_d] + num);
                case false:
                    max_num[max_d] = max(max_num[max_d], num);
                    break;
            }
            i++;
        }
        return res;
    }
};

