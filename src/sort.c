#include <stdio.h>
#include <string.h>
#include <time.h>

#define LENGTH 4

typedef struct book Book;

struct book {
	char title[50];
	int id;
	Book *next;
};

void bubbleSort(int numbers[], int size) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = i; j < size; j++) {
			if (numbers[i] > numbers[j]) {
				int tmp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = tmp;
			}
		}
	}
}

void merge(int numbers[], int begin, int middle, int end) {
	printf("%d %d %d\n", begin, middle, end);
	if (begin == middle) {
		if (numbers[begin] > numbers[end]) {
			int tmp = numbers[begin];
			numbers[begin] = numbers[end];
			numbers[end] = tmp;
			return;
		}
	}
	int chunkSize = middle - begin + 1;
	int tmpA[chunkSize];
	int i, j, noChanged = 0;
	
	for (i = 0; i < chunkSize; i++) {
		tmpA[i] = numbers[begin + i];
	}
	
	for (i = begin; i <= begin + middle; i++) {
		int tmp = numbers[i];
		printf ("%d\n", tmp);
		for (j = middle + begin + 1; j <= end; j++) {
			if (tmp > numbers[j]) {
				numbers[i++] = numbers[j];
				noChanged++;
			} else {
				numbers[i] = tmp;
				break;
			}
		}
	}
	if (noChanged == chunkSize) {
		for (i = 0; i < chunkSize; i++) {
			numbers[middle + 1 + i] = tmpA[i];
		}
	}
}

void mergeSort(int numbers[], int begin, int end) {
	if (begin == end) {
		return;
	}
	int middle = begin + (end - begin) / 2;
	mergeSort(numbers, begin, middle);
	mergeSort(numbers, middle + 1, end);
	merge(numbers, begin, middle, end);
}

int main() {
	
	int numbers[LENGTH] = {4,1,3,2};
	int length = sizeof(numbers) / sizeof(int);
	
	mergeSort(numbers, 0, length - 1);
	int i;
	for (i = 0; i < length; i++) {
		printf("%d\n", numbers[i]);
	}

    printf("Finished in: %.2lf s.\n", (float) clock() / CLOCKS_PER_SEC);
    
    return 0;
    
}
