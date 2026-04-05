class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k= n-1;
            if( i>0 && nums[i-1] == nums[i]) continue;
            while(j<k){
                if(nums[j]+nums[k]== -nums[i]){ result.push_back({nums[i],nums[j],nums[k]});
                 while(j<k && nums[j] ==nums[j+1] ) ++j;
                 ++j;--k;
                }
                  if(nums[j]+nums[k] > -nums[i]) k--;
                    if(nums[j]+nums[k] < -nums[i]) j++;
            }
            
        }
        return result;
    }
};
