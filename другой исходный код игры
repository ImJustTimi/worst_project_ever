#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define DEBUG
#define COUNT_OF_GAME_ITEMS 2
#define TEXT_FOR_GAME_MENU "1. LuckyGame\n2. Back\n0. Exit\nChoose item: "
#define TEXT_FOR_START_MENU "1. Play\n0. Exit\nChoose item: "

int start_lucky_game() {
  int is_win = 0;
  int leftbound = 1, rightbound = 10;
  int user_number, computer_number;
  computer_number = leftbound + rand()%(rightbound - leftbound + 1);
#ifdef DEBUG
  printf("* DEBUG: true anwser: %d *\n", computer_number);
#endif
  printf("It\'s test of your lucky.\n\
I guessed number from %d to %d. Try to guess it. Your input:", leftbound,rightbound);
  scanf_s("%d", &user_number);
  if (user_number == computer_number) {
    is_win = 1;
  }
  return is_win;
}
void start_game_menu(int* is_exit) {
  int user_input;
  int is_back = 0;
  while (1) {
    printf(TEXT_FOR_GAME_MENU);
    scanf_s("%d", &user_input);

    if (user_input < 0  user_input > COUNT_OF_GAME_ITEMS) {
      printf("Wrong choose(\n");
      system("pause");
      system("cls");
      continue;
    }
    if (user_input == 0) *is_exit = 1;
    if (*is_exit) break;

    if (user_input == COUNT_OF_GAME_ITEMS) is_back = 1;
    if (is_back) break;
    
    system("cls");

    if (user_input == 1) {
      int is_win = start_lucky_game();
      if (is_win) {
        printf("U win\n");
      }
      else {
        printf("U lose(\n");
      }
      system("pause");
    }
  }
}
    void start_main_menu() {
      int user_input;
      int is_exit = 0;
      while (!is_exit) {
        printf(TEXT_FOR_START_MENU);
        scanf_s("%d", &user_input);

        if (user_input < 0  user_input > 1) {
          printf("Wrong choose(\n");
          system("pause");
          system("cls");
          continue;
        }
        if (user_input == 0) is_exit = 1;
        if (is_exit) break;

        system("cls");

        if (user_input == 1) {
          start_game_menu(&is_exit);
        }
      }
    }

int main() {
  srand(time(0));
  start_main_menu();
  return 0;
}
//ДЗ сделать меню настроек, там добавить уровни сложности
