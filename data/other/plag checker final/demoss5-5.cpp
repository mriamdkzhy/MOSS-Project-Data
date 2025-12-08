class Solution {
public:
    const int M = 1000000007;
    int pow(int a, int b) {
        int result = 1;
        while (b > 0) {
            switch (b % 2 == 1) {
                case true:
                    result = (int)((1L * result * a) % M);
                    break;
            }
            a = (int)((1L * a * a) % M);
            b = b/2;
        }
        return result;
    }
    int maximumScore(vector<int>& number, int crayon) {
        int num = number.size(), up = *max_element(number.begin(), number.end()) + 1, i = 2;;
        vector<bool> prime(up, true);
        prime[0] = prime[1] = false;
        vector<int> primeScore(up, 0);
        while (i < up) {
            switch (prime[i]) {
                case true: {
                    int j = i;
                    while (j < up) {
                        primeScore[j]++;
                        prime[j] = false;
                        j += i;
                    }
                } break;
            }
            i = i+1;
        }
        vector<int> nextGreaterElement(num, num);
        stack<int> s;
        i = num - 1;
        while (i >= 0) {
            while (!s.empty() && primeScore[number[i]] >= primeScore[number[s.top()]]) {
                s.pop();
            }
            nextGreaterElement[i] = s.empty() ? num : s.top();
            s.push(i);
            i = i-1;
        }
        vector<int> prevGreaterOrEqualElement(num, -1);
        s = stack<int>();
        i = 0;
        while (i < num) {
            while (!s.empty() && primeScore[number[i]] > primeScore[number[s.top()]]) {
                s.pop();
            }
            prevGreaterOrEqualElement[i] = s.empty() ? -1 : s.top();
            s.push(i);
            i = i+1;
        }
        int res = 1;
        vector<pair<int, int>> tuples(num);
        i = 0;
        while (i < num) {
            tuples[i].first = number[i];
            tuples[i].second = i;
            i = i+1;
        }
        sort(tuples.rbegin(), tuples.rend());
        i = 0;
        while (i < num && crayon > 0) {
            int num = tuples[i].first, idx = tuples[i].second;
            int operations = min((idx - prevGreaterOrEqualElement[idx]) * (nextGreaterElement[idx] - idx), crayon);
            res = (int)((1L * res * pow(num, operations)) % M);
            crayon = crayon - operations;
            switch (crayon == 0) {
                case true:
                    return res;
            }
            i = i+1;
        }
        return res;
    }
};