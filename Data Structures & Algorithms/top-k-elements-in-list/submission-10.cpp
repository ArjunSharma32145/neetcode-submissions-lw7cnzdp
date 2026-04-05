class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for( auto x : nums) freq[x]++;
        vector<vector<int>> bucket(nums.size()+1);
        for(auto it : freq){
            bucket[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i = bucket.size()-1;i>0;i--){
                for(auto n : bucket[i]){
                    ans.push_back(n);
                    if(ans.size()==k) return ans;
                }
        }
        return ans;
    }
};
