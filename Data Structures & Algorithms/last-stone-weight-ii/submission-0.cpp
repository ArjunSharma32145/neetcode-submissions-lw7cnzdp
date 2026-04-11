class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalsum = 0;
        for(auto it : stones) totalsum += it;
        vector<vector<bool>> dp(n+1,vector<bool>(totalsum+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=totalsum;j++){
                if(i==0) dp[i][j]  = false;
                if(j==0) dp[i][j] = true;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=totalsum;j++){
                if(stones[i-1] <= j){
                    dp[i][j] = dp[i-1][j-stones[i-1]] || dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        int ans = INT_MAX;
        for(int j=totalsum/2;j>=0;j--){
            if(dp[n][j] == true) ans = min(ans,totalsum - 2*j);
        }
        return ans;
    }
};