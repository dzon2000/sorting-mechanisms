void merge(int numbers[], int begin, int middle, int end) {
	int i;
	if (begin == middle) {
		if (numbers[begin] > numbers[end]) {
			int tmp = numbers[begin];
			numbers[begin] = numbers[end];
			numbers[end] = tmp;
		}
		return;
	}
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
