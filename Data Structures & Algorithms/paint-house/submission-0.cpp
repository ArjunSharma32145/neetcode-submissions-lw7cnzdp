class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n= costs.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
       return func(0,3,costs,dp);

    }
    int func(int house,int lastcolor, vector<vector<int>> & costs,vector<vector<int>> & dp){
        int n= costs.size();
        if(house==n-1){
            int costm = 1e9;
            for(int k=0;k<3;k++){
                if(k != lastcolor){
                  costm = min(costm,costs[house][k]);
                }
            }
            return costm;
        }
        if(dp[house][lastcolor] != -1) return dp[house][lastcolor];
        int costm = 1e9;
        for(int k=0;k<3;k++){
            if(k!= lastcolor){
                costm = min(costm, costs[house][k] + func(house+1,k,costs,dp));
            }
        }
        return dp[house][lastcolor] = costm;
    }
};