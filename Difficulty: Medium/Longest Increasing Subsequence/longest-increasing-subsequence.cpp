//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int solvetab(vector<int> arr){
        int n = arr.size() ; 
        vector<vector<int>> dp ( n + 1 , vector<int> ( n+1 , 0)) ; 
        
        for(int curr = n - 1 ; curr>= 0 ; curr--){
            for(int prev = curr-1 ; prev>= -1 ; prev--){
                int take = 0 ; 
                if(prev==-1|| arr[curr]>arr[prev]){
                    take = 1 + dp[curr+1][curr+1] ;
                }
                int untake = dp[curr+1][prev+1] ; 
                dp[curr][prev+1] = max(take, untake) ; 
            }
        }
        return dp[0][0];
    }
    int solvefast(vector<int> arr){
        int n = arr.size() ; 
        // vector<vector<int>> dp ( n + 1 , vector<int> ( n+1 , 0)) ; 
        vector<int>currRow (n+1,0 ) ; 
        vector<int>nextRow (n+1,0 ) ; 
        
        for(int curr = n - 1 ; curr>= 0 ; curr--){
            for(int prev = curr-1 ; prev>= -1 ; prev--){
                int take = 0 ; 
                if(prev==-1|| arr[curr]>arr[prev]){
                    // take = 1 + dp[curr+1][curr+1] ;
                    take = 1 + nextRow[curr+1] ; 
                    // take = 1 + curr[curr+1] ; 
                }
                // int untake = dp[curr+1][prev+1] ; 
                int untake = nextRow[prev+1] ; 
                // int untake = curr 
                
                currRow[prev+1] = max(take, untake) ; 
            }
            // currRow = nextRow ; 
            nextRow = currRow ; 
        }
        // return dp[0][0];
        return currRow[0] ; 
        
        
    }
    int longestSubsequence(vector<int>& arr) {
        // code here
        return solvefast(arr); 
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