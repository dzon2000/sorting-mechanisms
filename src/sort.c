#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 102400

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
	int i;
	//printf("%d %d %d\n", begin, middle, end);
	if (begin == middle) {
		if (numbers[begin] > numbers[end]) {
			int tmp = numbers[begin];
			numbers[begin] = numbers[end];
			numbers[end] = tmp;
		}
		return;
	}
//	for (i = 0; i < LENGTH; i++) {
//		if (i == begin) {
//			printf("|");
//		}
//		printf("%d ", numbers[i]);
//		if (i == middle) {
//			printf("|");
//		} else if (i == end) {
//			printf("|");
//		}
//	}
//	puts("");
	int chunkSize = middle - begin + 1;
	int tmpA[chunkSize];
	int j, noChanged = 0, k, l = 0;

	for (i = 0; i < chunkSize; i++) {
		tmpA[i] = numbers[begin + i];
	}

	for (i = begin, k = i; i < begin + chunkSize; i++, k++) {
		noChanged = 0;
		int tmp = tmpA[i - begin];
		for (j = middle + 1 + l; j <= end; j++) {
			if (tmp > numbers[j]) {
				numbers[k++] = numbers[j];
				noChanged++;
				l++;
			} else {
				numbers[k] = tmp;
				break;
			}
		}
		numbers[k] = tmp;
		if (noChanged == chunkSize) {
			int x;
			for (x = k + 1; x <= end; x++) {
				numbers[x] = tmpA[++i - begin];
			}
			break;
		}
	}
//	for (i = 0; i < LENGTH; i++) {
//		if (i == begin) {
//			printf("|");
//		}
//		printf("%d ", numbers[i]);
//		if (i == middle) {
//			printf("|");
//		} else if (i == end) {
//			printf("|");
//		}
//	}
//	puts("");
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

void sortIt(int numbers[], int length) {
//	mergeSort(numbers, 0, length - 1);
	bubbleSort(numbers, length);
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
	int numbers[LENGTH]; /*= { 754, 620, 789, 633, 338, 286, 180, 713, 254, 56,
			654, 109, 411, 909, 110, 559, 991, 294, 76, 527, 770, 74, 213, 992,
			238, 865, 210, 70, 862, 997, 111, 617 };*/
	int i;
	for (i = 0; i < LENGTH; i++) {
		numbers[i] = rand() % 10000000;
//		printf("%d\n", numbers[i]);
	}
	puts("");
	//int length = sizeof(numbers) / sizeof(int);
	sortIt(numbers, LENGTH);
//	puts("");
//	int numbers1[LENGTH] = { 1, 2, 3, 4 };
//	sortIt(numbers1, LENGTH);
//	puts("");
//	int numbers2[LENGTH] = { 2, 4, 1, 3 };
//	sortIt(numbers2, LENGTH);
//	puts("");
//		int numbers3[LENGTH] = { 3, 4, 2, 1 };
//		sortIt(numbers3, LENGTH);
	printf("Finished in: %.2lf s.\n", (float) clock() / CLOCKS_PER_SEC);

	return 0;

}
