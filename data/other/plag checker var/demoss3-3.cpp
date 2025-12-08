class Solution {
    public:
        int minAbsoluteDifference(vector<int>& number, int a) {
            long int answer = INT_MAX;
            set<int> setter;
            for(long int i = a; i < number.size(); ++i){
                setter.insert(number[i-a]);
                auto j = setter.upper_bound(number[i]);
                    if(j != setter.end()) answer = min(answer, abs(number[i] - *j));
                        if(j != setter.begin()) answer = min(answer, abs(number[i] - *prev(j)));
            }
            return answer;
        }
};