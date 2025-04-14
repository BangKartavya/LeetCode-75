class Solution {
    public:
        int largestAltitude(vector<int>& gain) {
            int n = gain.size();
            vector<int> prefix(n + 1, 0);

            for(int i = 0; i < n; i++) {
                prefix[i + 1] = gain[i] + prefix[i];
            }

            return *max_element(begin(prefix), end(prefix));
        }
};