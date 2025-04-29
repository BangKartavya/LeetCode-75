class Solution {
private:
    vector<vector<int>> result;
    int n;
    int k;

    void solve(int i,int pos, int currSum,vector<int> currPath) {
        if(pos >= k) {
            if(currSum == n) {
                result.push_back(currPath);
            }
            return;
        }

        for(;i<10;i++) {
            if(n-currSum >= i) {
                currPath.push_back(i);
                solve(i+1,pos+1,currSum+i,currPath);
                currPath.pop_back();
            }
            else break;
        }

        return;
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        this->n = n;

        if(n > 45) return result;

        solve(1,0,0,{});

        return result;
    }
};