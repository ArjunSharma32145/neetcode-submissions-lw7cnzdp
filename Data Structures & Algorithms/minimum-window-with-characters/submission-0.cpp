class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        unordered_map<char,int> countT;
        unordered_map<char,int> kitna;
        for(auto it : t) countT[it]++;
        int need = countT.size();
        int have = 0;
        int anslen = INT_MAX;
        int start = 0;
        int l = 0;
        for(int r=0;r<s.size();r++){
             kitna[s[r]]++;
             if(countT.count(s[r]) && kitna[s[r]] == countT[s[r]]){
                have++;
             }
             while(have == need){
                if((r-l+1) < anslen){
                    start = l;
                    anslen = r-l+1;
                }
                kitna[s[l]]--;
                if(countT.count(s[l]) && kitna[s[l]] < countT[s[l]]) have--;
                l++;
             }
        }
        if(anslen == INT_MAX) return "";
        return s.substr(start,anslen);
    }
};
