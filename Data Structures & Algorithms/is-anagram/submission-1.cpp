class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int j=0;
        if(s.size() !=t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[j]){
                return false;
            }
            j++;
        }
        return true;
    }
};
