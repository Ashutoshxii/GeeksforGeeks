// User function template for C++
class Solution {
  public:
    bool allZero(vector<int>v){
        for(int &i : v){
            if(i!=0)return false ; 
        }
        return 1 ; 
    }
    int search(string &pat, string &txt) {
        // code here
        vector<int>track(26,0) ; 
        for(char &ch:pat){
            track[ch-'a']++ ; 
        }
        // vector<int>match(26,0) ; 
        int n = txt.size() ; 
        int i = 0 ; int j = 0 ; 
        int k = pat.size() ; 
        int ans = 0 ; 
        while(j < n){
            track[txt[j]-'a']-- ; 
            if(j-i+1==k){
                if(allZero(track))ans++ ; 
                track[txt[i]-'a']++ ;
                i++ ; 
            }
            // track[txt[j]-'a']++ ; 
            j++ ; 
        }
        return ans ; 
    }
};