class Solution {
public:
    int rob(vector<int>& nums) {
      int n = nums.size();
        vector<int> dp(n,-1);
        return func(n-1,dp,nums);
    }
    int func(int index,vector<int> & dp,vector<int> & nums){
      if(index <0) return 0;
      if(dp[index] != -1) return dp[index];
      int loot = nums[index] + func(index-2,dp,nums);
      int notloot = 0 + func(index-1,dp,nums);
      return dp[index] = max(loot,notloot);
    }
};
