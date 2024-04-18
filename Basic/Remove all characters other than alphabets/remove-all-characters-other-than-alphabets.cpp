//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string removeSpecialCharacter(string S) {
        // code here
        for(int i = 0 ; i < S.length() ; i++){
	        if(S[i]>='a'&&S[i]<='z'||S[i]>='A'&&S[i]<='Z'){
	           continue; 
	        }
	        else{
	            S.erase(S.begin()+i);
	            i-- ;
	        }
	    }
	    if(S.empty()){
	        S = "-1" ; 
	    }
	    return S ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.removeSpecialCharacter(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends