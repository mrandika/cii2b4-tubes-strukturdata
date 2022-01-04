#include "user.h"

void user_create_list(user_list &l) {
    user_first(l) = NULL
}

user_address user_new_element(infotype value) {
    user_address p = new user_node;
    user_info(p) = value;
    user_next(p) = NULL
}

void user_insert_first(user_list &l, user_address p) {
    if (user_first(l) != NULL) {
        next(p) = user_first(l);
        user_first(l) = p;
    } else {
        user_first(l) = p;
    }
}

void user_insert_last(user_list &l, user_address p) {
    if (user_first(l) != NULL) {
        user_address q = user_first(l);
        while (user_next(q) != NULL) {
            q = user_next(q);
        }
        user_next(q) = p;
    } else {
        user_first(l) = p;
    }
}

void user_delete_first(user_list &l, user_address &p) {
    if (user_first(l) == NULL) {
        cout << "Kosong" << endl;
    } else if (next(user_first(l)) == NULL) {
        user_first(l) = NULL;
    } else {
        p = user_first(l);
        user_first(l) = user_next(p);
        p = NULL;
    }
}

void user_delete_last(user_list &l, user_address &p) {
    user_address q;
    if (user_first(l) == NULL) {
        cout << "Kosong" << endl;
    } else if (next(user_first(l)) == NULL) {
        user_first(l) = NULL;
    } else {
        p = user_first(l);
        while (user_next(p) != NULL) {
            p = user_next(p);
        }
        p = NULL;
    }
}

void user_delete_after(user_list &l, user_address prec, user_address &p) {
    if (user_first(l) == NULL) {
        cout << "Kosong" << endl;
    } else if (user_next(user_first(l) == NULL)) {
        user_first(l) = NULL;
    } else {
        p = user_next(prec);
        user_next(prec) = user_next(p);
        p = NULL;
    }
}

bool user_is_email_registered(user_list l, string email) {

}

user_address user_search_credential(user_list l, string email, string password) {

}
