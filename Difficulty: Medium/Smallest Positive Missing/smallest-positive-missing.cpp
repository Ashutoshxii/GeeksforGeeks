class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        for(int i  = 1 ; i < arr.size()+2 ; i++){
            bool ist = false ; 
            for(int j = 0 ; j < arr.size() ;j++){
                if(arr[j]==i){
                    ist = true ; 
                    break ; 
                }
            }
            if(!ist)return i ;
        }
        return -1 ; 
    }
};