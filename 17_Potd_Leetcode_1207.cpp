class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp1;
        unordered_set<int>st;
        for(int i=0;i<arr.size();i++){
            mp1[arr[i]]++;
        }
        for(auto it : mp1){
            if(st.find(it.second)!=st.end())return 0;
            st.insert(it.second);
        }
        return  1;
    }

};
