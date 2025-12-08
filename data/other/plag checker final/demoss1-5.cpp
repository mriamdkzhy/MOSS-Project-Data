class Solution {
public:
    int maximumSum(vector<int>& vec) {
        int result = -1, maximum[10] = {}, i = 0;
        while (i < vec.size()) {
            int number = vec[i], maxi = 0, j = number;
            while (j == true) {
                maxi = max(maxi, j % 10);
                j /= 10;
            }
            switch (maximum[maxi] != 0) {
                case true:
                    result = max(result, maximum[maxi] + number);
                case false:
                    maximum[maxi] = max(maximum[maxi], number);
                    break;
            }
            i++;
        }
        return result;
    }
};
