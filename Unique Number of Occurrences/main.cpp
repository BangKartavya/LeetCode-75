class Solution {
    public:
        bool uniqueOccurrences(vector<int>& arr) {
            unordered_map<int, int> mp;

            for(int& i : arr)
                mp[i]++;

            for(auto it : mp) {
                int key = it.first;
                int occ = it.second;

                for(auto it : mp) {
                    if(it.first != key) {
                        if(it.second == occ) return false;
                    }
                }
            }

            return true;
        }
};