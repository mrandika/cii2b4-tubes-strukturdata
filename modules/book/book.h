//
// Created by Andika on 24/12/21.
//

#include "../../UDT/date.h"
#include "../borrower/borrower.h"

#ifndef TUGAS_BESAR_BOOK_H
#define TUGAS_BESAR_BOOK_H

#define book_info(P) (P)->info
#define book_prev(P) (P)->prev
#define book_next(P) (P)->next
#define book_first_borrower(P) (P)->first_borrower
#define book_first(L) ((L).first)
#define book_last(L) ((L).last)

struct book {
    string isbn, judul, penulis, versi;
    date tanggalRilis;
    int stok;
};

typedef struct book infotype;
typedef struct book_node *book_address;

struct book_node {
    book_address prev;
    infotype info;
    borrow_address first_borrower;
    book_address next;
};

struct book_list {
    book_address first;
    book_address last;
};

void book_create_list(book_list &l);
address book_create_element(infotype value);

void book_insert_irst(book_list &l, book_address p);
void book_insert_last(book_list &l, book_address p);
void book_insert_after(address prec, book_address p);

void book_delete_first(list &l, book_address p);
void book_delete_last(list &l, book_address p);
void book_delete_after(address prec, book_address p);

#endif //TUGAS_BESAR_BOOK_H
