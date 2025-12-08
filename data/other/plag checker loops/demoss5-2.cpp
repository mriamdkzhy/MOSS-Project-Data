class Solution {
public:
    const int MOD = 1000000007;

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int upper = *max_element(nums.begin(), nums.end()) + 1;
        vector<bool> prime(upper, true);
        prime[0] = prime[1] = false;
        vector<int> primeScore(upper, 0);
        int i = 2;
        while (i < upper) {
            switch (prime[i]) {
                case true: {
                    int j = i;
                    while (j < upper) {
                        primeScore[j]++;
                        prime[j] = false;
                        j += i;
                    }
                } break;
            }
            i++;
        }
        vector<int> nextGreaterElement(n, n);
        stack<int> s;
        i = n - 1;
        while (i >= 0) {
            while (!s.empty() && primeScore[nums[i]] >= primeScore[nums[s.top()]]) {
                s.pop();
            }
            nextGreaterElement[i] = s.empty() ? n : s.top();
            s.push(i);
            i--;
        }
        vector<int> prevGreaterOrEqualElement(n, -1);
        s = stack<int>();
        i = 0;
        while (i < n) {
            while (!s.empty() && primeScore[nums[i]] > primeScore[nums[s.top()]]) {
                s.pop();
            }
            prevGreaterOrEqualElement[i] = s.empty() ? -1 : s.top();
            s.push(i);
            i++;
        }
        int res = 1;
        vector<pair<int, int>> tuples(n);
        i = 0;
        while (i < n) {
            tuples[i].first = nums[i];
            tuples[i].second = i;
            i++;
        }
        sort(tuples.rbegin(), tuples.rend());
        i = 0;
        while (i < n && k > 0) {
            int num = tuples[i].first;
            int idx = tuples[i].second;
            int operations = min((idx - prevGreaterOrEqualElement[idx]) * (nextGreaterElement[idx] - idx), k);
            res = (int)((1L * res * pow(num, operations)) % MOD);
            k -= operations;
            switch (k == 0) {
                case true:
                    return res;
            }
            i++;
        }

        return res;
    }
    int pow(int x, int n) {
        int res = 1;
        while (n > 0) {
            switch (n % 2 == 1) {
                case true:
                    res = (int)((1L * res * x) % MOD);
                    break;
            }
            x = (int)((1L * x * x) % MOD);
            n /= 2;
        }
        return res;
    }
};
