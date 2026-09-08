class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it : nums){
            if(mpp.count(it)) return true;
            mpp[it] = 0;
        }
        return false;
    }
};