//
// Created by Andika on 21/12/21.
//

#include "../user/user.h"
#include "../book/book.h"
#include "../auth/auth.h"

#ifndef TUGAS_BESAR_MENU_H
#define TUGAS_BESAR_MENU_H

int main_menu();

int user_menu(user_address user);
int admin_menu(user_address user);

void main_menu_selection(int &mainSelection, string &email, string &password, user_list &userList, user_address &userData, user &newUserData);
void user_menu_selection(book_list &bookList, book_address &bookData, user_address &userData, int &subSelection, char &ascending, char &backToMenu, char &byTitle, string &key);
void admin_menu_selection(book_list &bookList, book_address &bookData, user_list &userList, user_address &userData, int &subSelection, char &ascending, char &backToMenu, char &byTitle, string &key);

#endif //TUGAS_BESAR_MENU_H
