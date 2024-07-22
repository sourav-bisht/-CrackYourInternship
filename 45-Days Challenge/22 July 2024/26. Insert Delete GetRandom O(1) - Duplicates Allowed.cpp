class RandomizedCollection {
private:
    vector<int> values;
    unordered_map<int,unordered_set<int>> index;
public:
    RandomizedCollection() {
        values.clear();
        index.clear();
    }
    
    bool insert(int val) {
        bool ans = false;
        if( index.find(val) == index.end() )
        {
            ans = true;
        }
        values.push_back(val);
        index[val].insert(values.size()-1);
    return ans;
    }
    
    bool remove(int val) {
        bool ans = false;
        if( index.find(val) != index.end() )
        {
            ans = true;
            auto it = index.find(val);
            int pos = *(it->second.begin());
            it->second.erase(pos);
            values[pos] = values.back();
            index[values.back()].insert(pos);
            index[values.back()].erase(values.size()-1);
            values.pop_back();

            if( it->second.size() == 0 )
            {
                index.erase(it);
            }
        }
    return ans;
    }
    
    int getRandom() {
        int ind = rand() % values.size();
        return values[ind];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
