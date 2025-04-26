class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long result = 0;
        int n = costs.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap2;

        int l = -1;
        int r = -1;

        for(int i = 0;i<candidates;i++) {
            minHeap1.push({costs[i],i});
        }

        if(candidates == n) {
            // eat five star do nothing
        }

        else if((n-candidates-1 <= candidates-1) && candidates < n) {
            // take remaining
            for(int i = candidates;i<n;i++) minHeap2.push({costs[i],i});
        }
        else {
            l = candidates;
            r = n-candidates-1;
            for(int i = n-1;i>n-1-candidates;i--) minHeap2.push({costs[i],i});
        }

        while(k--) {
            if(minHeap1.empty()) {
                result += minHeap2.top().first;
                minHeap2.pop();

                if(l == -1 || r == -1) continue;

                if(r >= l) {
                    minHeap2.push({costs[r],r});
                    r--; 
                }
            }

            else if(minHeap2.empty()) {
                result+= minHeap1.top().first;
                minHeap1.pop();

                if(l == -1 || r == -1) continue;

                if(l <= r) {
                    minHeap1.push({costs[l],l});
                    l++;
                }
            }

            else if(minHeap1.top().first < minHeap2.top().first) {
                result+= minHeap1.top().first;
                minHeap1.pop();

                if(l == -1 || r == -1) continue;

                if(l <= r) {
                    minHeap1.push({costs[l],l});
                    l++;
                }
            }
            else if(minHeap1.top().first > minHeap2.top().first) {
                result += minHeap2.top().first;
                minHeap2.pop();

                if(l == -1 || r == -1) continue;

                if(r >= l) {
                    minHeap2.push({costs[r],r});
                    r--; 
                }
            }
            else {
                if(minHeap1.top().second < minHeap2.top().second) {
                    result+= minHeap1.top().first;
                    minHeap1.pop();

                    if(l == -1 || r == -1) continue;

                    if(l <= r) {
                        minHeap1.push({costs[l],l});
                        l++;
                    }
                }
                else {
                    result += minHeap2.top().first;
                    minHeap2.pop();

                    if(l == -1 || r == -1) continue;
    
                    if(r >= l) {
                        minHeap2.push({costs[r],r});
                        r--; 
                    }
                }
            }
        }

        return result;
    }
};