//
// Created by Andika on 21/12/21.
//

#include "auth.h"

user_address login(user_list userList, string email, string password) {
    return user_search_credential(userList, email, password);
}

user_address create_user(user_list userList, user data) {
    bool isEmailAlreadyRegistered;
    user_address userElement;

    userElement = null;
    isEmailAlreadyRegistered = user_is_email_registered(userList, data.email);

    if (isEmailAlreadyRegistered) {
        cout << "Email sudah terdaftar, gunakan email lain!" << endl;
    } else {
        data.tanggalDaftar = get_today_date();
        data.apakahAdmin = data.id[0] == 3 && data.id[1] == 1;
        data.akunAktif = true;

        userElement = user_new_element(data);
        user_insert_last(userList, userElement);
    }

    return userElement;
}