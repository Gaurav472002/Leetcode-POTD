class Solution {
public:
        
       
        unordered_map<string,int>mp;
     // function to check if two strings has duplicate or not
    bool duplicate(string s1 , string s2){

            int count[26]={0};
            for(auto s: s1){
                if(count[s-'a']>0)return 1 ; // check for same chars

                count[s-'a']++;
            }
            for(auto s:s2){
                if(count[s-'a']>0)return 1;
            }
            return 0;
    }

    int solve(vector<string>&arr,string temp,int i,int n){

                if(i>=n){
                    return temp.size();
                }
                
                if(mp.find(temp)!=mp.end())return mp[temp];

                int exclude=0;
                int include=0;
                if(duplicate(arr[i],temp)){
                    exclude = solve(arr,temp,i+1,n);
                }
                else{
                    exclude = solve(arr,temp,i+1,n);
                    include = solve(arr,temp+arr[i],i+1,n);
                }
                return mp[temp]=max(include,exclude);
    }


    int maxLength(vector<string>& arr) {
        string temp="";
        int i=0;
        int n=arr.size();
        mp.clear();
        return solve(arr,temp,i,n);
        
    }
};
