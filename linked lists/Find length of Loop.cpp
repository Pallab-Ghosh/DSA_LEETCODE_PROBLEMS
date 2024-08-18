#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//{ Driver Code Starts
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
    cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(struct Node *head) {
        // Code here
        Node* slow = head ;
        Node* fast=head ;
        Node* position_ptr = head;
      
        
        int res=1;

        if(head == 0 || head->next==0) // head is null or only 1 node
           return 0;

        while(fast != 0 && fast->next != 0)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) //break if find cycle
              break;
        }
        

       if(slow == fast) // check if slow == fast then again run loop
       {
           
           
           while(position_ptr != slow)
           {
             position_ptr = position_ptr->next;
             slow = slow->next;
           }

             Node* start = position_ptr->next;
           // start reached to the node where cycle started
           while(start!=position_ptr)
           {
               start=start->next;
               res++;
           }
             
             
             return res;
       }
       
       else // else return null that no cycle found 
       {
         return 0;
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
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        loopHere(head, tail, k);

        Solution ob;
        cout << ob.countNodesinLoop(head) << endl;
    }
    return 0;
}

// } Driver Code Ends

int main(int argc, char** argv) {
	return 0;
}
