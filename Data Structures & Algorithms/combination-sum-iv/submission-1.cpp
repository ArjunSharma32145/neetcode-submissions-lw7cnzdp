class Solution {
    vector<int> dp;
    int solve(int sum,int target,vector<int> & nums){
        if(sum == target) return 1;
        if(sum > target) return 0;

        if(dp[sum] != -1) return dp[sum];
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(sum + nums[i] <= target){
             ans += solve(sum+nums[i],target,nums);
            }
        }
        return dp[sum] =  ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1,-1);
        return solve(0,target,nums);
    }
};