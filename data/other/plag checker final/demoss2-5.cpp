class Solution {
public:
    string finalString(const string &str) {
        string x;
        string y;
        int i = 0;
        while (i < str.size()) {
            char chr = str[i];
            switch (chr == 'i') {
                case true:
                    swap(x, y);
                    break;
                case false:
                    x += chr;
                    break;
            }
            i++;
        }
        reverse(y.begin(), y.end());
        return string(begin(y), end(y)) + x;
    }
};