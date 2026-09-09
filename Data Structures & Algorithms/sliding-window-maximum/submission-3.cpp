class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<k;i++){
            mpp[nums[i]]++;
        }
        ans.push_back(prev(mpp.end())->first);
        int l = 0;
        int j = k;
        while(j < nums.size()){
             mpp[nums[j]]++;
             mpp[nums[l]]--;
             if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
             j++;
             l++;
             ans.push_back(prev(mpp.end())->first);
        }
        return ans;
        
    }
};
