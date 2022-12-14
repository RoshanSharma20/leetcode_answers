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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *ptr=dummy;
        while(list1 && list2)
        {
            if(list1->val<=list2->val)
            {
                ptr->next=list1;
                list1=list1->next;
                ptr=ptr->next;
            }
            else
            {
                ptr->next=list2;
                list2=list2->next;
                ptr=ptr->next;
            }
        }
        while(list1)
        {
            ptr->next=list1;
            list1=list1->next;
            ptr=ptr->next;
        }
        while(list2)
        {
            ptr->next=list2;
            list2=list2->next;
            ptr=ptr->next;
        }
        return dummy->next;
    }
};