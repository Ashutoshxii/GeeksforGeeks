//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        long long i = 0 ; 
        long long j =  v.size() - 1   ; 
        
        long long mid = i + (j-i)/2 ; 
        if(!binary_search(v.begin(),v.end(),x)){
             pair<int,int> p = make_pair(-1,-1) ; 
             return p ;
        }
        while(i <= j ){
            mid = i + (j-i)/2 ; 
            if(v[mid]==x){
                while(mid>=0&&v[mid-1]==v[mid]){
                    mid-- ;
                }
                int k = mid ; 
                while(mid<v.size()-1&&v[mid]==v[mid+1]){
                    mid++ ;
                }
                int l = mid ; 
                pair<int,int> p = make_pair(k,l) ; 
                return p ; 
            }
            else if(v[mid]>x){
                j = mid-1;
            }
            else{
                i = mid+ 1 ;
            }
        }
        
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends