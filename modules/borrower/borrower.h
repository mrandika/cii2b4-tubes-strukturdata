//
// Created by Andika on 24/12/21.
//

#include "../../UDT/date.h"
#include "../user/user.h"

#ifndef TUGAS_BESAR_BORROWER_H
#define TUGAS_BESAR_BORROWER_H

#define borrow_info(P) (P)->info
#define borrow_next(P) (P)->next
#define borrow_first(L) ((L).first)

struct borrower {
    string id;
    int denda;
    date tanggalPinjam, tanggalKembali;
    bool sudahKembali;
};

typedef struct borrower infotype;
typedef struct borrow_node *borrow_address;

struct borrow_node {
    infotype info;
    user_address user;
    borrow_address next;
};

// Basic Function
borrow_address borrow_new_element(infotype value);
void borrow_insert_last(user_list &l, borrow_address p);
void borrow_delete_first(user_list &l, borrow_address &p);
void borrow_delete_last(user_list &l, borrow_address &p);
void borrow_delete_after(user_list &l, borrow_address prec, borrow_address &p);

#endif //TUGAS_BESAR_BORROWER_H
