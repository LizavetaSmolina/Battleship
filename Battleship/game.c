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

		printf("Podaj x:");
		scanf_s(" %c", &letter);

		x = letter_to_int(letter);
		printf("Podaj y:");
		scanf_s("%d", &y);

		while (shot(computer_ships, x, y, user_hits) == 0) {
			printf("Podana koordytana już niedostępna! \n");
			printf("Podaj x:");
			scanf_s(" %c", &letter);
			x = letter_to_int(letter);
			printf("Podaj y:");
			scanf_s("%d", &y);
		}
		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		while (shot(user_ships, x, y, computer_hits) == 0) {

			x = rand() % 10 + 1;
			y = rand() % 10 + 1;
		}
		system("cls");
	}

	print_fields(user_field, computer_field, user_ships, computer_ships, user_hits);
	if (finish_game(computer_ships) == 1) printf("UZYTKOWNIK WYGRAL!");
	else if (finish_game(user_ships) == 1) printf("UZYTKOWNIK PRZEGRAL!");
}
