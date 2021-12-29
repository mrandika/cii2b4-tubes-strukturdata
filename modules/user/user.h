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
void user_insert_first(user_list &l, user_address p);
void user_insert_last(user_list &l, user_address p);
void user_delete_first(user_list &l, user_address &p);
void user_delete_last(user_list &l, user_address &p);
void user_delete_after(user_list &l, user_address prec, user_address &p);

// Auth Function
bool user_is_email_registered(user_list l, string email);
user_address user_search_credential(user_list l, string email, string password);

#endif //TUGAS_BESAR_USER_H
