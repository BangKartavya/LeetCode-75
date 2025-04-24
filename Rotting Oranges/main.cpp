class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dirX[4] = {0,-1,0,1};
        int dirY[4] = {1,0,-1,0};

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
        }
        int time = -1;
        while(!q.empty()) {
            time++;
            int siz = q.size();
            while(siz--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i=0;i<4;i++) {
                    int newX = x + dirX[i];
                    int newY = y + dirY[i];

                    if(newX < 0 || newX >= m || newY < 0 || newY >= n) continue;

                    if(grid[newX][newY] == 1 && !vis[newX][newY]) {
                        vis[newX][newY] = true;
                        q.push({newX,newY});
                    }
                }
            }
        }

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 1 && !vis[i][j]) return -1;
            }
        }

        return time == -1 ? 0 : time;
    }
};