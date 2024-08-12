class NestedIterator {
public:
    queue<int> q;
    void funcFlatten(vector<NestedInteger> &nestedList)
    {
        int n = nestedList.size();
        for( int i = 0; i<n; i++ )
        {
            NestedInteger obj = nestedList[i];
            if( obj.isInteger() )
            {
                q.push(obj.getInteger());
            }
            else
            {
                funcFlatten(obj.getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        funcFlatten(nestedList);
    }
    
    int next() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};
