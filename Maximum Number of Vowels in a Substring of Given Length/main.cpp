class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a','e','i','o','u'};

        int n = s.size();
        int i = 0;
        int j = k-1;
        int curr = 0;
        int maxi = 0;
        for(int z = i;z<=j;z++) if(vowels.find(s[z]) != vowels.end()) curr++;
        maxi = max(maxi,curr);

        while(j < n) {
            if(vowels.find(s[i]) != vowels.end()) {
                curr--;
            }
            i++;
            j++;

            if(j < n) {
                if(vowels.find(s[j]) != vowels.end()) {
                    curr++;
                }
            }

            maxi = max(maxi,curr);
        }
        return maxi;
    }
};