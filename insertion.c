#include <stdio.h>

void main() {
	int array[15] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
	int firstUnsortedPosition = 1;
	int extraction;
	int i;
	
	while(firstUnsortedPosition < 15) {
		extraction = array[firstUnsortedPosition];
		for(i = firstUnsortedPosition - 1; i >= 0; i--) {
			if(array[i] > extraction) {
				array[i+1] = array[i];
				array[i] = extraction;
			}	
			else {
				array[i+1] = extraction;
				break;
			}
		}
		firstUnsortedPosition++;  
	}

	for(i = 0; i < 15; i++) {
		printf("%d ", array[i]);
	}
}
