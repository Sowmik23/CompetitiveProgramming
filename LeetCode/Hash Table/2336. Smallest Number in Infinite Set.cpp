class SmallestInfiniteSet {
public:
    set<int> st;
    
    SmallestInfiniteSet() {
        
        for(int i=1;i<=1001;i++){
            st.insert(i);
        }    
    }
    
    int popSmallest() {
        set<int> ::iterator it;
        it = st.begin();
        int x = *it;
        st.erase(it);
        return x;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
