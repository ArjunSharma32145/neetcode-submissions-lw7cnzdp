class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto it : nums) freq[it]++;
        vector<pair<int,int>> st;
        for(auto it : freq){
         st.push_back({it.second,it.first});
        }
       sort(st.rbegin(),st.rend());
       vector<int> ans;
       for(int i=0;i<k;i++){
         ans.push_back(st[i].second);
       }
       return ans;
    }
};
