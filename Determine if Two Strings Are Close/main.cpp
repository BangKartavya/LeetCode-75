class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int freq1[26];
        int freq2[26];

        if(word1.size() != word2.size()) return false;

        memset(freq1,0,sizeof(freq1));
        memset(freq2,0,sizeof(freq2));

        for(char& ch: word1) freq1[ch-'a']++;
        for(char& ch: word2) freq2[ch-'a']++;
    
        bool equal = true;

        for(int i = 0;i<26;i++) {
            if(freq1[i] != freq2[i]) {
                equal = false;
            }

            if((freq1[i] == 0 && freq2[i] != 0) ||(freq1[i] != 0 && freq2[i] == 0)) return false;
        }
        if(equal) return true;

        for(int i = 0;i<26;i++) {
            for(int j = 0;j<26;j++) {
                if(i == j) continue;

                if(freq1[i] == freq2[j]) {
                    swap(freq1[i],freq1[j]);
                }
            }
        }

        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;

        for(int i = 0;i<26;i++) {
            if(freq1[i] && freq2[i]) {
                mp1[freq1[i]]++;
                mp2[freq2[i]]++;
            }
        }

        for(auto it: mp1) {
            if(mp2[it.first] != it.second) return false;
        }

        return true;

    }
};