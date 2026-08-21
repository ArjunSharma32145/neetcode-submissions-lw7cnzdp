class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n);
        int p = 0;
        int r = 2;
        while(r--){
            for(int i=0;i<n;i++){
                ans[p] = nums[i];
                p++;
            }
        }
        return ans;
    }
};