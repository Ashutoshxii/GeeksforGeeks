//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size() ; 
        int m = capacity ;
        vector<vector<int>> dp (n+1 , vector<int>(m+1,0)) ;
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(wt[i-1] <= j){
                    dp[i][j] = max((val[i-1]+dp[i-1][j-wt[i-1]])
                    , dp[i-1][j]) ; 
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m] ; 
        
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends