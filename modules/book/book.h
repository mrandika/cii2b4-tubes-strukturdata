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

typedef struct book book_infotype;
typedef struct book_node *book_address;

struct book_node {
    book_address prev;
    book_infotype info;
    borrow_address first_borrower;
    book_address next;
};

struct book_list {
    book_address first;
    book_address last;
};

void book_create_list(book_list &l);
book_address book_create_element(book_infotype value);

bool book_is_duplicate(book_list &l, string isbn);
void book_insert_first(book_list &l, book_address p);
void book_insert_last(book_list &l, book_address p);
void book_insert_after(book_address prec, book_address p);
void book_insert_ascending(book_list &l, book_address p);

void book_delete_first(book_list &l, book_address p);
void book_delete_last(book_list &l, book_address p);
void book_delete_after(book_address prec, book_address p);
void book_delete(book_list &l, book_address p);

void borrow_delete_first(book_list &l, book_address p);
void borrow_delete_last(book_list &l, book_address p, borrow_address &b);
void borrow_delete_after(borrow_address prec, borrow_address &p);
void borrow_delete_data(book_list &l, book_address book, string id);

void show_book(book_list &l, bool ascending);
void lookup_book(book_list &l, bool byTitle, string key);
book_address search_book(book_list &l, bool byTitle, string key);

void show_book_borrower(book_address book);
void borrowed_book(book_list &l, user_address user);
void show_user_borrowed_book(book_list &l, user_address user);
void show_all_user_borrowed_book(book_list &l, user_list &u);

int get_borrowed_count(book_list l, user_address user);
int get_borrow_id(book_address book);
void borrow_book(book_list l, book_address book, user_address user, bool seed_mode);
void return_book(book_address book, user_address user, string id);

#endif //TUGAS_BESAR_BOOK_H
