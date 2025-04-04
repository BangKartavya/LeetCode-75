class Solution {
    public:
        vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
            int n = candies.size();
            vector<bool> result(n, false);

            int maxi = *max_element(begin(candies), end(candies));

            for(int i = 0; i < n; i++) {
                result[i] = (candies[i] + extraCandies) >= maxi;
            }

            return result;
        }
};