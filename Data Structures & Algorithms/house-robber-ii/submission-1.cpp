class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        int ans1 =0;
        int ans2 =0;
        int prev =nums[0];
        int prev2 = 0;
        // last wala nahi lenge
        for(int i=1;i<n-1;i++){
            int loot = nums[i] + prev2;
            int notloot = 0 + prev;
            ans1 = max(loot,notloot);
            prev2 =prev;
            prev = ans1;
        }
        ans1 = prev;
        prev=nums[1];
        prev2=0;
          for(int i=2;i<n;i++){
            int loot = nums[i] + prev2;
            int notloot = 0 + prev;
            ans2 = max(loot,notloot);
            prev2 =prev;
            prev = ans2;
        }
        ans2 = prev;
        return max(ans1,ans2);

    }

};
