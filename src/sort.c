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

/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>

typedef struct Header header;

typedef enum {
	GET, POST
} method_type;

struct Header {
	method_type method;
	char *host;
	char *path;
};

char *buildRequest(header h) {
	char *request = malloc(strlen(h.host));
	char *method = NULL;
	if (h.method == GET) {
		method = "GET";
	} else {
		method = "POST";
	}
	sprintf(request, "%s %s HTTP.1.0\n", method, h.path);
	sprintf(request + strlen(request), "Host: %s\n", h.host);
	return request;
}

header createHTTPHeader(char* host, char* path, method_type method) {
	header h;
	h.host = malloc(strlen(host));
	h.path = malloc(strlen(path));
	strcpy(h.host, host);
	strcpy(h.path, path);
	h.method = method;
	return h;
}

int main() {
	char *host = "linuxdev.windchill:8080";
	char *path = "/Windchill";
	header h = createHTTPHeader(host, path, GET);
//	size_t len = strlen(host);
//	h.host = malloc(len);
//	strcpy(h.host, host);
	char *request = buildRequest(h);
	int socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if (socket_desc == -1) {
		printf("Could not create socket");
		return 0;
	}
	struct addrinfo hints;
	struct addrinfo *res;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0;

	getaddrinfo("linuxdev.windchill", "8080", &hints, &res);
	int connect_desc = connect(socket_desc, res->ai_addr, res->ai_addrlen);
	if (connect_desc == -1) {
		printf("Could not connect");
		return 0;
	}
	printf("Connected!\n");

	send(socket_desc, request, sizeof request, 0);

	char buf[2056];
	int byte_count;
	byte_count = recv(socket_desc, buf, sizeof(buf) - 1, 0); // <-- -1 to leave room for a null terminator
	buf[byte_count] = 0; // <-- add the null terminator
	printf("recv()'d %d bytes of data in buf\n", byte_count);
	printf("%s", buf);
	return 0;
}


 */
