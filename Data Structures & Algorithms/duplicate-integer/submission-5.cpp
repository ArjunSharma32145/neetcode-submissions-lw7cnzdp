class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map <int,int> mpp;
        for(auto num : nums){
            mpp[num]++;
        }
        for(auto it : mpp){
            if(it.second >= 2) return true;
        }
        return false;
    }
};