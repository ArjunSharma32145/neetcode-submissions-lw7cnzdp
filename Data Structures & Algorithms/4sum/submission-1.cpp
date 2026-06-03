class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int l=0;l<n;l++){
            if(l>0 && nums[l-1] == nums[l]) continue;
            for(int k=l+1;k<n;k++){
                if(k>l+1 && nums[k-1] == nums[k]) continue;
                int i = k+1;
                int j=n-1;
                while(i<j){
                    long long sum = (long long)nums[l] + nums[k]+nums[i]+ nums[j];
                    if(sum == target){
                        ans.push_back({nums[l],nums[k],nums[i],nums[j]});
                        i++;
                        j--;
                        while(i<j && nums[i-1] == nums[i]) i++;
                        while(i<j && nums[j+1] == nums[j]) j--;
                    }
                    else if(sum > target) j--;
                    else i++;
                }
            }
         
        }
           return ans;
    }
};