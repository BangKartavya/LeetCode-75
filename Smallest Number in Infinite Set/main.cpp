class SmallestInfiniteSet {
private:
    unordered_set<int> s;
    priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    SmallestInfiniteSet() {
        for(int i = 1;i<=1000;i++) {
            minHeap.push(i);
        }
    }
    
    int popSmallest() {

        int val = minHeap.top();
        minHeap.pop();
        s.insert(val);

        return val;
    }
    
    void addBack(int num) {
        if(s.find(num) != s.end()) {
            minHeap.push(num);
            s.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */