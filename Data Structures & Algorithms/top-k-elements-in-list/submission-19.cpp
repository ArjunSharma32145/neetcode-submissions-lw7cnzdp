class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // if i want k most frequent elements first i need frequency of every element
        unordered_map<int,int> mpp;
        for(auto it : nums) mpp[it]++;
        // i want top k hence use minheap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it : mpp){
            pq.push({it.second,it.first});
            if(pq.size() >k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
