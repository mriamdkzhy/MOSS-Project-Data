class Solution {
    public:
        const long int M = 1000000007;
        long int maximumScore(vector<int>& number, int l) {
        long int nums = number.size();
        long int upp = *max_element(number.begin(), number.end()) + 1;
        vector<bool> primary(upp, true);
        primary[0] = primary[1] = false;
        vector<long int> primes(upp, 0);
        for (long int i = 2; i < upp; i++) {
           if (primary[i]) {
                for (int j = i; j < upp; j += i) {
                    primes[j]++;
                    primary[j] = false;
                }
            }
        }
        vector<long int> nextGreaterElement(n, n);
        stack<long int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && primes[number[i]] >= primes[number[s.top()]]) {
                s.pop();
            }
            nextGreaterElement[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        vector<long int> prevGreaterOrEqualElement(n, -1);
        s = stack<int>();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && primes[number[i]] > primes[number[s.top()]]) {
                s.pop();
            }
            prevGreaterOrEqualElement[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        int res = 1;
        vector<pair<long int, long int>> tuples(n);
        for (int i = 0; i < n; i++) {
            tuples[i].first = number[i];
            tuples[i].second = i;
        }        
        sort(tuples.rbegin(), tuples.rend());
        for (const auto& [num, i] : tuples) {
        long int operations = min((i - prevGreaterOrEqualElement[i]) * (nextGreaterElement[i] - i), k);
        res = (long int)((1L * res * pow(num, operations)) % M);
        k -= operations;
            if (k == 0) {
                return res;
            }
        }
        
        return res;
        }
        long int pow(int x, int n) {
            long int res = 1;
               while (n > 0) {
                    if (n % 2 == 1) {
                        res = (long int)((1L * res * x) % M);
                    }
                    x = (long int)((1L * x * x) % M);
                    n /= 2;
                }
            return res;
        }
};