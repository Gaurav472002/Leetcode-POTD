class Solution {
public:

    vector<int> getNSL(vector<int>&arr,int n){
        vector<int>result(n);
        stack<int>s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                result[i]=-1;
            }
            else{
                while(!s.empty() &&  arr[s.top()]>=arr[i]){
                    s.pop();
                }
                result[i]= s.empty()?-1:s.top();
            }
            s.push(i);
        }
        return result;
    }


       vector<int> getNSR(vector<int>&arr,int n){
        vector<int>result(n);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                result[i]=n;
            }
            else{
                while(!s.empty() &&  arr[s.top()] >arr[i]){
                    s.pop();
                }
                result[i]= s.empty()?n:s.top();
            }
            s.push(i);
        }
        return result;
    }


    int sumSubarrayMins(vector<int>& arr) {
        int n =arr.size();
        vector<int>NSL = getNSL(arr,n);
        vector<int>NSR = getNSR(arr,n);

        long long sum=0;
        int M =1e9+7;

        for(int i=0;i<n;i++){
            long long l =i-NSL[i];
            long long r =NSR[i]-i;

            long long total =l*r;

            long long totalSum = total*arr[i];
            sum= (sum+totalSum)%M;
        }
        return sum;
    }
};
