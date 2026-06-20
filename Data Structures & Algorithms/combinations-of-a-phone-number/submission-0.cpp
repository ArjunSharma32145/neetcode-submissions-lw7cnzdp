class Solution {
    void solve(int index,string & digits,string & temp,vector<string> & ans,unordered_map<int,string> & mpp){

        if(index == digits.size()){
            ans.push_back(temp);
            return;
        }
        
        for(auto it : mpp[digits[index] - '0']){
           
                temp.push_back(it);
                solve(index+1,digits,temp,ans,mpp);
                temp.pop_back();

        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(!digits.size()) return ans;
        string temp;
        unordered_map<int,string> mpp;
        mpp[2] = "abc";
        mpp[3] = "def";
        mpp[4] = "ghi";
        mpp[5] = "jkl";
        mpp[6] = "mno";
        mpp[7] = "pqrs";
        mpp[8] = "tuv";
        mpp[9] = "wxyz";
        solve(0,digits,temp,ans,mpp);
        return ans;

    }
};
