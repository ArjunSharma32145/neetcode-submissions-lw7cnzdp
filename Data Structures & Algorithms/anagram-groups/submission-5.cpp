class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(auto s : strs){
            string sorted = s;
            sort(sorted.begin(),sorted.end());
            mpp[sorted].push_back(s);
        }
        vector<vector<string>> result;
        for(auto it : mpp){
            result.push_back(it.second);
        }
        return result;
    }
};
