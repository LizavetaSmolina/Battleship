#include <stdio.h>
#include "functions.h"

void print_field(char* field, int* ships) {
	printf("   A B C D E F G H I J\n");
	for (int i = 0; i < 22; i++) {
		printf("_");
	}
	printf("\n");

	for (int i = 0; i < 10; i++) {
		if (i < 9) printf("%d |", i + 1);
		else printf("%d|", i + 1);

		for (int j = 0; j < 10; j++) {
			if (*(ships + i * 10 + j) == 1) *(field + i * 10 + j) = 'O';
			printf("%c ", *(field + i * 10 + j));
		}
		printf("\n");
	}
}

void print_fields(char* user_field, char* computer_field, int* user_ships, int* computer_ships, int* user_hits) {
	printf("   USER                		   COMPUTER           \n\n");
	printf("   A B C D E F G H I J		   A B C D E F G H I J\n");
	for (int i = 0; i < 22; i++) {
		printf("_");
	}
	printf("		");
	for (int i = 0; i < 22; i++) {
		printf("_");
	}
	printf("\n");

	for (int i = 0; i < 10; i++) {
		if (i < 9) printf("%d |", i + 1);
		else printf("%d|", i + 1);

		for (int j = 0; j < 10; j++) {
			if (*(user_ships + i * 10 + j) == 1) *(user_field + i * 10 + j) = 'O';
			if (*(user_ships + i * 10 + j) == 2) *(user_field + i * 10 + j) = 'X';
			printf("%c ", *(user_field + i * 10 + j));
		}
		printf("		");

		if (i < 9) printf("%d |", i + 1);
		else printf("%d|", i + 1);

		for (int j = 0; j < 10; j++) {
			if (*(computer_ships + i * 10 + j) == 2) {
				*(computer_field + i * 10 + j) = 'X';
				printf("%c ", *(computer_field + i * 10 + j));
			}
			else if (*(computer_ships + i * 10 + j) != 2 && *(user_hits + i * 10 + j) == 1) {
				*(computer_field + i * 10 + j) = '*';
				printf("%c ", *(computer_field + i * 10 + j));
			}
			else printf(". ");
		}
		printf("\n");
	}
	printf("\n");
}

int letter_to_int(char x) {
	switch (x) {
	case 'A': case 'a': return 1;
	case 'B': case 'b': return 2;
	case 'C': case 'c': return 3;
	case 'D': case 'd': return 4;
	case 'E': case 'e': return 5;
	case 'F': case 'f': return 6;
	case 'G': case 'g': return 7;
	case 'H': case 'h': return 8;
	case 'I': case 'i': return 9;
	case 'J': case 'j': return 10;
	default: return 0;
	}
}
