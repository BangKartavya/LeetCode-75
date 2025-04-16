class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;

        for(char& ch: s) {
            if(ch != '*') stk.push(ch);
            else {
                stk.pop();
            }
        }

        string result;

        while(!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }

        reverse(begin(result),end(result));

        return result;
    }
};