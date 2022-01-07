//
// Created by Andika on 21/12/21.
//

#include <iostream>
#include "../../UDT/date.h"

using namespace std;

#ifndef TUGAS_BESAR_USER_H
#define TUGAS_BESAR_USER_H

#define user_info(P) (P)->info
#define user_next(P) (P)->next
#define user_first(L) ((L).first)

#define null nullptr

struct user {
    string id;
    string nama, email, password;
    bool apakahAdmin;
    bool akunAktif;
    date tanggalDaftar;
};

typedef struct user infotype;
typedef struct user_node *user_address;

struct user_node {
    infotype info;
    user_address next;
};

struct user_list {
    user_address first;
};

// Basic Function
void user_create_list(user_list &l);
user_address user_new_element(infotype value);
void user_insert_last(user_list &l, user_address p);

// Admin Function
user_address user_search_email(user_list &l, string email);
void user_change_status(user_address p, int status);

// Auth Function
bool user_is_email_registered(user_list l, string email);
user_address user_search_credential(user_list l, string email, string password);
void user_logout(user_address &p);

#endif //TUGAS_BESAR_USER_H
