bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            int n = intervals.size();

            sort(begin(intervals), end(intervals), cmp);
            int nonOver = 0;
            int prevEnd = INT_MIN;

            for(int i = 0; i < n; i++) {
                if(intervals[i][0] >= prevEnd) {
                    nonOver++;
                    prevEnd = intervals[i][1];
                }
            }

            return n - nonOver;
        }
};