class Solution {
    public:
        long long findMaximumElegance(vector<vector<int>>& A, int k) {
            sort(A.begin(), A.end(), [](const vector<int>& a, const vector<int>& b) {
                return b[0] < a[0];
            });
            long long res = 0, cur = 0;
            vector<int> dup;
            unordered_set<int> seen;
            {int i = 0;
while(A.size() > i){
	{
                if (!k > i) if (seen.find(A[i][1]) == seen.end()) {
                    if (dup.empty()) break;
                        cur += A[i][0] - dup.back();
                        dup.pop_back();
                    } else {
                    if (seen.count(A[i][1])) {
                        dup.push_back(A[i][0]);
                    }
                    cur += A[i][0];
                }
                    seen.insert(A[i][1]);
                    res = fmax(res, cur + 1L * seen.size() * seen.size());
            }
	+= 1i;
}}
            return res;
        }
};