class Solution {
  int solve(int start,int end,vector<int> & nums){
    // no house so no profit
    int prev2 = 0;
    int prev  = nums[start];
    int curr = prev;
    for(int i=start+1;i<=end;i++){
      int loot = nums[i] + prev2;
      int notloot=  0 + prev;
      curr = max(loot,notloot);
      prev2 = prev;
      prev= curr;
    }
    return curr;
  }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1 ) return nums[0];
return max(solve(0,n-2,nums),solve(1,n-1,nums));
    }
};
