//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int i = 0 ; 
        int j = S.size()-1 ;
        while(i<j){
            swap(S[i],S[j]) ; 
            i++ ;
            j-- ; 
        }
        i = 0 ; 
        j = 0 ;
        int p = 0 ;
        while(i<S.size()-1){
            while(p<S.size()&&S[p]!='.'){
                p++ ; 
            }
            j = p-1 ; 
            while(i<j){
                swap(S[i],S[j]) ; 
                i++ ;
                j-- ;
            }
            p++ ; 
            i = p ;
            j = p ; 
        }
        return S ;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends