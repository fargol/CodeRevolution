#include<bits/stdc++.h>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}
struct Node * mergeResult(struct Node *node1,struct Node *node2);
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;
        struct Node* headA=NULL;
        struct Node* tempA = headA;
        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);
            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }
        struct Node* headB=NULL;
        struct Node* tempB = headB;
        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);
            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        struct Node* result = mergeResult(headA,headB);
        print(result);
        cout<<endl;
    }
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of linked list is the following
struct Node
{
int data;
Node* next;
};
*/
struct Node * mergeResult(Node *node1,Node *node2)
{
    // your code goes here
    Node *ptr1=node1,*ptr2=node2,*headFinal=NULL,*curr=NULL;
    while(ptr1!=NULL&&ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            Node *temp=ptr1;
            ptr1=ptr1->next;
            temp->next=curr;
            curr=temp;
        }
        else{
            Node *temp=ptr2;
            ptr2=ptr2->next;
            temp->next=curr;
            curr=temp;
        }
    }
    while(ptr1!=NULL){
        Node *temp=ptr1;
        ptr1=ptr1->next;
        temp->next=curr;
        curr=temp;
    }
    while(ptr2!=NULL){
        Node *temp=ptr2;
        ptr2=ptr2->next;
        temp->next=curr;
        curr=temp;
    }
    headFinal=curr;
    curr=headFinal;
    return headFinal;
}