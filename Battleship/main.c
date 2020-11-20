#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {

	srand(time(NULL));
	char* user_field = new_field();
	char* computer_field = new_field();

	int* user_hits = new_int_array();
	int* computer_hits = new_int_array();
	int* user_ships = new_int_array();
	int* computer_ships = new_int_array();

	print_fields(user_field, computer_field, user_ships, computer_ships, user_hits);


	computer_ships = init_field_random(computer_ships);
	//print_field(computer_field, computer_ships);
	user_ships = init_field(user_ships);
	system("cls");

	game(user_field, computer_field, user_ships, computer_ships, user_hits, computer_hits);

	return 0;
}