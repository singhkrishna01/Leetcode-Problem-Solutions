class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(head->next==nullptr)
        return NULL;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast!=nullptr && fast->next!=nullptr){
            prev =slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        return head;
    }
};