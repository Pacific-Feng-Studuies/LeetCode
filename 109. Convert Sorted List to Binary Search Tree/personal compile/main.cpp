#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Definition for a binary tree node
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:

    TreeNode* BSTG(ListNode* head, ListNode* tail)  
    {
        if(head == tail) 
            return nullptr;
        
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

void output(TreeNode* root)
{
    queue <TreeNode*> queue_tree;

    queue_tree.push(root);

    while (queue_tree.size() != 0)
    {
        if(queue_tree.front()!=nullptr)
        {
            if(queue_tree.front()->left != nullptr)
            {
                queue_tree.push(queue_tree.front()->left);
            } 

            if(queue_tree.front()->right != nullptr)
            {
                queue_tree.push(queue_tree.front()->right);
            }

            if(queue_tree.front()->left != nullptr || queue_tree.front()->right != nullptr)
            {
                if(queue_tree.front()->left == nullptr)
                {
                    queue_tree.push(nullptr);
                }

                if(queue_tree.front()->right == nullptr)
                {
                    queue_tree.push(nullptr);
                }
            }

            cout << queue_tree.front()->val << endl;
        }
        else
        {
            if(!(queue_tree.size()==1 && queue_tree.front()==nullptr))  
                cout << "Null" << endl;               
        } 

        queue_tree.pop();
    }
}

int main()
{
    ListNode* list4 = new ListNode(9);
    ListNode* list3 = new ListNode(5, list4);
    ListNode* list2 = new ListNode(0, list3);
    ListNode* list1 = new ListNode(-3, list2);
    ListNode* list0 = new ListNode(10, list1);

    Solution solution;
    TreeNode* result = solution.sortedListToBST(list0);
    output(result);

    return 0;
}