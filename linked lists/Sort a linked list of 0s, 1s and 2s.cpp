#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */




class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    
    void get_sorted_arr( vector<int>&nums)
    {
        int n = nums.size();

        int mid = 0 , low = 0, high = n-1;
        
        while(mid <= high)
        {
            if(nums[mid] ==0)
            {
                swap(nums[low] , nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else {
                swap(nums[mid] , nums[high]);
                high--;
            }
        }
    }
    
    
    Node* segregate(Node* head) {

        // Add code her
        if(head == 0 || head->next == 0 )return head;
        Node* temp = head;
        
        vector<int>store_ele;
        
        while(temp!=0)
        {
            store_ele.push_back(temp->data);
            temp = temp->next;
        }
        
        get_sorted_arr(store_ele);
        
        temp = head;
        int i = 0;
        while(temp!=0)
        {
            temp->data = store_ele[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
 
