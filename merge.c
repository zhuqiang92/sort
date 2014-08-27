#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int firstElement, int middleElement, int lastElement) {
	int i, j, k, *front, *back;
	int n1, n2;
	
	n1 = middleElement - firstElement + 1;
	n2 = lastElement - middleElement;
	
	front = (int *) malloc ( n1 * sizeof(int) );
	back  = (int *) malloc ( n2 * sizeof(int) );
	
	for(i = 0; i < n1; i++)
		front[i] = a[firstElement + i];
	for(i = 0; i < n2; i++)
		back[i] = a[middleElement + i + 1];
		
	i = 0;
	j = 0;
	k = firstElement;
	
	while(i < n1 && j < n2) {
		if(front[i] < back[j])
			a[k++] = front[i++];
		else
			a[k++] = back[j++];
	}
	
	while(i < n1)
		a[k++] = front[i++];
		
	while(j < n2)
		a[k++] = back[j++];				
}

void merge_sort(int a[], int firstElement, int lastElement) {
	int middleElement;
	
	middleElement = (firstElement + lastElement) / 2;
	
	if(firstElement < lastElement) {
		merge_sort(a, firstElement, middleElement);
		merge_sort(a, middleElement + 1, lastElement);
		merge(a, firstElement, middleElement, lastElement);
	}
}

void main() {
	int array[15] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
	int i;
	
	merge_sort(array, 0, 14);
	
	for(i = 0; i < 15; i++) {
		printf("%d ", array[i]);
	}
}
