int getParentIdx(int iChild) {
	return (iChild - 1) / 2;
}

int getLeftChildIdx(int iParent) {
	return 2 * iParent + 1;
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
	int root = start;
	int iChild = getLeftChildIdx(root);
	while (iChild <= end) {
		int swap = root;
		if (numbers[swap] < numbers[iChild]) {
			swap = iChild;
		}
		if (iChild + 1 <= end && numbers[swap] < numbers[iChild + 1]) {
			swap = iChild + 1;
		}
		if (swap == root) {
			return;
		} else {
			int tmp = numbers[swap];
			numbers[swap] = numbers[root];
			numbers[root] = tmp;
			root = swap;
		}
		iChild = getLeftChildIdx(root);
	}
}

void heapifyUp(int numbers[], int length) {
	int end = 1;
	while (end < length) {
		siftUp(numbers, 0, end);
		end++;
	}
}

void heapifyDown(int numbers[], int length) {
	int start = getParentIdx(length - 1);
	while (start >= 0) {
		siftDown(numbers, start, length - 1);
		start--;
	}
}

void heapSort(int numbers[], int length) {
//	heapifyUp(numbers, length);
	heapifyDown(numbers, length);
	int end = length - 1;
	while (end > 0) {
		int tmp = numbers[end];
		numbers[end] = numbers[0];
		numbers[0] = tmp;
		end--;
//		siftUp(numbers, 0, end);
		siftDown(numbers, 0, end);
	}
}
