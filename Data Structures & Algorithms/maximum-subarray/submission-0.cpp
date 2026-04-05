class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int maxsum = nums[0];
         int cursum =0;
         for(int i=0;i<nums.size();i++){
            cursum += nums[i];
            maxsum = max(maxsum,cursum);
             cursum = max(cursum,0);
         }
         return maxsum;
    }
};
