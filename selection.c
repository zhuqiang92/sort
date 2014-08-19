#include <stdio.h>

int swap(int *a, int *b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void main() {
	int array[15] = {27,36,19,26,2,48,50,46,3,4,5,47,15,38,44};
	int numOfElements = 15;
	int minimum, min;
	int firstUnsortedPosition = 0;
	int i;
	
	while(numOfElements-- != 0) {
		minimum = array[firstUnsortedPosition];

		for(i = firstUnsortedPosition + 1; i<15; i++) {
			if(array[i] < minimum) {
				minimum = array[i];
				min = i;
			}
		}

		swap(&array[min], &array[firstUnsortedPosition]);
		
		firstUnsortedPosition += 1;
	}

	for(i = 0; i<15; i++) {
		printf("%d ", array[i]);
	}
}
