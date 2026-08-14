class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adjlist(n);
        for(int i=0;i<edges.size();i++){
            adjlist[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adjlist[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        vector<double> prob(n,0);
        prob[start_node] = 1;
        pq.push({1,start_node});
        while(!pq.empty()){
            auto node = pq.top().second;
            auto p = pq.top().first;
            pq.pop();
            for(auto it : adjlist[node]){
                if(p*it.second > prob[it.first]){
                    prob[it.first] = p*it.second;
                    pq.push({prob[it.first],it.first});
                }
            }
        }
        return prob[end_node];
    }
};