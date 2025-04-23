class Solution {
private:
    vector<vector<int>> adj;
    int n;
    vector<int> vis;
    set<vector<int>> s;
    int answer = 0;

    void dfs(int node) {
        vis[node] = true;

        for(int& it: adj[node]) {
            if(!vis[it]) {
                if(s.find({it,node}) == s.end()) {
                    answer++;
                }
                dfs(it);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        this->n = n;
        adj.resize(n);
        vis.resize(n,false);

        s = set<vector<int>>(begin(connections),end(connections));

        for(vector<int>& connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        dfs(0);

        return answer;

    }
};