//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>&h , int i ,vector<int>&dp){
        if(i>= h.size()-1)return 0 ; 
        if(dp[i]!=-1)return dp[i] ; 
        int first = INT_MAX ; 
        int second = INT_MAX ; 
        
        
   
        first = abs(h[i]-h[i+1]) + solve(h,i+1,dp) ; 
  
        if(i < h.size() -2){
            second = abs(h[i]-h[i+2]) + solve(h,i+2,dp) ; 
        }
        return dp[i] = min(first,second) ; 
    }   
    int minCost(vector<int>& height) {
        // Code here
        vector<int> dp(height.size(),-1)  ; 
        return solve(height,0,dp) ; 
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends