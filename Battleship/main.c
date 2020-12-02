#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include "functions.h"
#include "curses.h"


#define WIDTH 30
#define HEIGHT 10 

int startx = 0;
int starty = 0;

char* choices[] = {
			"1.New game",
			"2.Continue",
			"3.Save",
			"4.Exit",
};
int n_choices = sizeof(choices) / sizeof(char*);


void print_menu(WINDOW* menu_win, int highlight)
{
	int x, y, i;

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for (i = 0; i < n_choices; ++i)
	{
		if (highlight == i + 1)
		{
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}

int menu(char* user_field, char* computer_field, int* user_ships, int* computer_ships, int* user_hits, int* computer_hits, FILE* game_file) {
	WINDOW* menu_win;
	int highlight = 1;
	int choice = 0;
	int c;

	initscr();
	clear();
	noecho();
	cbreak();
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;

	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
	refresh();
	print_menu(menu_win, highlight);
	while (1)
	{

		c = wgetch(menu_win);
		switch (c)
		{
		case KEY_UP:
			if (highlight == 1)
				highlight = n_choices;
			else
				--highlight;
			break;
		case KEY_DOWN:
			if (highlight == n_choices)
				highlight = 1;
			else
				++highlight;
			break;
		case 10:
			choice = highlight;
			break;

		default:
			break;
		}
		print_menu(menu_win, highlight);
		if (choice == 1) {
			system("cls");
			new_game(user_field, computer_field, user_ships, computer_ships, user_hits, computer_hits, game_file);
			clrtoeol();
			refresh();
			endwin();
			return 1;
		}
		
		if (choice == 2) {
			if (cont_game(user_field, computer_field, user_ships, computer_ships, user_hits, computer_hits, &game_file) == 1) {
				system("cls"); 
				prev_game(user_field, computer_field, user_ships, computer_ships, user_hits, computer_hits, &game_file);
			}
			else {
				mvprintw(23, 0, "Unable to load saved game file");
				refresh();
			}
			clrtoeol();
			refresh();
			endwin();
			return 1;
		}

		if (choice == 3) {
			if (save_game(user_field, computer_field, user_ships, computer_ships, user_hits, computer_hits, &game_file) == 1) {
				mvprintw(23, 0, "Your game is saved");
				refresh();
			}
			else {
				mvprintw(23, 0, "Unable to save game file");
				refresh();
			}
		}

		if (choice == 4) {
			clrtoeol();
			refresh();
			endwin();
			return 0;
		} 
	}

	clrtoeol();
	refresh();
	endwin();

}



void main()
{
	srand(time(NULL));
	FILE* game_file;

	char* user_field = new_field();
	char *computer_field = new_field();

	int* user_hits = new_int_array();
	int* computer_hits = new_int_array();
	int* user_ships = new_int_array();
	int* computer_ships = new_int_array();

	while (1) {
		if (menu(user_field, computer_field, user_ships, computer_ships, user_hits, computer_hits, &game_file) == 0) break;
	}
		
	return 0;
}

