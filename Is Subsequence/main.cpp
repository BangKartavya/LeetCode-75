class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        if(s.size() == 0) return true;

        for(char& ch: t) {
            if(ch == s[i]) {
                i++;

                if(i == s.size()) return true;
            }
        }

        return false;
    }
};