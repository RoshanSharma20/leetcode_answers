/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        if(node->next->next==NULL)
        {
            node->val=node->next->val;
            node->next=NULL;
        }
        else
        {
            ListNode *temp = node;
            node=node->next;
            while(node->next)
            {
                temp->val=node->val;
                node=node->next;
                temp=temp->next;
            }
            temp->val=node->val;
            temp->next=NULL;
        }
    }
};