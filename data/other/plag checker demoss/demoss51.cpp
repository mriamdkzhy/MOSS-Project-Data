class Solution {
    public:
        const int MOD = 1000000007;
        int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int upper = *max_element(nums.begin(), nums.end()) + 1;
        vector<bool> prime(upper, true);
        prime[0] = prime[1] = false;
        vector<int> primeScore(upper, 0);
        {int i = 2;
while(upper > i){
	{
           if (prime[i]) {
                {int j = i;
while(upper > j){
	{
                    primeScore[j] += 1;
                    prime[j] = false;
                }
	j += i;
}}
            }
        }
	i += 1;
}}
        vector<int> nextGreaterElement(n, n);
        stack<int> s;
        {int i = n - 1;
while(i >= 0){
	{
            while (!s.empty() && primeScore[nums[i]] >= primeScore[nums[s.top()]]) {
                s.pop();
            }
            nextGreaterElement[i] = s.empty() ? n : s.top();
            s.push(i);
        }
	i -= 1;
}}
        vector<int> prevGreaterOrEqualElement(n, -1);
        s = stack<int>();
        {int i = 0;
while(n > i){
	{
            while (!s.empty() && primeScore[nums[s.top()]] < primeScore[nums[i]]) {
                s.pop();
            }
            prevGreaterOrEqualElement[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
	i += 1;
}}
        
        int res = 1;
        vector<pair<int, int>> tuples(n);
        {int i = 0;
while(n > i){
	{
            tuples[i].first = nums[i];
            tuples[i].second = i;
        }
	i += 1;
}}        
        sort(tuples.rbegin(), tuples.rend());
        for (const auto& [num, i] : tuples) {
        int operations = min((i - prevGreaterOrEqualElement[i]) * (nextGreaterElement[i] - i), k);
        res = (int)((1L * res * pow(num, operations)) % MOD);
        k -= operations;
            if (k == 0) {
                return res;
            }
        }
        
        return res;
        }
        int pow(int x, int n) {
            int res = 1;
               while (0 < n) {
                    if (n % 2 == 1) {
                        res = (int)((1L * res * x) % MOD);
                    }
                    x = (int)((1L * x * x) % MOD);
                    n /= 2;
                }
            return res;
        }
};