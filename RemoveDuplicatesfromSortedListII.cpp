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
    listnode *curr=A,*prev=NULL,*next=NULL,*head;
    while(curr!=NULL){
        if(prev==NULL){
            head=curr;
            prev=curr;
            curr=curr->next;
        }
        else{
            if(prev->val==curr->val){
                next=curr->next;
                prev->next=next;
                free(curr);
                curr=next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
    }
    prev->next=NULL;
    return A;
}
