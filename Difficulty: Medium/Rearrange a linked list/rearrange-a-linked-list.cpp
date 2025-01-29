//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl
         << "~"
         << "\n";
}


// } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    void rearrangeEvenOdd(Node *head) {
        // Your Code here
        vector<int> odd ; 
        vector<int> even ; 
        
        Node*temp = head ; 
        int i = 1 ; 
        while(temp!=NULL){
            if(i%2==1){
                odd.push_back(temp->data) ; 
            }
            else{
                even.push_back(temp->data) ; 
            }
            temp = temp->next ; 
            i++ ; 
        }
        
        temp = head ; 
       for(int i =0  ;  i < odd.size() ; i ++){
           temp->data = odd[i] ; 
           temp=temp->next ; 
       }
       for(int i =0  ;  i < even.size() ; i ++){
           temp->data = even[i] ;  
           temp=temp->next ; 
       }
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends