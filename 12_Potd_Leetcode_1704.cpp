--APPROACH 1--
  class Solution {
public:


    unordered_set<int>mp ={'a','e','i','o','u','A','E','I','O','U'};

    bool halvesAreAlike(string s) {
        int n = s.length();
        int i =0;
        int j=n/2;
        int leftcount =0,rightcount=0;
        while(i<n/2  && j<n){
            if(mp.find(s[i])!=mp.end())leftcount++;
            if(mp.find(s[j])!=mp.end())rightcount++;
            i++;
            j++;

        }
        return leftcount==rightcount;
    }
};

--APPROACH 2---
  class Solution {
public:


    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'
        ||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')return 1;
        return 0;
    }

    bool halvesAreAlike(string s) {
        int n = s.length();
        int i =0;
        int j=n/2;
        int leftcount =0,rightcount=0;
        while(i<n/2  && j<n){
            if(isVowel(s[i]))leftcount++;
            if(isVowel(s[j]))rightcount++;
            i++;
            j++;

        }
        return leftcount==rightcount;
    }
};
