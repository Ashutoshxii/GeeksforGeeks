//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string modify (string S)
    {
        //code here.
        for(int i = 0 ; i < S.length() ; i++){
	        if(S[i]==' '){
	            S.erase(S.begin()+i);
	            i-- ; 
	        }
	    }
	    return S ; 
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore ();
    while (t--)
    {
        string s;
        getline (cin, s);
        Solution ob;
        cout <<ob.modify (s) << endl;
    }
    return 0;
}


// } Driver Code Ends