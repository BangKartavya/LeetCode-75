class Solution {
    public:
        string reverseVowels(string s) {
            int vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

            vector<char> v;
            int n = s.size();

            for(char& ch : s) {
                if(find(vowels, vowels + 10, ch) != (vowels + 10)) v.push_back(ch);
            }

            int j = v.size() - 1;

            for(int i = 0; i < n; i++) {
                if(find(vowels, vowels + 10, s[i]) != (vowels + 10)) {
                    s[i] = v[j--];
                }
            }

            return s;
        }
};