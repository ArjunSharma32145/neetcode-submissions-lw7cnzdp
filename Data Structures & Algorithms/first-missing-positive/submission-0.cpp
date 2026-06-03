class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> hashtable(100000,false);
        hashtable[0] = true;
        for(auto it : nums) if(it>0) hashtable[it] = true;
        for(int i=0;i<100000;i++) if(!hashtable[i]) return i;
        return -1;
    }
};