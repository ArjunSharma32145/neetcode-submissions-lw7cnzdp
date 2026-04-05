class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> mpp;
        for(int i=0;i<k;i++){
            mpp[nums[i]]++;
        }
        ans.push_back(prev(mpp.end())->first);
        int l=0;
        for(int j=k;j<nums.size();j++){
            mpp[nums[l]]--;
            if(mpp[nums[l]]== 0) mpp.erase(nums[l]);
            l++;
            mpp[nums[j]]++;
            ans.push_back(prev(mpp.end())->first);
        }
        return ans;
    }
};
