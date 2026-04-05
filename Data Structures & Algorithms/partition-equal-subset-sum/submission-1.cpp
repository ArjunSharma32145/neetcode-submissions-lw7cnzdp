class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
      for(const auto & it : nums){
       sum += it;
      }  
      if(sum%2 != 0) return false;
      int target = sum/2;
      int n= nums.size();
      // jo values change hoti hai unki dp banti hai
      vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return balochistan(n-1,target,nums,dp);
    }
private: 
 bool balochistan(int index, int target, vector<int> & alqaeda,
 vector<vector<int>> & dp){
    if( target ==0) return true;
    if(index == 0) return target == alqaeda[index];
    if( dp[index][target] != -1) return dp[index][target];
    bool nottake = balochistan(index-1,target,alqaeda,dp);
    bool take = false;
    if(target >= alqaeda[index]){
        take = balochistan(index-1,target-alqaeda[index],alqaeda,dp);
    }
    return  dp[index][target] = nottake || take;
 }
};
