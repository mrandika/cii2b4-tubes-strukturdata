//
// Created by Andika on 21/12/21.
//

#include "../user/user.h"

#ifndef TUGAS_BESAR_AUTH_H
#define TUGAS_BESAR_AUTH_H

address login(user_list userList, string email, string password);
address create_user(user_list userList, user data);
int get_first_digit(int id);

#endif //TUGAS_BESAR_AUTH_H
