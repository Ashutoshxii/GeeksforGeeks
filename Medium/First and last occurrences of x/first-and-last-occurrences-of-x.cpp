//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int> v ;
        if(!binary_search(arr ,arr+n,x)){
            v.push_back(-1) ; 
            v.push_back(-1) ; 
            return v ; 
        }
        int i = 0 ; 
        int j = n -1 ;
        int mid = i + (j-i)/2 ;
        while(i<=j){
            mid = i + (j-i)/2 ;
            if(arr[mid]==x){
                while(arr[mid-1]==arr[mid]){
                    mid-- ; 
                }
                int k = mid ; 
                while(arr[mid+1]==arr[mid]){
                    mid++ ; 
                }
                int l = mid ; 
                v.push_back(k) ; 
                v.push_back(l) ; 
                return v ; 
            }
            else if(arr[mid]>x){
                j = mid-1; 
            }
            else{
                i = mid+1 ;
            }
            
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends