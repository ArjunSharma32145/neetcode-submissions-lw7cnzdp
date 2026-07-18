class Solution {
    int solve(int i,int j,vector<vector<int>> & dp,vector<int> & nums){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = 0;
        // if we standing on kth ballon it means we are gonna pop that at last
        for(int k=i;k<=j;k++){
        int cost = nums[i-1]*nums[k]*nums[j+1]  + solve(i,k-1,dp,nums) + solve(k+1,j,dp,nums);
        maxi = max(maxi,cost); 
        }
        return dp[i][j] =  maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
       nums.push_back(1);
       nums.insert(nums.begin(),1);
       int n = nums.size();
       vector<vector<int>> dp(n,vector<int>(n,-1));
       return solve(1,n-2,dp,nums);
    }
};
