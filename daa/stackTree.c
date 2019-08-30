#include<stdio.h>
#include<stdlib.h>
// tree implimentatation
struct treeNode{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};
// to add new node
struct treeNode* treeNewNode(int data){
    struct treeNode *temp = (struct treeNode *) malloc(sizeof(struct treeNode));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
// insert data
struct treeNode* insert(struct treeNode* node,int data){
    if(node==NULL){
        return treeNewNode(data);
    }
    if(data<node->data){
        node->left = insert(node->left,data);
    }
    else if(data>node->data){
        node->right = insert(node->right,data);
    }
    return node;
}

// =====================================================================

struct stackNode{
    int data;
    struct stackNode* next;
}*top;

void push(int data){
    struct stackNode *temp = (struct stackNode *)malloc(sizeof(struct stackNode));
    temp->data=data;
    if(top==NULL){
        top=temp;
        top->next=NULL;
    }  
    else{
        temp->next=top;
        top=temp;
    } 
}
int pop(){
    if(top!=NULL){
        struct stackNode *temp1;
        temp1=top;
        int x = temp1->data;
        temp1=temp1->next;
        top=temp1;
        return x;
       
    }
}
// traverse tree
void inorder(struct treeNode *node){
    if(node!=NULL){
        inorder(node->left);
        push(node->data);
        inorder(node->right);
    }
}

// =============================================================
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)         
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
void main(){
    top=NULL;
    printf("============Enter number of node in tree=============\n");
    int n;
    scanf("%d",&n);
    printf("=================Enter data for tree=================\n");
    struct treeNode *head =NULL;
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        if(head==NULL){
            head = insert(head,data);
        }
        insert(head,data);
    }
    
    printf("============Enter number of node in stack=============\n");
    int k;
    scanf("%d",&k);
    printf("=================Enter data for stack=================\n");
    for(int i=0;i<k;i++){
        int data;
        scanf("%d",&data);
        push(data);
    }
   int arr[n+k];
   int i=0;
    inorder(head);
     while(top!=NULL){
         arr[i]=top->data;
         i+=1;
         top=top->next;
     }
     bubbleSort(arr,n+k);
     printf("=================Sorted array =================\n");
     for (i=0; i < n+k; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
}