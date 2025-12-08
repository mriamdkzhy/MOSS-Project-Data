class Solution {
    public:
        long int maxSum(vector<long int>& vec) {
            long int result = -1, maxim[10] = {};
               for (auto i : vec) {
                    int max_d = 0;
                {
                long int x = i;
                while(x){
                    max_d = max(max_d, x % 10);
                    x /= 10;
                }}
                        if (maxim[max_d])
                            result = max(result, maxim[max_d] + i);
                            maxim[max_d] = max(maxim[max_d], i);
                }
            return result;
        }
};