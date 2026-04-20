class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set lol(nums.begin(),nums.end());
        if(lol.size() == nums.size()) return false;
        else return true;
        }
};