#ifndef  FUNCTIONS_H
#define  FUNCTIONS_H

char* new_field();
int* new_int_array();
int new_ship(int*, enum direction, enum type_of_ship, int, int);
int letter_to_int(char);
int* init_field(int*);
int* init_field_random(int*);
void print_field(char*, int*);
void print_fields(char*, char*, int*, int*, int*);
int finish_game(int*);
int shot(int*, int, int, int*);
void game(char*, char*, int*, int*, int*, int*, FILE*);
int check(int*, int x, int y); 
int save_game(char*, char*, int*, int*, int*, int*, FILE* );
int cont_game(char*, char*, int*, int*, int*, int*, FILE*);
void new_game(char* , char* , int* , int* , int* , int*, FILE*);
void prev_game(char* , char* , int* , int* , int* , int*, FILE*);

#endif
