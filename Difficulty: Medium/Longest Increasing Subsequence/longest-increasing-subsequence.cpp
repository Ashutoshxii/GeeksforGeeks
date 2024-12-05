//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int solve(vector<int>&arr , int curr , int prev){
        int n = arr.size() ; 
        if(curr==n)return 0 ;
        int take = 0 ; 
        if(prev==-1||arr[curr]>arr[prev]){
            take = 1 + solve(arr , curr+ 1 , curr) ;
        }
        int untake = solve(arr, curr+1,prev);
        return max(take,untake) ; 
        //4min
    }
    int solvemem(vector<int>&arr , int curr , int prev, vector<vector<int>> dp){
        int n = arr.size() ; 
        if(curr==n)return 0 ;
        
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1] ; 
        }
        
        int take = 0 ; 
        if(prev==-1||arr[curr]>arr[prev]){
            take = 1 + solvemem(arr , curr+ 1 , curr , dp) ;
        }
        int untake = solvemem(arr, curr+1,prev,dp);
        return dp[curr][prev+1]  = max(take,untake) ; 
        //6min
    }
    int tabulation(vector<int>arr,int n){
        vector<vector<int>> dp (n+1 , vector<int> (n+1, 0));
        
        for(int curr = n -1 ; curr>= 0 ; curr--){
            for(int prev = curr - 1 ; prev >= -1 ; prev--){
                int take = 0 ; 
                if(prev==-1||arr[curr]>arr[prev]){
                    take = 1 + dp[curr+ 1][ curr + 1 ] ;
                }
                int untake = dp[curr+1][prev+1];
                // return dp[curr][prev+1]  = max(take,untake) ; 
                dp[curr][prev+1] = max(take , untake) ; 
            }
        }
        return dp[0][0] ; 
        
    }
    int tabulationfast(vector<int>arr,int n){
        // vector<vector<int>> dp (n+1 , vector<int> (n+1, 0));
        vector<int> currRow( n + 1 , 0) ; 
        vector<int> nextRow( n + 1 , 0) ; 
        
        for(int curr = n -1 ; curr>= 0 ; curr--){
            for(int prev = curr - 1 ; prev >= -1 ; prev--){
                int take = 0 ; 
                if(prev==-1||arr[curr]>arr[prev]){
                    take = 1 + nextRow[ curr + 1 ] ;
                }
                int untake = nextRow[prev+1];
                // return dp[curr][prev+1]  = max(take,untake) ; 
                currRow[prev+1] = max(take , untake) ; 
            }
            nextRow  = currRow ; 
        }
        return currRow[0] ; 
        
    }
    // int 
    int solveoptimal(vector<int> arr , int n ){
        if(n==0){
            return 0 ; 
        }
        vector<int> vec ; 
        vec.push_back(arr[0]) ; 
        for(int i = 1 ; i  < n ; i++){
            if(vec.back()<arr[i]){
                vec.push_back(arr[i]) ; 
            }
            else{
                int j = lower_bound(vec.begin() , vec.end() , arr[i]) - vec.begin()  ;
                vec[j] = arr[i] ; 
            }
        }
        return vec.size() ; 
        
    }
    int longestSubsequence(vector<int>& arr) {
        // code here
        // int n = arr.size() ; 
        // vector<vector<int>> dp (n , vector<int>(n+1 , -1));
        // return solvemem(arr , 0 , -1 , dp) ; 
        int n = arr.size() ; 
        // return tabulationfast(arr,n) ;
        return solveoptimal(arr,n) ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.longestSubsequence(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends
