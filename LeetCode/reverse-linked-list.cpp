// https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // I can use the Same linked list just changing the next pointers !! 
        // A    ->     B     ->     C
        // prev      curr
        //                      Next
        //       <---
        //           prev
        //                       curr
        
        //Not a recursive call
        //no of nodes can be 0 or 1 also 
        if (head==NULL or head->next==NULL)
            return head; 

        ListNode* curr, *prev, *Next; //don't forget to use pointer sign with last 2 variables
        curr = head; 
        prev= NULL; 

        while (curr != NULL)
        {
            Next=curr->next; 

            curr->next = prev; 
            prev=curr; 
            curr=Next; 
        }

        return prev; 
    }
};