//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    unordered_map<char,int> mpp ; 
	    string st ; 
	    for(int i = 0 ; i < str.length() ; i++){
	        mpp[str[i]]++ ; 
	        if(mpp[str[i]]==1){
	            st.push_back(str[i]) ; 
	        }
	    }
	    return st ;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends