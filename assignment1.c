#include <stdio.h>

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

int main()
{
    int i, n, a[100000];
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    insertionSort(a,n);
    printf("The sorted elements are : ");
    for(i = 0; i < n; i++)
        printf("%d  ",a[i]);
    printf("\n");
    return 0;
}

