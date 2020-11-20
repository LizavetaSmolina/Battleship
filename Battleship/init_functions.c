#include <stdio.h>
#include "functions.h"


char* new_field() {
	char* field = (char*)malloc(10 * 10 * sizeof(char));

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			*(field + i * 10 + j) = '.';
		}
	}
	return field;
}

int* new_int_array() {
	int* field = (int*)malloc(10 * 10 * sizeof(int));

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			*(field + i * 10 + j) = 0;
		}
	}
	return field;
}


enum direction { h, v };
enum type_of_ship { battleship = 1, cruiser = 2, submarine = 3, boat = 4 };

int new_ship(int* field, enum direction dir, enum type_of_ship type, int x, int y) {

	int result = 1;
	switch (type) {
	case boat:
		if (x > 10 || x < 1 || y > 10 || y < 1) return 0;
		x--; y--;
		if (*(field + y * 10 + x) == 1) {
			result = 0;
		}
		else *(field + y * 10 + x) = 1;
		break;
	case submarine:
		if (dir == h) {
			if (x + 1 > 10 || x < 1 || y < 1 || y > 10) return 0;
			x--; y--;
			for (int i = x; i < x + 2; i++) {
				if (*(field + y * 10 + i) == 1) return 0;
			}
			for (int i = x; i < x + 2; i++) {
				*(field + y * 10 + i) = 1;
			}
		}
		else {
			if (x > 10 || x < 1 || y + 1 < 1 || y > 10) return 0;
			x--; y--;
			for (int i = x; i < x + 2; i++) {
				if (*(field + i * 10 + x) == 1) return 0;
			}
			for (int i = x; i < x + 2; i++) {
				*(field + i * 10 + x) = 1;
			}
		}
		break;
	case cruiser:
		if (dir == h) {
			if (x + 2 > 10 || x < 1 || y < 1 || y > 10) return 0;
			x--; y--;
			for (int i = x; i < x + 3; i++) {
				if (*(field + y * 10 + i) == 1) return 0;
			}
			for (int i = x; i < x + 3; i++) {
				*(field + y * 10 + i) = 1;
			}
		}
		else {
			if (x > 10 || x < 1 || y + 2 < 1 || y > 10) return 0;
			x--; y--;
			for (int i = x; i < x + 3; i++) {
				if (*(field + i * 10 + x) == 1) return 0;
			}
			for (int i = x; i < x + 3; i++) {
				*(field + i * 10 + x) = 1;
			}
		}
		break;
	case battleship:
		if (dir == h) {
			if (x + 3 > 10 || x < 1 || y < 1 || y > 10) return 0;
			x--; y--;
			for (int i = x; i < x + 4; i++) {
				if (*(field + y * 10 + i) == 1) return 0;
			}
			for (int i = x; i < x + 4; i++) {
				*(field + y * 10 + i) = 1;
			}
		}
		else {
			if (x > 10 || x < 1 || y + 3 < 1 || y > 10) return 0;
			x--; y--;
			for (int i = x; i < x + 4; i++) {
				if (*(field + i * 10 + x) == 1) return 0;
			}
			for (int i = x; i < x + 4; i++) {
				*(field + i * 10 + x) = 1;
			}
		}
		break;
	}
	return result;
}

int* init_field(int* ships) {
	//enum direction dir;
	int x, y;
	char letter;

	/*printf("1. Dodaj statki jednomasztowe\n");
	for (int i = 0; i < 4; i++) {
		printf("Podaj x literowo:");
		scanf_s(" %c", &letter);
		x = letter_to_int(letter);
		printf("Podaj y cyfrowo:");
		scanf_s("%d", &y);
		if (new_ship(ships, h, boat, x, y) == 0) {
			printf("Nie wolno ustawic statek z podaną kordynatą!\n");
			i = i - 1;
		}
	}

	printf("2. Dodaj statki dwumasztowe\n");
	for (int i = 0; i < 3; i++) {
		printf("Podaj x literowo:");
		scanf_s(" %c", &letter);
		x = letter_to_int(letter);
		printf("Podaj y cyfrowo:");
		scanf_s("%d", &y);
		if (new_ship(ships, h, submarine, x, y) == 0) {
			printf("Nie wolno ustawic statek z podana kordynata!\n");
			i = i - 1;
		}
	}*/

	printf("3. Dodaj statki trzymasztowe\n");
	for (int i = 0; i < 2; i++) {
		printf("Podaj x literowo:");
		scanf_s(" %c", &letter);
		x = letter_to_int(letter);
		printf("Podaj y cyfrowo:");
		scanf_s("%d", &y);
		if (new_ship(ships, h, cruiser, x, y) == 0) {
			printf("Nie wolno ustawic statek z podana koordynata!\n");
			i = i - 1;
		}
	}

	printf("4. Dodaj statki czteromasztowe\n");
	for (int i = 0; i < 1; i++) {
		printf("Podaj x literowo:");
		scanf_s(" %c", &letter);
		x = letter_to_int(letter);
		printf("Podaj y cyfrowo:");
		scanf_s("%d", &y);
		if (new_ship(ships, h, battleship, x, y) == 0) {
			printf("Nie wolno ustawic statek z podana koordynata!\n");
			i = i - 1;
		}
	}

	return ships;
}

int* init_field_random(int* ships) {
	//enum direction dir;
	int y;
	int x;

	/*for (int i = 0; i < 4; i++) {
		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		if (new_ship(ships, h, boat, x - 1, y - 1) == 0) {
			i = i - 1;
		}
	}

	for (int i = 0; i < 3; i++) {
		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		if (new_ship(ships, h, submarine, x - 1, y - 1) == 0) {
			i = i - 1;
		}
	}*/

	for (int i = 0; i < 2; i++) {
		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		if (new_ship(ships, h, cruiser, x - 1, y - 1) == 0) {
			i = i - 1;
		}
	}

	for (int i = 0; i < 1; i++) {
		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		if (new_ship(ships, h, battleship, x - 1, y - 1) == 0) {
			i = i - 1;
		}
	}

	return ships;
}

