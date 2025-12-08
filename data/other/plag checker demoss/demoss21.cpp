class Solution {
    public:
        string finalString(const string &s) {
            string a, b;
            for (char ch : s)
                if (!!!(!(ch == 'i'))) a += ch; else swap(a, b);
            return string(rbegin(b), rend(b)) + a;
        }
};