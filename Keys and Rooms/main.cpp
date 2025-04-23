class Solution {
private:
    vector<vector<int>> rooms;
    int n;
    vector<bool> vis;
    int room = 1;

    void dfs(int i) {
        vis[i] = true;

        for(int& it: rooms[i]) {
            if(!vis[it]) {
                room++;
                dfs(it);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        this->rooms = rooms;
        n = rooms.size();
        vis.resize(n,false);

        dfs(0);

        return room==n;
    }
};