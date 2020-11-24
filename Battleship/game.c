#include <stdio.h>
#include "functions.h"

int finish_game(int* field) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (*(field + i * 10 + j) == 1) return 0;
		}
	}
	return 1;
}

int shot(int* ships, int x, int y, int* hits) {
	if (x > 10 || x < 0 || y > 10 || y < 0) return 0;

	x--; y--;
	if (*(hits + y * 10 + x) == 1) return 0;
	else *(hits + y * 10 + x) = 1;

	if (*(ships + y * 10 + x) == 1) {
		*(ships + y * 10 + x) = 2;
	}
	return 1;
}


void game(char* user_field, char* computer_field, int* user_ships, int* computer_ships, int* user_hits, int* computer_hits) {

	int x, y; 
	char letter;

	while (finish_game(user_ships) == 0 && finish_game(computer_ships) == 0) {
		print_fields(user_field, computer_field, user_ships, computer_ships, user_hits);

		int s = 0;
		while (s == 0) {
			printf("Podaj x literowo:");
			scanf_s(" %c", &letter);

			x = letter_to_int(letter);
			printf("Podaj y cyfrowo:");
			scanf_s("%d", &y);
			s = shot(computer_ships, x, y, user_hits);
		}

		s = 0;
		while (s == 0) {
			x = rand() % 10 + 1;
			y = rand() % 10 + 1;
			s = shot(user_ships, x, y, computer_hits);
		}
		system("cls");
	}

	print_fields(user_field, computer_field, user_ships, computer_ships, user_hits);
	if (finish_game(computer_ships) == 1) printf("UZYTKOWNIK WYGRAL!"); 
	else if (finish_game(user_ships) == 1) printf("UZYTKOWNIK PRZEGRAL!");
}

void save_game(char* user_field, char* computer_field, int* user_ships, int* computer_ships, int* user_hits, int* computer_hits, FILE* file) {

	if (fopen_s(&file, "game.txt", "w") != 0) {
		printf("Cannot open file.\n");
		exit(1);
	}
	else {
		fprintf(file, "   USER                		   COMPUTER           \n\n");
		fprintf(file, "   A B C D E F G H I J		   A B C D E F G H I J\n");
		for (int i = 0; i < 22; i++) {
			fprintf(file, "_");
		}
		fprintf(file, "		");
		for (int i = 0; i < 22; i++) {
			fprintf(file, "_");
		}
		fprintf(file, "\n");

		for (int i = 0; i < 10; i++) {
			if (i < 9) fprintf(file, "%d |", i + 1);
			else fprintf(file, "%d|", i + 1);

			for (int j = 0; j < 10; j++) {
				if (*(user_ships + i * 10 + j) == 1) *(user_field + i * 10 + j) = 'O';
				if (*(user_ships + i * 10 + j) == 2) *(user_field + i * 10 + j) = 'X';
				fprintf(file, "%c ", *(user_field + i * 10 + j));
			}
			fprintf(file, "		");

			if (i < 9) fprintf(file, "%d |", i + 1);
			else fprintf(file, "%d|", i + 1);

			for (int j = 0; j < 10; j++) {
				if (*(computer_ships + i * 10 + j) == 2) {
					*(computer_field + i * 10 + j) = 'X';
					fprintf(file, "%c ", *(computer_field + i * 10 + j));
				}
				else if (*(computer_ships + i * 10 + j) != 2 && *(user_hits + i * 10 + j) == 1) {
					*(computer_field + i * 10 + j) = '*';
					fprintf(file, "%c ", *(computer_field + i * 10 + j));
				}
				else fprintf(file, ". ");
			}
			fprintf(file, "\n");
		}
		fprintf(file, "\n");
		fclose(file);
	}
}