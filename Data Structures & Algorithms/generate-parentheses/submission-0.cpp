class Solution {
    void solve(int n,int & open,int & close,vector<string> & ans,string & temp){
        if(open == n && close == n){
            ans.push_back(temp);
            return;
        }
       // open lenge
       if(open<n){
       temp += '(';
       open++;
       solve(n,open,close,ans,temp);
       temp.pop_back();
       open--;
       }
       //close lenge
       if(open > close && close < n){
        temp += ')';
        close++;
        solve(n,open,close,ans,temp);
        temp.pop_back();
        close--;
       }

    }
public:
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close =0;
        vector<string> ans;
        string temp;
        solve(n,open,close,ans,temp);
        return ans;
    }
};
