class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> mpp;
        for(auto num : nums){
            mpp[num]++;
        }
        vector<pair<int,int>> lol;
        for(auto it : mpp){
            lol.push_back({it.second,it.first});
        }
        sort(lol.rbegin(),lol.rend());
        vector<int> result;
       for(int i=0;i<k;i++){
        result.push_back(lol[i].second);
       }
       return result;
    }
};
