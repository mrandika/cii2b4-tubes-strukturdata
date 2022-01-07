#include <iostream>
#include "user.h"

using namespace std;

void user_create_list(user_list &l) {
    user_first(l) = null;
}

user_address user_new_element(infotype value) {
    user_address newNode;

    newNode = new user_node;

    user_info(newNode) = value;
    user_next(newNode) = null;

    return newNode;
}

void user_insert_last(user_list &l, user_address p) {
    user_address node;

    if (user_first(l) == null) {
        user_first(l) = p;
    } else {
        node = user_first(l);

        while (user_next(node) != null) {
            node = user_next(node);
        }

        user_next(node) = p;
    }
}

user_address user_search_email(user_list &l, string email) {
    bool found;
    user_address node;

    node = user_first(l);
    found = false;

    while (node != null && !found) {
        if (user_info(node).email == email) {
            found = true;
        } else {
            node = user_next(node);
        }
    }

    if (!found) {
        node = null;
    }

    return node;
}

void user_change_status(user_address p, int status) {
    user_info(p).akunAktif = status;
}

bool user_is_email_registered(user_list l, string email) {
    user_address node;
    bool found;

    node = user_first(l);
    found = false;

    if (user_first(l) != null) {
        while (node != null && !found) {
            if (user_info(node).email == email) {
                found = true;
            } else {
                node = user_next(node);
            }
        }
    }

    return found;
}

user_address user_search_credential(user_list l, string email, string password) {
    user_address node;
    bool found;

    node = user_first(l);
    found = false;

    if (user_first(l) == null) {
        cout << "Data pengguna tidak ditemukan." << endl;
    } else {
        while (node != null && !found) {
            if (user_info(node).email == email && user_info(node).password == password && user_info(node).akunAktif) {
                found = true;
            } else {
                node = user_next(node);
            }
        }
    }

    if (!found) {
        cout << "Login gagal, data login tidak ditemukan!" << endl;
        node = null;
    } else {
        cout << "Login berhasil!" << endl;
    }

    return node;
}

void user_logout(user_address &p) {
    p = null;
}
