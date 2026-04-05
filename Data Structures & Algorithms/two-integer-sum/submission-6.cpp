class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mpp;
        int complement =0;
        for(int i=0;i<nums.size();i++){
            complement = target - nums[i];
            if(mpp.find(complement) != mpp.end()){
                return {mpp[complement],i};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};
