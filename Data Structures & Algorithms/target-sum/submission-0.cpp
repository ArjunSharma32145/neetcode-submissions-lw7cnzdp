class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = 0;
        for(auto it : nums) totalsum += it;
        if(abs(target) > totalsum || (target + totalsum )%2 != 0) return 0;
        int search = (target + totalsum) /2;
        vector<vector<int>>dp(n+1,vector<int>(search+1));
        // base conditon
        for(int i=0;i<=n;i++){
            for(int j=0;j<=search;j++){
                if(i==0) dp[i][j] = 0;
                if(j==0) dp[i][j] = 1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=search;j++){
                if(nums[i-1] == 0) dp[i][j] = 2*dp[i-1][j];
                else if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][search];
    }
};
