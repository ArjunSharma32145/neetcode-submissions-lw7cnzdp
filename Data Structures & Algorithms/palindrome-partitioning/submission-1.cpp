class Solution {
    bool ispalind(string c){
        int n = c.size();
        int i =0;
        int j = n-1;
        while(i<j){
            if(c[i] != c[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int index,string & s,vector<string> & temp,vector<vector<string>> & ans){
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }
        string lol = "";
        for(int i=index;i<s.size();i++){
            lol += s[i];
            if(ispalind(lol)){
                temp.push_back(lol);
                solve(i+1,s,temp,ans);
                temp.pop_back();
            }
            
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,s,temp,ans);
        return ans;
    }
};
