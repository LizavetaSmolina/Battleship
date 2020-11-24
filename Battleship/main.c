#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include "functions.h"

int main() {

	srand(time(NULL));
	FILE* game_file;
		//= creat("file.txt", S_IREAD | S_IWRITE);;

	char* user_field = new_field();
	char* computer_field = new_field();

	int* user_hits = new_int_array();
	int* computer_hits = new_int_array();
	int* user_ships = new_int_array();
	int* computer_ships = new_int_array();

	print_fields(user_field, computer_field, user_ships, computer_ships, user_hits);


	computer_ships = init_field_random(computer_ships);
	print_field(computer_field, computer_ships);
	user_ships = init_field(user_ships);
	system("cls");

	game(user_field, computer_field, user_ships, computer_ships, user_hits, computer_hits);

	save_game(user_field, computer_field, user_ships, computer_ships, user_hits, computer_hits, &game_file);

	return 0;
}