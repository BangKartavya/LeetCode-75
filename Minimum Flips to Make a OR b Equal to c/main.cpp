class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;

        for(int i = 0;i<32;i++) {
            if(((a & (1 << i)) | (b & (1 << i))) == (c & (1 << i))) {
                continue;
            }
            else {
                if(c & (1 << i)) {
                    cnt++;
                }
                else {
                    if((a & (1 << i)) && (b & (1 << i))) {
                        cnt+=2;
                    }
                    else {
                        cnt+=1;
                    }
                }
            }
        }

        return cnt;
    }
};