//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(int A[], int l, int h, int key) {
        // l: The starting index
        // h: The ending index, you have to search the key in this range

        // complete the function here
        int left = l ; 
        int right = h ;
        int mid = (left + right)/2 ;
        
        while(left<=right){
            mid = (left+right)/2 ; 
            if(A[mid]==key){
                return mid ; 
            }
            else if(A[mid]>=A[left]){
                if(key<= A[mid]&&key >= A[left]){
                    right = mid - 1 ; 
                }
                else{
                    left = mid + 1 ;
                }
            }
            else{
                if(key<=A[right]&&key>= A[mid]){
                    left = mid + 1 ;
                }
                else{
                    right = mid -1 ; 
                }
            }
        }
        return -1 ; 
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
    return 0;
}
// } Driver Code Ends