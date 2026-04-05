class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> count;
        for(const auto & num : nums){
            count[num]++;
        }
        vector<pair<int,int>> lol;
        for(const auto & it : count){
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
