//
// Created by Andika on 30/12/21.
//

#include "book.h"

void book_create_list(book_list &l) {
    book_first(l) = null;
    book_last(l) = null;
}

book_address book_create_element(book_infotype value) {
    book_address p = new book_node;
    book_prev(p) = null;
    book_info(p) = value;
    book_first_borrower(p) = null;
    book_next(p) = null;

    return p;
}

bool book_is_duplicate(book_list &l, string isbn) {
    bool duplicate;
    book book;
    book_address node;

    duplicate = false;
    node = book_first(l);

    if (book_first(l) != null && book_last(l) != null) {
        while (node != null && !duplicate) {
            book = book_info(node);

            if (book_info(node).isbn == isbn) {
                duplicate = true;
            }

            node = book_next(node);
        }
    }

    return duplicate;
}

void book_insert_first(book_list &l, book_address p) {
    if (book_first(l) != null) {
        book_next(p) = book_first(l);
        book_prev(book_next(p)) = p;
        book_first(l) = p;
    } else {
        book_first(l) = p;
        book_last(l) = p;
    }
}

void book_insert_last(book_list &l, book_address p) {
    if (book_last(l) != null) {
        book_prev(p) = book_last(l);
        book_next(book_prev(p)) = p;
        book_last(l) = p;
    } else {
        book_first(l) = p;
        book_last(l) = p;
    }
}

void book_insert_after(book_address prec, book_address p) {
    book_next(p) = book_next(prec);
    book_prev(p) = prec;
    book_prev(book_next(prec)) = p;
    book_next(prec) = p;
}

void book_insert_ascending(book_list &l, book_address p) {
    book_address node;

    if ((book_first(l) == null && book_last(l) == null) || book_info(p).judul.compare(book_info(book_first(l)).judul) < 0) {
        // Insert First
        book_insert_first(l, p);
    } else if (book_info(p).judul.compare(book_info(book_last(l)).judul) > 0) {
        // Insert Last
        book_insert_last(l, p);
    } else {
        node = book_first(l);

        while (node != null && book_info(p).judul.compare(book_info(node).judul) > 0) {
            node = book_next(node);
        }

        book_insert_after(book_prev(node), p);
    }
}

void book_delete_first(book_list &l, book_address p) {
    p = book_first(l);

    if (book_next(p) == null) {
        book_first(l) = null;
        book_last(l) = null;
    } else {
        book_first(l) = book_next(book_first(l));
        book_prev(book_first(l)) = null;
        book_next(p) = null;
    }
}

void book_delete_last(book_list &l, book_address p) {
    p = book_last(l);

    if (book_first(l) != null && book_last(l) != null) {
        p = book_last(l);
        book_last(l) = book_prev(book_last(l));
        book_prev(p) = null;
        book_next(book_last(l)) = null;
    } else {
        p = book_first(l);
        book_first(l) = null;
        book_last(l) = null;
    }
}

void book_delete_after(book_address prec, book_address p) {
    p = book_next(prec);
    book_next(prec) = book_next(p);
    book_prev(book_next(p)) = prec;
    book_next(p) = null;
    book_prev(p) = null;
}

void book_delete(book_list &l, book_address p) {
    book_address node;

    if (p == book_first(l)) {
        book_delete_first(l, p);
    } else if (p == book_last(l)) {
        book_delete_last(l, p);
    } else {
        node = book_first(l);

        while (book_info(node).isbn != book_info(p).isbn) {
            node = book_next(node);
        }

        book_delete_after(book_prev(node), book_last(l));
    }
}

void show_book(book_list &l, bool ascending) {
    int num;
    book book;
    book_address node;

    if (ascending) {
        node = book_first(l);
    } else {
        node = book_last(l);
    }

    if (book_first(l) != null && book_last(l) != null) {
        num = 1;
        while (node != null) {
            book = book_info(node);

            if (book_info(node).stok > 0) {
                cout << to_string(num) + ". " << book.judul << " (" << book.isbn << ")" << ", tersedia " << book.stok << endl;
                num++;
            }

            if (ascending) {
                node = book_next(node);
            } else {
                node = book_prev(node);
            }
        }
    }
}

void lookup_book(book_list &l, bool byTitle, string key) {
    int num;
    book book;
    book_address node;
    bool found;

    node = book_first(l);

    if (book_first(l) != null && book_last(l) != null) {
        num = 0;
        while (node != null && book_info(node).stok > 0 && !found) {
            book = book_info(node);

            if (book.judul == key || book.isbn == key) {
                found = true;
            }

            node = book_next(node);
            num++;
        }

        if (byTitle) {
            cout << "Buku dengan judul " << key;
        } else {
            cout << "Buku dengan ISBN " << key;
        }

        if (!found) {
            node = null;

            cout << " tidak ditemukan" << endl;
        } else {
            cout << " ditemukan pada baris " << num << endl;
        }
    }
}

book_address search_book(book_list &l, bool byTitle, string key) {
    book book;
    book_address node;
    bool found;

    node = book_first(l);
    found = false;

    if (book_first(l) != null && book_last(l) != null) {
        while (node != null && !found) {
            book = book_info(node);

            if (book.judul == key || book.isbn == key) {
                found = true;
            } else {
                node = book_next(node);
            }
        }
    }

    if (!found) {
        node = null;
    }

    return node;
}