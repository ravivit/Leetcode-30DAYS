class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node create
        ListNode* dummy = new ListNode(-1);

        // temp pointer for building answer
        ListNode* temp = dummy;

        // jab tak dono lists me nodes hain
        while(list1 != NULL && list2 != NULL) {

            // agar list1 chhoti hai
            if(list1->val <= list2->val) {

                temp->next = list1;
                list1 = list1->next;
            }
            else {

                temp->next = list2;
                list2 = list2->next;
            }

            // temp ko aage badhao
            temp = temp->next;
        }

        // agar list1 bachi hai
        if(list1 != NULL) {
            temp->next = list1;
        }

        // agar list2 bachi hai
        if(list2 != NULL) {
            temp->next = list2;
        }

        // dummy ke next me actual answer hai
        return dummy->next;
    }
};