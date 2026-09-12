class KthLargest {
public: 
// as we have to find  largest use min heap 
priority_queue<int,vector<int>,greater<int>> pq;
int l = 0;
    KthLargest(int k, vector<int>& nums) {
        l = k;
        for(auto it : nums){
            pq.push(it);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > l) pq.pop();
        return pq.top();
    }
};
