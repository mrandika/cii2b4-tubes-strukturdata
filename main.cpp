#include <iostream>

#include "utils/seed.h"
#include "modules/menu/menu.h"
#include "modules/auth/auth.h"

using namespace std;

int main() {
    user_list userList;
    address userData;
    int mainSelection, subSelection;

    string email, password;
    user newUserData;

    user_create_list(userList);
    populateUserList(userList);

    mainSelection = main_menu();

    // Component - Main Menu
    while (mainSelection >= 0 && mainSelection <= 2) {
        switch (mainSelection) {
            case 1:
                cout << "Email: "; cin >> email;
                cout << "Password: "; cin >> password;
                userData = login(userList, email, password);

                cout << endl;

                if (userData != null) {
                    mainSelection = -1;
                    cout << "Login berhasil!" << endl;
                } else {
                    mainSelection = main_menu();
                }

                break;

            case 2:
                cout << "Nomor ID: "; cin >> newUserData.id;
                cout << "Nama: "; cin >> newUserData.nama;
                cout << "Email: "; cin >> newUserData.email;
                cout << "Password: "; cin >> newUserData.password;
                userData = create_user(userList, newUserData);

                if (userData != null) {
                    mainSelection = -1;
                    cout << "Registrasi berhasil!" << endl;
                } else {
                    mainSelection = main_menu();
                }
        }
    }

    cout << endl;

    // Component - Sub menu
    if (mainSelection == -1 && user_info(userData).apakahAdmin) {
        cout << user_info(userData).nama << " " << user_info(userData).apakahAdmin << endl;
    } else if (!user_info(userData).apakahAdmin) {
        cout << user_info(userData).nama << " " << user_info(userData).apakahAdmin << endl;
    }

    return 0;
}
