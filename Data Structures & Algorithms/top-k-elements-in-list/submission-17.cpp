class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> freq;
        for(auto it : nums) freq[it]++;
        // now sort using freq one way store both in pair vector with freq in starting so sorting would do the job
        vector<pair<int,int>> lol;
        for(auto it : freq){
            lol.push_back({it.second,it.first});
        }
        sort(lol.rbegin(),lol.rend());
        for(int i=0;i<k;i++){
            ans.push_back(lol[i].second);
        }
        return ans;
    }
};
