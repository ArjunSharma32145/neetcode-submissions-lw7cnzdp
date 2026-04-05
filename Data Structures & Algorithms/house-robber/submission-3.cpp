class Solution {
public:
// go for all possible ways thats why cant go with greedy approach because sometimes some path seems costly at starting but later are rewarding but we will never take the path in greedy approach

    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 =0;
        int curi =0;
        for (int i=1 ;i<n;i++){
       int loot = nums[i] + prev2;
       int notloot  = 0 + prev;
       curi = max(loot,notloot);
       prev2 =prev;
       prev = curi; 
        }
        return prev;
    }
};
