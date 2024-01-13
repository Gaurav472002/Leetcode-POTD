class Solution {
public:
    int minSteps(string s, string t) {
        int count[26]={0};
        int ans=0;
        for(auto ch:s){
            count[ch-'a']++;
        }
        for(auto ch:t){
            count[ch-'a']--;
            if(count[ch-'a']<0)ans++; // if a character in t makes the count -ve
            // it means t has that character extra so we will have to swap it so we will increment
            // the count.
        }
        return ans;
    }
};
