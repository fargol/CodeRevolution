/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* deleteDuplicates(listnode* A) {
    listnode *head=A,*curr=A->next,*prev=A,*next;
    while(curr!=NULL){
        if(curr->val==prev->val){
            prev->next=curr->next;
            free(curr);
            curr=prev->next;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}
