class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int i=0;
        for(auto it : nums){
            int complement = target - it;
            if(mpp.find(complement) != mpp.end()) return {mpp[complement],i};
            mpp[it] = i;
            i++;
        }
        return {};
    }
};
