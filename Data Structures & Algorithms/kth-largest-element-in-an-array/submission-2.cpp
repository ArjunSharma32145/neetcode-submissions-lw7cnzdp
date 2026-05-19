class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto it : nums) pq.push(it);
   int lol = k-1;
        while(lol >= 0 && lol--) pq.pop();
        return pq.top();
    }
};
