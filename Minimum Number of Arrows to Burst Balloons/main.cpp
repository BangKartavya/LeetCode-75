bool cmp(const vector<int>& a , const vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points),end(points),cmp);

        int arrows = 0;
        long long int prevEnd = LONG_MIN;

        for(int i = 0;i<n;i++) {
            if(points[i][0] > prevEnd) {
                arrows++;
                prevEnd = points[i][1];
            }
        }   

        return arrows;
    }
};