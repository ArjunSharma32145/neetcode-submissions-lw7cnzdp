class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int k=0;k<n;k++){
            if(k>0 && nums[k-1] == nums[k]) continue;
            int i = k+1;
            int j = n-1;
            while(i<j){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    i++;
                    j--;
                    while(i<j && nums[i-1] == nums[i]) i++;
                    while(i<j && nums[j] == nums[j+1]) j--;
                }
                else if(sum > 0) j--;
                else i++;
            }
        }
        return ans;
    }
};
