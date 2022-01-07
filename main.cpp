#include <iostream>

#include "utils/seed.h"
#include "modules/menu/menu.h"

using namespace std;

int main() {
    user_list userList;
    user_address userData;

    book_list bookList;
    book_address bookData;

    int mainSelection, subSelection;

    char ascending;
    char backToMenu;
    char byTitle;

    string key;

    string email, password;
    user newUserData;

    /*
     * Populate the list with dummy data
     */
    user_create_list(userList);
    populateUserList(userList);

    book_create_list(bookList);
    populateBookList(bookList);

    populateBorrower(bookList, userList);

    mainSelection = main_menu();

    // Component - Main Menu
    main_menu_selection(mainSelection, email, password, userList, userData, newUserData);

    // Component - Sub menu
    if (mainSelection == -1 && user_info(userData).apakahAdmin) {
        subSelection = admin_menu(userData);

        admin_menu_selection(bookList, bookData, userList, userData, subSelection, ascending, backToMenu, byTitle, key);
    } else if (!user_info(userData).apakahAdmin) {
        subSelection = user_menu(userData);

        user_menu_selection(bookList, bookData, userData, subSelection, ascending, backToMenu, byTitle, key);
    }

    cout << "Program Selesai!" << endl;

    return 0;
}
