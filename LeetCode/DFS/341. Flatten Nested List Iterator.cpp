// 341. Flatten Nested List Iterator


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> flattenList;
    int n;
    int i = 0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        
        buildFlattenList(nestedList);
        n = flattenList.size();
    }
    
    int next() {
        int val = flattenList.at(i);
        i++;
        return val;   
    }
    
    bool hasNext() {
        return i<n;
    }
private:
    void buildFlattenList(vector<NestedInteger> &nestedList){
        for(auto &lst: nestedList){
            if(lst.isInteger()){
                int x = lst.getInteger();
                flattenList.push_back(x);
            }
            else {
               buildFlattenList(lst.getList());
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */