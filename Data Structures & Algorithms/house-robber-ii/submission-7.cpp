class Solution {
public:
    int solve(int start,int end,vector<int> & nums){
      int ans = 0;
      int prev = nums[start];
      int prev2 = 0;
      for(int i=start+1;i<end;i++){
        int loot = nums[i] + prev2;
        int notloot = 0 + prev;
        ans = max(loot,notloot);
        prev2= prev;
        prev = ans;
      }
      return ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        //first case
        int ekcase = solve(1,n,nums);
        // second case
        int seccase = solve(0,n-1,nums);
        return max(ekcase,seccase);
    }
};
