class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adjlist(26);
        int n = words.size();
    for(int i=0;i<n-1;i++){
        string s1 = words[i];
        string s2 = words[i+1];
        if(s1.size() > s2.size() && s1.substr(0,s2.size()) == s2 ) return "";
        int len = min(s1.size(),s2.size());
        for(int ptr=0;ptr<len;ptr++){
            if(s1[ptr] != s2[ptr]){
                adjlist[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }
  vector<bool> present(26,false);
  for(auto word : words){
    for(auto c : word){
        present[c-'a'] = true;
    }
  }
    vector<int> indegree(26,0);
    for(int i=0;i<26;i++){
        for(auto it: adjlist[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<26;i++){
        if(present[i] && indegree[i] == 0 ) q.push(i);
    }
    vector<int> topodic;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topodic.push_back(node);
        for(auto nei : adjlist[node]){
            indegree[nei]--;
            if(indegree[nei] == 0) q.push(nei);
        }
    }
    string aliendic;
    for(auto it : topodic){
        aliendic.push_back(it+'a');
    }
    int presentcount = 0;
    for(int i=0;i<26;i++) if(present[i]) presentcount++;
    if(aliendic.size() != presentcount) return "";
    return aliendic;
    }
};
