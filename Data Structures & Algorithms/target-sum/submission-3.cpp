class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum =0;
        int m = nums.size();
        for(auto it : nums) totalsum += it;
        int amount = totalsum - target;
        if(amount <0) return 0;
        if(amount%2 !=0) return 0;
        amount = amount/2;
        vector<vector<int>> dp(m+1,vector<int>(amount+1,0));

        // if your nums is zero then no way right hence zero in case totalways
        // if your amount is zero we have found this path hence one
        for(int j=0;j<=amount;j++) dp[0][j] = 0;
        for(int i=0;i<=m;i++) dp[i][0] = 1;

        for(int i=1;i<=m;i++){
            for(int j=0;j<=amount;j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return  dp[m][amount];

    }
};
