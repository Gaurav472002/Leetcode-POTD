class RandomizedSet {
public:
    vector<int>ans;
    unordered_map<int,int>indexMap;
    RandomizedSet() {
        
        
    }
    
    bool insert(int val) {
        if(indexMap.find(val)!=indexMap.end())return 0;
        ans.push_back(val);
        indexMap[val]=ans.size()-1;
        return 1;
    }
    
    bool remove(int val) {
        
        if(indexMap.find(val)==indexMap.end())return 0;

        int lastElement = ans.back();
        int index = indexMap[val]; // find the index of the element to be deleted
        
        ans.back()=val;
        ans[index]=lastElement;
       
        indexMap[lastElement]=index;
        ans.pop_back();
        indexMap.erase(val);
        return 1;

    }
    
    int getRandom() {
        
        int idx = rand()%ans.size();
        return  ans[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
