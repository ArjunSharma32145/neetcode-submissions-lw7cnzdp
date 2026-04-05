class Solution {
public:
    int rob(vector<int>& nums) {
      int n = nums.size();
        vector<int> dp(n,-1);
        return func(0,nums,dp);
    }
    int func(int index,vector<int> & nums,vector<int> & dp){
      if(index >= nums.size()) return 0;
      if(dp[index] != -1) return dp[index];
      int loot = nums[index] + func(index+2,nums,dp);
      int notloot = 0 + func(index+1,nums,dp);
      return dp[index] = max(loot,notloot);
    }
};
