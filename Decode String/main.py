class Solution:
    def decodeString(self, s: str) -> str:
        stk = []

        for ch in s:
            if(ch != ']'):
                stk.append(ch)
            else:
                temp = ""

                while(len(stk) > 0 and stk[-1].isalpha()):
                    temp += stk.pop()
                
                stk.pop()

                num = ""

                while(len(stk) > 0 and stk[-1].isdigit()):
                    num += stk.pop()
                
                p = int(num[::-1])

                for i in range(p):
                    for j in range(len(temp)-1,-1,-1):
                        stk.append(temp[j])
        
        result = ""
        for i in range(len(stk)):
            result += stk[i]
        
        return result

m