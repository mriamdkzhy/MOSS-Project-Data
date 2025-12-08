class Solution {
public:
    string finalString(const string &s) {
        string a, b;
        int i = 0;
        while (i < s.size()) {
            char ch = s[i];
            switch (ch == 'i') {
                case true:
                    swap(a, b);
                    break;
                case false:
                    a += ch;
                    break;
            }
            i++;
        }

        return string(rbegin(b), rend(b)) + a;
    }
};
