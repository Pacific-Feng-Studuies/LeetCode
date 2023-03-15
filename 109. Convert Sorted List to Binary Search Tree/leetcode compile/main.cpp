
class Solution {
public:

    TreeNode* BSTG(ListNode* head, ListNode* tail)  
    {
        if(head == tail) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val);

        root ->left = BSTG(head, slow);
        root ->right = BSTG(slow->next, tail);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head == nullptr)         return nullptr;

        if(head->next == nullptr)   return new TreeNode(head->val);

        return BSTG(head, nullptr);
    }
};