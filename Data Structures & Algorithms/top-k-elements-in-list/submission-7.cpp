class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto it : nums) freq[it]++;
        vector<pair<int,int>> ans;
        for(auto it : freq){
            ans.push_back({it.second,it.first});
        }
        sort(ans.rbegin(),ans.rend());
        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(ans[i].second);
        }
        return result;
    }
};
