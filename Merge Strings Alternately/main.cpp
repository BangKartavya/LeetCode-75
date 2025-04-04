class Solution {
    public:
        string mergeAlternately(string word1, string word2) {
            int n = word1.size();
            int m = word2.size();

            string result;

            for(int i = 0; i < min(n, m); i++) {
                result += word1[i];
                result += word2[i];
            }

            for(int i = min(n, m); i < max(n, m); i++) {
                if(n > m) {
                    result += word1[i];
                } else result += word2[i];
            }

            return result;
        }
};