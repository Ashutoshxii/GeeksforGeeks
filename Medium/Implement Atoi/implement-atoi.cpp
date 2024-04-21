//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int k = 0 ; 
        bool n = false ; 
        if(s[0]=='-'){
            n =true ; 
            for(int i = 1 ; i< s.length() ; i++){
            if(s[i]>'9'||s[i]<'0'){
                return -1 ; 
            }
            else{
                k=(k*10)+s[i]-48 ;
            }
        }
        }
        else{
            for(int i = 0 ; i< s.length() ; i++){
            if(s[i]>'9'||s[i]<'0'){
                return -1 ; 
            }
            else{
                k=(k*10)+s[i]-48 ;
            }
        }
        }
        
        if(n==true){
            return -k ; 
        }
        return k ; 
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		int ans=ob.atoi(s);
		cout<<ans<<endl;
	}
}
// } Driver Code Ends