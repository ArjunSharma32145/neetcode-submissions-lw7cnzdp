class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int k = i+1;
            int j = n-1;
            while(k<j){
                int sum = nums[i] + nums[k] + nums[j];
                if(sum > 0) j--;
                else if(sum < 0) k++;
                else{
                     ans.push_back({nums[i],nums[k],nums[j]});
                     k++;
                     j--;
                     while(k<j && nums[k] == nums[k-1]) k++;
                     while(k<j && nums[j] == nums[j+1]) j--;
                }
            }
        }
        return ans;
    }
};
