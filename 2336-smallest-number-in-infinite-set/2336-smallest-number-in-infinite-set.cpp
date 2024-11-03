class SmallestInfiniteSet {
public:
    
    int ptr = 1;
    vector<bool> arr;

    SmallestInfiniteSet() {
        arr.assign(1001,true);
    }
    
    int popSmallest() {
       while(!arr[ptr]) ptr++;
       arr[ptr] = false;
       ptr++;
       return ptr-1; 
    } 
    
    void addBack(int num) {
       arr[num] = true; 
       if( ptr >= num) ptr = num; 
    }
};


/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */