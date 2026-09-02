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
    void reorderList(ListNode* head) {
        vector<int> a;
        
        ListNode* tmp = head;
        while(tmp) {
            a.push_back(tmp->val);
            tmp = tmp->next;
        }

        int n = a.size();
        vector<int> a1(n);

        for(int i = 0; i < n; i += 2) a1[i] = a[i / 2];
        for(int i = 1; i < n; i += 2) a1[i] = a[n - (i + 1) / 2];

        ListNode* tmp1 = head;
        for(int i = 0; i < n; i++) {
            tmp1->val = a1[i];
            tmp1 = tmp1->next;
        }
    }
};
