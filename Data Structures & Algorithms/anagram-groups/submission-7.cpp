class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> lol;
        for(auto  s : strs){
            string sortedS = s;
            sort(sortedS.begin(),sortedS.end());
            lol[sortedS].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it : lol){
            ans.push_back(it.second);
        }
        return ans;
    }
};
