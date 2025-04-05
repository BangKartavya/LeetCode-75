class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();

        for(int i = 0;i<m;i++) {
            if(flowerbed[i] == 1) {
                if(i-1>=0) {
                    flowerbed[i-1] = INT_MAX;
                }
                if(i+1 < m) {
                    flowerbed[i+1] = INT_MAX;
                }
            }
        }

        int zeros = 0;

        for(int i = 0;i<m;i++) {
            zeros += (flowerbed[i] == 0);
            if(i + 1 < m && flowerbed[i] == 0) flowerbed[i+1] = INT_MAX;
        }

        if(n == 1) return zeros >= 1;
        
        return zeros >= n;
    }
};