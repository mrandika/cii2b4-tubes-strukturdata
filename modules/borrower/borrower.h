//
// Created by Andika on 24/12/21.
//

#include "../../UDT/date.h"
#include "../user/user.h"

#ifndef TUGAS_BESAR_BORROWER_H
#define TUGAS_BESAR_BORROWER_H

#define borrow_info(P) (P)->info
#define borrow_user(P) (P)->user
#define borrow_next(P) (P)->next

typedef struct borrower borrow_infotype;
typedef struct borrow_node *borrow_address;

struct borrower {
    string id;
    date tanggalPinjam, tanggalKembali;
    bool sudahKembali;
};

struct borrow_node {
    borrow_infotype info;
    user_address user;
    borrow_address next;
};

borrow_address borrow_new_element(borrow_infotype value);

#endif //TUGAS_BESAR_BORROWER_H
