class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map <int,int> mpp;
        for(auto lol : nums){
            mpp[lol]++;
        }
        for(auto it : mpp){
            if(it.second >=2) return true;
        }
        return false;
    }
};