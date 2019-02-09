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
 * @input B : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* mergeTwoLists(listnode* A, listnode* B) {
    listnode *currA=A,*currB=B,*head=NULL,*prev=NULL;
    while(currA!=NULL&&currB!=NULL){
        if(currA->val<currB->val){
            if(head==NULL){
                head=currA;
            }
            else{
                prev->next=currA;
            }
            prev=currA;
            currA=currA->next;
        }
        else{
            if(head==NULL){
                head=currB;
            }
            else{
                prev->next=currB;
            }
            prev=currB;
            currB=currB->next;
        }
    }
    while(currA!=NULL){
        prev->next=currA;
        prev=currA;
        currA=currA->next;
    }
    while(currB!=NULL){
        prev->next=currB;
        prev=currB;
        currB=currB->next;
    }
    prev->next=NULL;
    return head;
}
