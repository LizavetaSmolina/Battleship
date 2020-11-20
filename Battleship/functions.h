#ifndef  FUNCTIONS_H
#define  FUNCTIONS_H

char* new_field();
int* new_int_array();
int new_ship(int*, enum direction, enum type_of_ship, int, int);
int letter_to_int(char);
int* init_field(int*);
int* init_field_random(int*);
void print_field(char*, int*);
void print_fields(char*, char*, int*, int*);
int finish_game(int*);
int shot(int*, int, int, int*);
void game(char*, char*, int*, int*, int*, int*);

/*char* new_field();
int* new_int_array();
int new_ship(int* field, enum direction dir, enum type_of_ship type, int x, int y);
int letter_to_int(char x);
int* init_field(int* ships);
int* init_field_random(int* ships);
void print_field(char* field, int* ships);
void print_fields(char* user_field, char* computer_field, int* user_ships, int* computer_ships);
int finish_game(int* field);
int shot(int* ships, int x, int y, int* hits);
void game(char* user_field, char* computer_field, int* user_ships, int* computer_ships, int* user_hits, int* computer_hits)*/


#endif
