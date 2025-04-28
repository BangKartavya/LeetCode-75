class Solution {
    private:
        unordered_map<char, vector<char>> mp;
        vector<string> result;
        string digits;
        int n;

        void solve(int i, string curr) {
            if(i >= n) {
                result.push_back(curr);
                return;
            }

            for(char& it : mp[digits[i]]) {
                curr.push_back(it);
                solve(i + 1, curr);
                curr.pop_back();
            }
            return;
        }

    public:
        vector<string> letterCombinations(string digits) {
            mp['2'] = {'a', 'b', 'c'};
            mp['3'] = {'d', 'e', 'f'};
            mp['4'] = {'g', 'h', 'i'};
            mp['5'] = {'j', 'k', 'l'};
            mp['6'] = {'m', 'n', 'o'};
            mp['7'] = {'p', 'q', 'r', 's'};
            mp['8'] = {'t', 'u', 'v'};
            mp['9'] = {'w', 'x', 'y', 'z'};

            if(digits == "") return result;

            this->digits = digits;
            n = digits.size();

            solve(0, "");

            return result;
        }
};