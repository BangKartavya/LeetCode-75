class StockSpanner {
    private:
        vector<int> stk;

    public:
        StockSpanner() {
            stk.clear();
        }

        int next(int price) {
            if(stk.empty()) {
                stk.push_back(price);
                return 1;
            } else {
                int n = stk.size() - 1;
                int days = 1;
                while(n >= 0 && stk[n] <= price) {
                    n--;
                    days++;
                }
                stk.push_back(price);
                return days;
            }
        }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */