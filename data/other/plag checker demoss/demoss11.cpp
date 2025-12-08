class Solution {
    public:
        int maxSum(vector<int>& nums) {
            int res = -1, max_num[10] = {};
               for (auto num : nums) {
                    int max_d = 0;
                   {int v = num;
                while(v){
                    max_d = max(max_d, v % 10);
                    v /= 10;
                }}
                        if (max_num[max_d])
                            res = max(res, max_num[max_d] + num);
                            max_num[max_d] = max(max_num[max_d], num);
                }
            return res;
        }
};