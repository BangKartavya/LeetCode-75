class Solution {
public:
    int compress(vector<char>& chars) {
        char last = -1;
        int cnt = 0;
        int n = chars.size();

        for(int i = 0;i<n;i++) {
            if(last == -1) {
                last = chars[i];
                chars.push_back(last);
                cnt++;
            }
            else if(last == chars[i]) {
                cnt++;
            }
            else {
                if(cnt == 1) {
                    last = chars[i];
                    chars.push_back(last);
                    cnt = 1;
                    continue;
                }
                int siz = chars.size();
                while(cnt > 0) {
                    chars.push_back(cnt%10+48);
                    cnt /= 10;
                }
                reverse(begin(chars)+siz,end(chars));
                last = chars[i];
                chars.push_back(last);
                cnt = 1;
            }
        }

        if(cnt > 1) {                
            int siz = chars.size();
            while(cnt > 0) {
                chars.push_back(cnt%10+48);
                cnt/=10;
            }                
            reverse(begin(chars)+siz,end(chars));
        }
        
        reverse(begin(chars),end(chars));
        reverse(begin(chars),begin(chars)+chars.size()-n);

        return chars.size()-n;
    }
};