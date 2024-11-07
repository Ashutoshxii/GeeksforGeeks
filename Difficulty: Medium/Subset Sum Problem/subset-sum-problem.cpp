//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int row = arr.size() + 1 ;
        int col = sum + 1 ;
        // vector<vector<bool>> vec (row,vector<bool>(col)) ;
        // return 1 ;
         vector<vector<bool>> vec(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            vec[i][0] = true; 
        }
        
        
        
        for(int i = 1 ; i < row ; i++){
            for(int j = 1 ; j < col ; j++){
                if(arr[i-1]<=j){
                    vec[i][j] = (vec[i-1][j] || vec[i-1][j-arr[i-1]]);
                }
                else{
                    vec[i][j] = vec[i-1][j] ; 
                }
            }
        }
        return vec[row-1][col-1] ;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends