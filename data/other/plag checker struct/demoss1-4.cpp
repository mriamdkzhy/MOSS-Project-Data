class Solution {
    public:
        int maxSum(vector<int>& nums) {
            int res = -1;
            int max_num[10] = {};
               for (int i=0;i<nums.size();i++) {
                    int max_d = 0;
                   for (int v = nums[i]; v; v /= 10)
                        max_d = max(max_d, v % 10);
                        if (max_num[max_d]==true)
                            res = max(res, max_num[max_d] + nums[i]);
                            max_num[max_d] = max(max_num[max_d], nums[i]);
                }
            return res;
        }
};

//changed variables res and maxnum initalisation
//changed first for loop
//changed if statement
