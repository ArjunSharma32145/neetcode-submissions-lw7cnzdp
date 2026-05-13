class RandomizedSet {
public:
    unordered_set<int> st;
    vector<int> vec;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!st.count(val)){
            st.insert(val);
            vec.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(st.count(val)){
            st.erase(val);
            auto it = find(vec.begin(),vec.end(),val);
            *it = vec.back();
            vec.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int n = vec.size();
        int i = rand()%n;
        return vec[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */