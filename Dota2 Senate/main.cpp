class Solution {
public:
    string predictPartyVictory(string s) {
        int n = s.size();
        queue<int> rq;
        queue<int> dq;

        for(int i = 0;i<n;i++) {
            if(s[i] == 'R') rq.push(i);
            else dq.push(i);
        }

        while(!rq.empty() && !dq.empty()) {
            int r = rq.front();
            rq.pop();
            int d = dq.front();
            dq.pop();

            if(r < d) {
                rq.push(r+n);
            }
            else dq.push(d+n);
        }
        return (rq.empty()) ? "Dire" : "Radiant";
    }
};