class Solution {
    private:
        vector<int> piles;
        int n;
        int h;

        bool isValid(int speed) {
            long long int time = 0;

            for(int i = 0; i < n; i++) {
                time += ceil((double)piles[i] / double(speed));
            }

            return time <= h;
        }

    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            this->piles = piles;
            n = piles.size();
            this->h = h;

            int s = 1;
            int e = *max_element(begin(piles), end(piles));
            int ans = 0;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                if(isValid(mid)) {
                    ans = mid;
                    e = mid - 1;
                } else s = mid + 1;
            }

            return ans;
        }
};