class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        // i have work of key value pair which i cant mimic using array so i will use map
        unordered_map<string,vector<string>> mpp;
        // key mein babaunga sort karke as sab anagrams ka sorted to same hoga na
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
