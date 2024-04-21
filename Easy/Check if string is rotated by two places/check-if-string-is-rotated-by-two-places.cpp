//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        
        if(str1.length()!=str2.length()){
            return 0 ; 
        }
        int n  = str1.length() ; 
        string s1(n,' ') ; 
        string s2(n,' ') ;
        for(int i = 0 ; i < n ; i++){
            s1[i] = str1[(i+2)%n] ; 
        } 
        for(int i = 0 ; i < n ; i++){
            s2[(i+2)%n] = str1[i] ; 
        } 
        if(s1==str2||s2==str2){
            return 1 ; 
        }
        return 0 ; 
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends