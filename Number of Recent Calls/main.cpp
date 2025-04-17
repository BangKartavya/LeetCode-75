class RecentCounter {
private:
    vector<int> req;


    int binarySearch(int val, bool lower) {
        int s = 0;
        int e = req.size()-1;

        if(req[s] >= val) return s;
        if(req[e] <= val) return e;

        while(s <= e) {
            int mid = s + (e-s)/2;

            if(lower) {
                if(req[mid] > val) {
                    e = mid-1;
                }
                else if(req[mid] == val) return mid;
                else {
                    s = mid+1;
                }
            }
            else {
                if(req[mid] < val) {
                    s = mid+1;
                }
                else if(req[mid] > val) {
                    e = mid-1;
                }
                else return mid;
            }
        }

        return s;
    }

public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        req.push_back(t);

        int lb = binarySearch(t-3000,true);
        int ub = binarySearch(t,false);

        return ub-lb+1;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */