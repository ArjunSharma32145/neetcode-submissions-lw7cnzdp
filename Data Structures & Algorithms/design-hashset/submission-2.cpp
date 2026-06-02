class MyHashSet {
public:
   vector<bool> check;
    MyHashSet() :
        check(1000001,false){}
    
    
    void add(int key) {
        check[key]= true;
    }
    
    void remove(int key) {
        check[key]= false;
    }
    
    bool contains(int key) {
        return check[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */