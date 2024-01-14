class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>count(26,0);
        vector<int>count2(26,0);
        for(auto ch: word1){
            count[ch-'a']++;
        }
        for(auto ch: word2){
            if(count[ch-'a']==0)return 0;
            count2[ch-'a']++;
        }

        if (count.size() != count2.size()) {
            return false; 
        }
    

    unordered_map<int, int> frequencyMap;

    // Increment frequency for elements in the first vector
    for (int element : count) {
        frequencyMap[element]++;
    }

    // Decrement frequency for elements in the second vector
    for (int element : count2) {
        if (frequencyMap.find(element) == frequencyMap.end()) {
            // Element in count2 not found in count
            return false;
        }

        frequencyMap[element]--;

        if (frequencyMap[element] == 0) {
            frequencyMap.erase(element);
        }
    }

    // If the map is empty, both vectors have the same elements
    return frequencyMap.empty();

        
    }
};


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>count(26,0);
        vector<int>count2(26,0);
        for(auto ch: word1){
            count[ch-'a']++;
        }
        for(auto ch: word2){
            if(count[ch-'a']==0)return 0;
            count2[ch-'a']++;
        }

        if (count.size() != count2.size()) {
            return false; 
        }
    
        sort(count.begin(),count.end());
        sort(count2.begin(),count2.end());
        return count==count2;

        
    }
};
