class Solution {
    public:
        string finalString(const string &s) {
            string a;
            string b;
            for (int i=0;i<s.length();i++)
                if (s[i] == 'i')
                    swap(a, b);
                else
                    a += s[i];
            reverse(b.begin(),b.end());
            return string(begin(b), end(b)) + a;
        }
};

//string initalisation
//changed for loop inside brackets
//implemented reverse function and fixed return.
