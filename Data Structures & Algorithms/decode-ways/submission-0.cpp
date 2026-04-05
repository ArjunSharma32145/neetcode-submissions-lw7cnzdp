class Solution {
public:
    int numDecodings(string s) {
       return lol(0,s);
    }
    int lol(int  i,string & s){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        // first case ek hi lenge
        int res = lol(i+1,s);
        // second case do lenge uske conditions
        if(i<s.size()-1){
            if(s[i]=='1' || s[i]=='2' && s[i+1] <'7') res += lol(i+2,s);
        }
        return res;
    }
 
};
