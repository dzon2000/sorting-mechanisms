#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "mergeSort.h"
#include "bubbleSort.h"
#include "heapSort.h"

#define LENGTH 1024000

typedef struct book Book;

struct book {
	char title[50];
	int id;
	Book *next;
};

void printArray(int numbers[0], int length) {
	int i;
	for (i = 0; i < length; i++) {
		printf("%d ", numbers[i]);
	}
	puts("");
}

void sortIt(int numbers[], int length) {
//	mergeSort(numbers, 0, length - 1);
	heapSort(numbers, length);
//	bubbleSort(numbers, length);
//	printArray(numbers, length);
	FILE *fp;
	fp = fopen("sorted.txt", "w");
	fprintf(fp, "--==Sorted numbers==--\n");

	int i;
	for (i = 0; i < length; i++) {
		fprintf(fp, "%d\n", numbers[i]);
	}
	fclose(fp);
	puts("");
}

int main() {
	srand(time(0));
	int numbers[LENGTH]; //= {6, 5, 3, 1, 8, 7, 2, 4 };
//	siftUp(numbers, 0, 5);
//	heapSort(numbers, LENGTH);
//	printArray(numbers, LENGTH);
	int i;
	for (i = 0; i < LENGTH; i++) {
		numbers[i] = rand() % 10000000;
	}
	puts("");
	sortIt(numbers, LENGTH);
	printf("Finished in: %.2lf s.\n", (float) clock() / CLOCKS_PER_SEC);

	return 0;

}

