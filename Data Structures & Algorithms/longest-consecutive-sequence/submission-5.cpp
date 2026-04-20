class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> store(nums.begin(),nums.end());
        int ans = 0;
        for(auto num : store){
            if(!store.count(num-1)){
                int streak = 1;
                int check = num+1;
                while(store.count(check)){
                    streak++;
                    check++;
                }
                ans = max(ans,streak);
            }
        }
        return ans;
    }
};
