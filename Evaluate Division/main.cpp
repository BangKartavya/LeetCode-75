class Solution {
    public:
        vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
            int n = equations.size();
            int m = queries.size();

            unordered_map<string, vector<pair<string, double>>> adj;
            unordered_set<string> valid;

            for(int i = 0; i < n; i++) {
                valid.insert(equations[i][0]);
                valid.insert(equations[i][1]);
                adj[equations[i][0]].push_back({equations[i][1], values[i]});
                adj[equations[i][1]].push_back({equations[i][0], (double)1 / (double)values[i]});
            }
            vector<double> result(m, -1);

            for(int i = 0; i < m; i++) {
                string a = queries[i][0];
                string b = queries[i][1];

                if(valid.find(a) == valid.end()) {
                    result[i] = -1.0;
                    continue;
                } else if(valid.find(b) == valid.end()) {
                    result[i] = -1.0;
                    continue;
                }

                queue<pair<string, double>> q;
                q.push({a, 1.0});

                unordered_set<string> vis;
                vis.insert(a);

                while(!q.empty()) {
                    string curr = q.front().first;
                    double val = q.front().second;
                    q.pop();

                    if(curr == b) {
                        result[i] = val;
                        break;
                    }

                    for(pair<string, double>& vp : adj[curr]) {
                        if(vis.find(vp.first) == vis.end()) {
                            vis.insert(vp.first);
                            q.push({vp.first, val * vp.second});
                        }
                    }
                }
            }

            return result;
        }
};