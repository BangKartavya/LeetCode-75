class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result(2);
        unordered_set<int> s1;
        unordered_set<int> s2;

        for(int& i: nums1) s1.insert(i);
        for(int& i: nums2) s2.insert(i);

        for(const int& i: s1) {
            if(s2.find(i) == s2.end()) result[0].push_back(i);
        }

        for(const int& i: s2) {
            if(s1.find(i) == s1.end()) result[1].push_back(i);
        }

        return result;
    }
};