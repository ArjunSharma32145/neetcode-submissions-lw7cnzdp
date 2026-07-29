class FreqStack {
public:
    unordered_map<int,int> mpp;
    vector<int> arr;
    FreqStack() {
        
    }
    
    void push(int val) {
       arr.push_back(val);
       mpp[val]++; 
    }
    
    int pop() {
        int maxfreq = 0;
        for(auto it : mpp) maxfreq = max(maxfreq,it.second);
        int i = arr.size()-1;
        while(mpp[arr[i]] != maxfreq) i--;
        int val = arr[i];
        arr.erase(arr.begin()+ i);
        mpp[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */