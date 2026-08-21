class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
      // key should be sorted string that would put all anagrams together as we need key value so hence map
      unordered_map<string,vector<string>> mpp;
      for(auto s : strs){
        string sortedS = s;
        sort(sortedS.begin(),sortedS.end());
        mpp[sortedS].push_back(s);
      }
      for(auto it : mpp){
        ans.push_back(it.second);
      }
      return ans;
    }
};
