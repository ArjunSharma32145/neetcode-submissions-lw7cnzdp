class Solution {
    int solve(int index,int prev_index,vector<vector<int>> & dp,vector<int> & nums){
        if(index == nums.size()) return 0;
        if(dp[index][prev_index+1] != -1) return dp[index][prev_index+1];
        //take
        int take = 0;
        if(prev_index == -1 || nums[index] > nums[prev_index]){
            take = 1 + solve(index+1,index,dp,nums);
        }
        int not_take = 0 + solve(index+1,prev_index,dp,nums);
        return  dp[index][prev_index+1] =  max(take,not_take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,dp,nums);
    }
};
