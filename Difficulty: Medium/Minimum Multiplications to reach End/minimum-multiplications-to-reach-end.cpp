// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod = 100000  ; 
        vector<int>steps(mod,INT_MAX) ; 
        queue<int>q ; 
        q.push(start) ; 
        int step = 0 ; 
        steps[start] = 0 ; 
        while(!q.empty()){
            int size = q.size() ;
            step++ ; 
            while(size--){
                int num = q.front() ; 
                q.pop() ; 
                // if(num==end)return step-1 ; 
                for(int &i:arr){
                    int x = (num*i)%mod ; 
                    if(steps[x]>step){
                        steps[x] = step ;  
                        q.push(x) ; 
                    }
                }
            }
        }
        if(steps[end]==INT_MAX)return -1 ;
        return steps[end] ; 
        return -1 ; 
    }
};
