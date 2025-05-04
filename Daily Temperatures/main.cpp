class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> result(n);

        for(int i = n-1;i>=0;i--) {
            if(stk.empty()) {
                stk.push(i);
            }
            else {
                while(!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                    stk.pop();
                }

                if(!stk.empty()) {
                    result[i] = (stk.top()-i);
                }
                stk.push(i);
            }
        }

        return result;
    }
};