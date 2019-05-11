class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *node = head;
        int forward = 0;
        int val1 = 0;
        int val2 = 0;
        do
        {
            if (head == NULL)
            {
                head = node = new ListNode(0);
            }
            else
            {
                node->next = new ListNode(0);
                node = node->next;
            }
                        
            if (l1 != NULL) 
            {
                val1 = l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL) 
            {
                val2 = l2->val;
                l2 = l2->next;
            }
            
            if ((l1!=NULL && l2==NULL) || (l1==NULL && l2!=NULL))
            {
                int val = val1 + val2 + forward;
                node->val = val%10;
                forward = val/10;
                val1 = val2 = forward;
                forward = 0;
            }
            else
            {
                int val = val1 + val2 + forward;
                node->val = val % 10;
                forward = val/10;
            }
           
        } while(l1!=NULL || l2!=NULL);
        
        if (forward > 0)
        {
            node->next = new ListNode(forward);
        }
            
        return head;
    }
};