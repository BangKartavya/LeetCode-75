class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int dirX[4] = {0,-1,0,1};
        int dirY[4] = {1,0,-1,0};

        int m = maze.size();
        int n = maze[0].size();

        queue<vector<int>> q;
        q.push({entrance[0],entrance[1],0});
        maze[entrance[0]][entrance[1]] = '+';

        while(!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            int steps = q.front()[2];
            q.pop();
            for(int i = 0;i<4;i++) {
                int newX = x + dirX[i];
                int newY = y + dirY[i];
                

                if((newX < 0 || newX >= m || newY < 0 || newY >= n)) {
                    if(x != entrance[0] || y != entrance[1]) {
                        return steps;
                    }
                    continue;
                }
                

                if(maze[newX][newY] == '.') {
                    q.push({newX,newY,steps+1});
                    maze[newX][newY] = '+';
                }
            }
        }

        return -1;

    }
};