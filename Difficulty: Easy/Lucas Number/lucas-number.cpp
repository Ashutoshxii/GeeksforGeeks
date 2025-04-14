//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        long long lucas(int n)
        {
            //code here.
            if(n==0)return 2 ; 
            if(n==1)return 1 ;
            long long mod = 1000000007;
            long long a = 2 ;
            long long b = 1 ; 
            long long ans = 0 ; 
            for(int i = 2 ; i <= n ; i++){
                 ans = (a + b)%mod ; 
                 a = b ;  
                 b = ans ; 
            }
            return ans ; 
    
        }
        
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		cout<<ob.lucas(n)<<endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends