class Solution {
public:
    int minAbsoluteDifference(vector<int>& vec, int a) {
        int answer = INT_MAX;
        set<int> setter;
        int i = a;
        while (i < vec.size()) {
            setter.insert(vec[i - a]);
            auto it = setter.upper_bound(vec[i]);
            switch (it != setter.end()) {
                case true:
                    answer = min(answer, abs(vec[i] - *it));
                    break;
            }
            switch (it != setter.begin()) {
                case true:
                    answer = min(answer, abs(vec[i] - *prev(it)));
                    break;
            }
            i++;
        }
        return answer;
    }
};