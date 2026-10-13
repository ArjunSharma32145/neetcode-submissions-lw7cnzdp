class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char,int> f1;
        for(auto it : s1) f1[it]++;
        unordered_map<char,int> f2;
        for(int i=0;i<s1.size();i++){
             f2[s2[i]]++;
        }
        int l = 0;
        if(f1 == f2) return true;
        int j= s1.size();
        while(j<s2.size()){
            f2[s2[l]]--;
            if(f2[s2[l]] == 0) f2.erase(s2[l]);
            l++;
            f2[s2[j]]++;
            j++;
            if(f1 == f2) return true;
        }
        return false;
    }
};
