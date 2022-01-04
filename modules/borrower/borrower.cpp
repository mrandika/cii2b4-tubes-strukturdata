#include "borrower.h"

borrow_address borrow_new_element(infotype value) {
    borrow_address p = new borrow_node;
    borrow_info(p) = value;
    user_next(p) = NULL;
    borrow_next(p) = NULL;

    return p;
}

void borrow_insert_last(user_list &l, borrow_address p) {
    if (borrow_first(l) != NULL) {
        borrow_address q = borrow_first(l);
        while (borrow_next(q) != NULL) {
            q = borrow_next(q);
        }
        borrow_next(q) = p;
    } else {
        borrow_first(l) = p;
    }
}

void borrow_delete_first(user_list &l, borrow_address &p) {
    if (borrow_first(l) == NULL) {
        cout << "Kosong" << endl;
    } else if (next(borrow_first(l)) == NULL) {
        borrow_first(l) = NULL;
    } else {
        p = borrow_first(l);
        borrow_first(l) = borrow_next(p);
        p = NULL;
    }
}

void borrow_delete_last(user_list &l, borrow_address &p) {
    if (borrow_first(l) == NULL) {
        cout << "Kosong" << endl;
    } else if (borrow_next(borrow_first(l)) == NULL) {
        borrow_first(l) = NULL;
    } else {
        p = borrow_first(l);
        while (borrow_next(p) != NULL) {
            p = borrow_next(p);
        }
        p = NULL;
    }
}

void borrow_delete_after(user_list &l, borrow_address prec, borrow_address &p) {
    if (borrow_first(l) == NULL) {
        cout << "Kosong" << endl;
    } else if (borrow_next(borrow_first(l) == NULL)) {
        borrow_first(l) = NULL;
    } else {
        p = borrow_next(prec);
        borrow_next(prec) = borrow_next(p);
        p = NULL;
    }
}
