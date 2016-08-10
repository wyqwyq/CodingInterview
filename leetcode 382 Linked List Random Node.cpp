class Solution {
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head):head_(head) {
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        // reservoir sampling
        ListNode * cur = head_;
        ListNode * ret;
        int len = 1;
        while(cur){
            if(random() % len == 0){
                ret = cur;
            }
            len++;
            cur = cur->next;
        }
        return ret->val;
    }
private:
    ListNode * head_;
};
