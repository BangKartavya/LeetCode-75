class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            stack<int> stk;

            for(int& ast : asteroids) {
                if(stk.empty())
                    stk.push(ast);
                else {
                    if((stk.top() < 0 && ast < 0) || (stk.top() > 0 && ast > 0) ||
                       (stk.top() < 0 && ast > 0)) {
                        stk.push(ast);
                    } else {
                        if(stk.top() > abs(ast))
                            continue;
                        while(!stk.empty() && stk.top() > 0 &&
                              stk.top() < abs(ast)) {
                            stk.pop();
                        }

                        if(stk.empty()) {
                            stk.push(ast);
                        } else {
                            if(stk.top() < 0) {
                                stk.push(ast);
                            } else {
                                if(stk.top() > 0 && stk.top() == abs(ast)) {
                                    stk.pop();
                                }
                            }
                        }
                    }
                }
            }

            vector<int> result(stk.size());
            while(!stk.empty()) {
                int n = stk.size() - 1;
                result[n] = (stk.top());
                stk.pop();
            }

            return result;
        }
};