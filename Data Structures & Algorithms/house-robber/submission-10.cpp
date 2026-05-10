class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[1] = nums[0];  // sirf ek ghar hai
        if(n==1) return dp[1];
        dp[2] = max(nums[0],nums[1]);
        if(n==2) return dp[2];
        for(int i=3;i<=n;i++){
          int loot = nums[i-1] + dp[i-2];
          int notloot = 0 + dp[i-1];
          dp[i] = max(loot,notloot);
        }
        return dp[n];
    }
};
