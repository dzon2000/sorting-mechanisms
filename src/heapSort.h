int getParentIdx(int iChild) {
	return (iChild - 1) / 2;
}

void siftUp(int numbers[], int start, int end) {

	int iChild = end;
	while (iChild > start) {
		int iParent = getParentIdx(iChild);
		if (numbers[iChild] > numbers[iParent]) {
			int tmp = numbers[iChild];
			numbers[iChild] = numbers[iParent];
			numbers[iParent] = tmp;
		}
		iChild = iParent;
	}

}

void siftDown(int numbers[], int start, int end) {

}

void heapify(int numbers[], int length) {
	int end = 1;
	while (end < length) {
		siftUp(numbers, 0, end);
		end++;
	}
}

void heapSort(int numbers[], int length) {
	heapify(numbers, length);

	int end = length - 1;
	int i;
	while (end > 0) {
		int tmp = numbers[end];
		numbers[end] = numbers[0];
		numbers[0] = tmp;
		end--;
		//siftUp(numbers, 0, end);
					heapify(numbers, end + 1);
	}
}
