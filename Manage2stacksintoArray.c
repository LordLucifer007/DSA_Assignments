#include <stdio.h>
#include <limits.h>
 
#define ARRAY_SIZE 100000
#define STACK1 0
#define STACK2 1
 
struct st {
    int array[ARRAY_SIZE];
    int top1, top2;
} st;
 
void initialize() {
    st.top1 = -1;
    st.top2 = ARRAY_SIZE;
}
  
void push(int stack, int num) {
    if(stack == STACK1) {
        if (st.top1 < st.top2-1) {
            st.top1++;
            st.array[st.top1] = num;
        } else {
            printf("Stack1 is Full");
            return;
        }
    } else if(stack == STACK2) {
       if (st.top1 < st.top2-1) {
           st.top2--;
           st.array[st.top2] = num;
       } else {
           printf("Stack2 is Full");
           return;
       }
    }
}
  
int pop(int stack) {
    if(stack == STACK1) {
        if(st.top1 >= 0){
            return st.array[st.top1--];
 } else {
            printf("Stack1 is Empty");
            return INT_MIN;
 }
    } else if(stack == STACK2) {
     if(st.top2 <= ARRAY_SIZE-1){
         return st.array[st.top2++];
 } else {
            printf("Stack2 is Empty");
            return INT_MIN;
 }
    }
}
  
int main() {
    initialize();
    /* Push element in stack1 */
    push(STACK1, 2);
    push(STACK1, 4);
    push(STACK1, 6);
    /* Push element in stack2 */
    push(STACK2, 1);
    push(STACK2, 3);
    push(STACK2, 5);
    /*Pop Elements from stack1 */
    printf("Pop from stack1 %d\n", pop(STACK1));
    /*Pop Elements from stack2 */
    printf("Pop from stack2 %d\n", pop(STACK2));
    return 0;
}

