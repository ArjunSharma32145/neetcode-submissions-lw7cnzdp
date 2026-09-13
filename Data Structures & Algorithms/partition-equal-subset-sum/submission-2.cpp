class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        for(auto it : nums) totalsum += it;
        if(totalsum%2 != 0) return false;
        int target = totalsum/2;
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        // base case if target zero we reached man
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){

                if(nums[i-1] <= j){
                    dp[i][j] = max(dp[i-1][j] , dp[i-1][j-nums[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target] > 0;

    }
};
