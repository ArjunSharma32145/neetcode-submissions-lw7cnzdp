class MyHashMap {
public:
       vector<int> list1;
       vector<int> list2;
    MyHashMap() : list1(1000001,false) ,list2(1000001,-1) {
        
    }
    
    void put(int key, int value) {
        list1[key] = true;
        list2[key] = value;
    }
    
    int get(int key) {
        return list2[key];
    }
    
    void remove(int key) {
        list1[key] = false;
        list2[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */