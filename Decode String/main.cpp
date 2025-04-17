class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;

        for(char& ch: s) {
            if(ch != ']') {
                stk.push(ch);
            }
            else {
                string temp;

                while(!stk.empty() && isalpha(stk.top())) {
                    temp += stk.top();
                    stk.pop();
                }
                stk.pop();
                string num;

                while(!stk.empty() && isdigit(stk.top())) {
                    num += stk.top();
                    stk.pop();
                }

                reverse(begin(num),end(num));
                int p = stoi(num);

                for(int i = 0;i<p;i++) {
                    for(int j = temp.size()-1;j>=0;j--) {
                        stk.push(temp[j]);
                    }
                }
            }
        }
        string result;
        result.resize(stk.size());

        while(!stk.empty()) {
            int n = stk.size() -1;
            result[n] = stk.top();
            stk.pop();
        }

        return result;
    }
};