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
public:
    vector<int> flattenList;
    int currPtr = 0;

    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto integer: nestedList)
            solve(integer);
    }
    
    int next() {
        return flattenList[currPtr++];
    }
    
    bool hasNext() {
        return currPtr < flattenList.size();
    }

    void solve(NestedInteger value) {
        if(value.isInteger())
            flattenList.push_back(value.getInteger());
        else {
            for(auto integer: value.getList())
                solve(integer);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */