class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // min heap as minimum wale upar rahe aur hatte jaye 
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it : nums){
            pq.push(it);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
