#include <stdio.h>

#define DEBUG

int start_lucky_game() {
	int user_number, computer_number;
	int is_win = 0;
	int min_val = 1, max_val = 10;

	computer_number = min_val + rand() % (max_val - min_val + 1);  // [1, 10]

#ifdef DEBUG
	printf("\n*** DEBUG: computer_number = %d ***\n\n", computer_number);
#endif


	printf("It\'s lucky game. Let\'s test your luck.\n\
I thought of a random number between %d and %d, try to guess.\n\n\
Your choose: ", min_val, max_val);

	scanf_s("%d", &user_number);

	if (computer_number == user_number) {
		printf("Oh, no... YOU WIN, I\'m upset... :(\n");
		is_win = 1;
	} else {
		printf("No, my number was %d. ", computer_number);
		printf("Oh yeah, how good I am, and YOU LOST!!!\n");
	}

	return is_win;
}

void start_game_menu(int* is_exit, int* points) {
	int user_input;
	int is_back = 0;

	while (1) {
		system("cls");
		printf("Game menu\n\n\
1. Lucky Game\n\
2. Back\n\
0. Exit\n\
Choose item: ");

		scanf_s("%d", &user_input);

		while (user_input < 0 || user_input > 2) {
			printf("Wrong input. Try again: ");
			scanf_s("%d", &user_input);
		}

		switch (user_input) {
		case 1:
			system("cls");
			int is_win = start_lucky_game();
			if (is_win) {
				*points += 10;
			} else {
				*points -= 10;
			}
			system("pause");
			break;
		case 2:
			is_back = 1;
			break;
		case 0:
			*is_exit = 1;
			break;
		}

		if (is_back) break;
		if (*is_exit) break;
	}
}

void start_main_menu(int* points) {
	int user_input;
	int is_exit = 0;

	while (1) {
		system("cls");
		printf("Main menu\n\n\
1. Play\n\
0. Exit\n\
Choose item: ");

		scanf_s("%d", &user_input);

		while (user_input < 0 || user_input > 1) {
			printf("Wrong input. Try again: ");
			scanf_s("%d", &user_input);
		}

		switch (user_input) {
		case 1:
			system("cls");
			//printf("Game menu is TBD...\n");
			start_game_menu(&is_exit, points);
			//system("pause");
			break;
		case 0:
			is_exit = 1;
			break;
		}

		if (is_exit) break;
	}
}

int main() {
	srand(time(0));

	int points = 0;

	start_main_menu(&points);

	system("cls");
	printf("Your total points by game\'s results: %d\n", points);
	return 0;
}
