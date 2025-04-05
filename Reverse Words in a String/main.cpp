class Solution {
public:
    string reverseWords(string s) {
        string result;
        int n = s.size();

        while(n-1 >= 0 && !isalnum(s[n-1])) n--;

        for(int i = 0;i<n;i++) {
            while(i < n && !isalnum(s[i])) {
                i++;
            }

            int start = i;
            while(i < n && isalnum(s[i])) {
                i++;
            }


            string temp = s.substr(start,i-start);
    
            result = temp + " " + result;
        }

        cout << result << endl;

        return result.substr(0,result.size()-1);
    }
};