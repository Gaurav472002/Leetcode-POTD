class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        for(int &num: nums){
            mp[num]++;
        }

        int ans=0;

        for(auto it: mp){
            
            int freq =it.second;
            if(freq==1){
                return -1;
            }
            ans+= ceil((double)freq/3);
        }
        return ans;
    }
};

/* we greedily want to delete the element in the second way i.e three elements in one go to reduce the number of operations. In order to do this we will store the frequency of each element and then add the ceil value of freq / 3 in order to get the result.

If frequency of element = 
1 ----> -1
2------> 2/3 =0 ceil value =1  we can delete both element in one go
3------> 3/3 =1 ceil value =1  we can delete both element in one go
4------> 4/3 =1.33 ceil value =2  we can delete 4 element in two  pairs
5------> 5/3 =1.66 ceil value =2  we can delete 5 element in two go first 3elements and then 2 elements
6------> 6/3 =2 ceil value =2  we can delete in two go first 3 elements and then 3 elements
7------> 7/3 =2.33 ceil value =3  we can delete 7 element in 3 go 3 +2 +2 */
