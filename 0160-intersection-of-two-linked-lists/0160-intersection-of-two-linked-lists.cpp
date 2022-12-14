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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        map<ListNode*,int> m;
        while(headA)
        {
            m[headA]=1;
            headA=headA->next;
        }
        while(headB)
        {
            if(m.find(headB)!=m.end())
                return headB;
            headB=headB->next;
        }
        return NULL;
        }
};