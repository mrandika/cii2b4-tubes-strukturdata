//
// Created by Andika on 21/12/21.
//

#include "../user/user.h"

#ifndef TUGAS_BESAR_AUTH_H
#define TUGAS_BESAR_AUTH_H

user_address login(user_list userList, string email, string password);
user_address create_user(user_list userList, user data);

#endif //TUGAS_BESAR_AUTH_H
