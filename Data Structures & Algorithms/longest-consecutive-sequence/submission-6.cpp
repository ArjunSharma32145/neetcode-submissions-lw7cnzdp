class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> store(nums.begin(),nums.end());
        int ans = 0;
        for(auto lol : store){
            if(store.count(lol-1)) continue;
            int streak = 1;
            int check = lol+1;
            while(store.count(check)){
                streak++;
                check++;
            }
          ans = max(ans,streak);
        }
        return ans;
    }
};
