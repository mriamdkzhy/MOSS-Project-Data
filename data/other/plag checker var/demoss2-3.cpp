class Solution {
    public:
        string finalString(const string &str) {
            string x, y;
            for (char c : str)
                if (c == 'i')
                    swap(x, y);
                else
                    x += c;
            return string(rbegin(y), rend(y)) + x;
        }
};