class Solution {
    private:
        vector<vector<int>> adj;
        int n;
        vector<bool> vis;
        int result = 0;

        void dfs(int node) {
            vis[node] = true;

            for(int& it : adj[node])
                if(!vis[it]) dfs(it);
        }

    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            n = isConnected.size();
            adj.resize(n);
            vis.resize(n);
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(isConnected[i][j]) {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }

            for(int i = 0; i < n; i++) {
                if(!vis[i]) {
                    dfs(i);
                    result++;
                }
            }

            return result;
        }
};