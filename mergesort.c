#include<stdio.h>
#include<stdlib.h>

void mergeSort(int data[], int start, int mid, int end)
{
  return;
}

void mergeSortSplit(int data[], int start, int end)
{
  if(end>start)
  {
    int mid = (start-end)/2;
    mergeSortSplit(data, start, mid);
    mergeSortSplit(data, mid+1, end);          
    mergeSort(data, start, mid, end);
  }
}

int main() 
{
  int sortMe[7]= {6, 3, 1, 8, 9, 4, 5};
  int size = sizeof(sortMe)/sizeof(int);
  mergeSortSplit(sortMe, 0, size-1);
  return 0;
}
