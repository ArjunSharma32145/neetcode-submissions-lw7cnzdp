class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int l =0;
    KthLargest(int k, vector<int>& nums) {
        l=k;
        for(auto it : nums) pq.push(it);
        while(pq.size() >k) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
     if(pq.size() > l)  pq.pop();
        return pq.top();
    }
};
