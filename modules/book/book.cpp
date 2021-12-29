#include "book.h"

void book_create_list(book_list &l) {
    book_first(l) = NULL;
    book_last(l) = NULL;
}

address book_create_element(infotype value) {
    book_address p = new book_node;
    book_prev(p) = NULL;
    book_info(p) = value;
    book_first_borrower(p) = NULL;
    book_next(p) = NULL;

    return p;
}

void book_insert_first(book_list &l, book_address p) {
    if (book_first != NULL) {
        book_next(p) = book_first(l);
        book_prev(book_next(p)) = p;
        book_first(l) = p;
    } else {
        book_first(l) = p;
        book_last(l) = p;
    }
}

void book_insert_last(book_list &l, book_address p) {
    if (book_last != NULL) {
        book_prev(p) = book_last(l);
        book_next(book_prev(p)) = p;
        book_last(l) = p;
    } else {
        book_first(l) = p;
        book_last(l) = p;
    }
}

void book_insert_after(address prec, book_address p) {
    book_next(p) = book_next(prec);
    book_next(prec) = p;
    book_prev(p) = prec;
    book_prev(book_next(p)) = p;
}

void book_delete_first(list &l, book_address p) {
    if (book_first(l) == NULL) {
        cout << "Kosong" << endl;
    } else if (book_first(l) == book_last(l)) {
        book_first(l) = NULL;
        book_last(l) = NULL;
    } else {
        p = book_first(l);
        book_first(l) = book_next(p);
        p = NULL;
    }
}

void book_delete_last(list &l, book_address p) {
    if (book_last(l) == NULL) {
        cout << "Kosong" << endl;
    } else if (book_first(l) == book_last(l)) {
        book_first(l) = NULL;
        book_last(l) = NULL;
    } else {
        p = book_last(l);
        book_last(l) = book_prev(p);
        p = NULL;
    }
}

void book_delete_after(address prec, book_address p) {
    p = book_next(prec);
    book_next(prec) = book_next(p);
    book_prev(book_next(p)) = prec;
    p = NULL;
}
