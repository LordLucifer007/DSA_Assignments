//2. Write program to insert, delete and search an element in a sorted linked list

#include <stdio.h>
#include <stdlib.h>
  
  //Insertion(Creating a linked List)
struct Node {
    int data;
    struct Node* next;
};
first, *nw;

 void sortedInsert(struct Node** head_ref,
                  struct Node* new_node)
{
    struct Node* current;
	if (*head_ref == NULL
        || (*head_ref)->data
               >= new_node->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
    		current = *head_ref;
        while (current->next != NULL
               && current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

struct Node* newNode(int new_data)
{
    struct Node* new_node 
= (struct Node*)malloc(
sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = NULL;
  
    return new_node;
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct Node* head = NULL;
    struct Node* new_node = newNode(5);
    sortedInsert(&head, new_node);
    new_node = newNode(10);
    sortedInsert(&head, new_node);
    new_node = newNode(7);
    sortedInsert(&head, new_node);
    new_node = newNode(3);
    sortedInsert(&head, new_node);
    new_node = newNode(1);
    sortedInsert(&head, new_node);
    new_node = newNode(9);
    sortedInsert(&head, new_node);
    printf("\n Created Linked List\n");
    printList(head);
  
    return 0;
}

//Deletion
int binarySearch(int arr[], int low, int high, int key);
 
int deleteElement(int arr[], int n, int key)
{
    int pos = binarySearch(arr, 0, n - 1, key);
 
    if (pos == -1) {
        printf("Element not found");
        return n;
    }
     int i;
    for (i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
 
    return n - 1;
}

int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = (low + high) / 2;
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
    return binarySearch(arr, low, (mid - 1), key);
}
 
 int main()
{
    int i;
    int arr[] = { 10, 20, 30, 40, 50 };
 
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
 
    printf("Array before deletion\n");
    for (i = 0; i < n; i++)
        printf("%d  ", arr[i]);
 
    n = deleteElement(arr, n, key);
 
    printf("\n\nArray after deletion\n");
    for (i = 0; i < n; i++)
        printf("%d  ", arr[i]);
}

//Search
int search(int item)
{
     int count=1;
     nw=&first;
     while(nw->next!=NULL)
     {
          if(nw->data==item)
               break;
          else
               count++;
          nw=nw->next;
     }
     return count;
}
int main()
{
     int no,i,item,pos;
     first.next=NULL;
     nw=&first;
     printf("How many nodes you want in linked list?: ");
     scanf("%d",&no);
     printf("\n");
     for(i=0;i< no;i++)
     {
          nw->next=(struct node *)malloc(sizeof(struct node));
          printf("Enter element in node %d: ",i+1);
          scanf("%d",&nw->data);
          nw=nw->next;
     }
     nw->next=NULL;
     printf("\nElements in linked list :\n\n");
     nw=&first;
     while(nw->next!=NULL)
     {
          printf("%d\t",nw->data);
          nw=nw->next;
     }
     printf("\n");
     printf("\nEnter element to be searched : ");
     scanf("%d",&item);
     pos=search(item);
     if(pos<=no)
          printf("\n'%d' is found at node = %d",item,pos);
     else
          printf("Sorry! '%d' is not in linked list.",item);
     return 0;
}