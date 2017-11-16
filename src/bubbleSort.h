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
