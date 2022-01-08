//
// Created by Andika on 07/01/22.
//

#include "book.h"

void borrow_delete_first(book_list &l, book_address p) {
    borrow_address borrow_node;

    borrow_node = book_first_borrower(p);

    if (borrow_next(borrow_node) == null) {
        book_first_borrower(p) = null;
    } else {
        book_first_borrower(p) = borrow_next(borrow_node);
        borrow_node = null;
    }
}

void borrow_delete_last(book_list &l, book_address p, borrow_address &b) {
    borrow_address borrow_node;

    borrow_node = book_first_borrower(p);

    while (borrow_next(borrow_node) != b) {
        borrow_node = borrow_next(borrow_node);
    }

    b = borrow_next(borrow_node);
    borrow_next(borrow_node) = borrow_next(b);
    borrow_next(b) = null;
}

void borrow_delete_after(borrow_address prec, borrow_address &p) {
    borrow_next(prec) = borrow_next(p);
    prec = null;
}

void borrow_delete_data(book_list &l, book_address book, string id) {
    borrow_address prev_borrow_node, borrow_node;

    borrow_node = book_first_borrower(book);

    if (book_first_borrower(book)->info.id == id) {
        borrow_delete_first(l, book);
    } else if (id == to_string(get_borrow_id(book) - 1)) {
        borrow_delete_last(l, book, borrow_node);
    } else {
        while (borrow_node != null) {
            borrow_delete_after(prev_borrow_node, borrow_node);

            prev_borrow_node = borrow_node;
            borrow_node = borrow_next(borrow_node);
        }
    }
}

int get_borrowed_count(book_list l, user_address user) {
    int num;
    book_address node;
    borrow_address borrow_node;

    num = 0;
    node = book_first(l);

    while (node != null) {
        borrow_node = book_first_borrower(node);

        while (borrow_node != null) {
            if (borrow_node->user == user) {
                num++;
            }

            borrow_node = borrow_next(borrow_node);
        }

        node = book_next(node);
    }

    return num;
}

int get_borrow_id(book_address book) {
    int num;
    borrow_address borrow_node;

    num = 0;
    borrow_node = book_first_borrower(book);

    while (borrow_node != null) {
        num++;
        borrow_node = borrow_next(borrow_node);
    }

    return num + 1;
}

void borrowed_book(book_list &l, user_address user) {
    book book;
    book_address node;
    borrow_address borrow_node;

    node = book_first(l);

    if (book_first(l) != null && book_last(l) != null) {
        while (node != null) {
            book = book_info(node);
            borrow_node = book_first_borrower(node);

            while (borrow_node != null) {
                if (borrow_node->user == user && !borrow_info(borrow_node).sudahKembali) {
                    cout << "ID: " << borrow_info(borrow_node).id + ". " << book.judul << " (" << book.isbn << ") " << endl;
                }

                borrow_node = borrow_next(borrow_node);
            }

            node = book_next(node);
        }
    }
}

void show_book_borrower(book_address book) {
    borrow_address borrow_node;

    if (book != null) {
        borrow_node = book_first_borrower(book);

        while (borrow_node != null) {
            cout << "ID: " << borrow_info(borrow_node).id + ". " << book_info(book).judul << " (" << book_info(book).isbn << ") - " << user_info(borrow_node->user).email << endl;

            borrow_node = borrow_next(borrow_node);
        }
    }
}

void show_user_borrowed_book(book_list &l, user_address user) {
    int num;
    book book;
    book_address book_node;
    borrow_address borrow_node;

    num = 1;
    book_node = book_first(l);

    cout << "Peminjaman " << user_info(user).email << ": " << endl;

    while (book_node != null) {
        borrow_node = book_first_borrower(book_node);

        while (borrow_node != null) {

            if (borrow_node->user == user) {
                cout << num << ". " << book_info(book_node).judul << " pada tanggal " << borrow_info(borrow_node).tanggalPinjam.tanggal << "/" << borrow_info(borrow_node).tanggalPinjam.bulan << "/" << borrow_info(borrow_node).tanggalPinjam.tahun << "." << endl;
                num++;
            }

            borrow_node = borrow_next(borrow_node);
        }

        book_node = book_next(book_node);
    }
}

void show_all_user_borrowed_book(book_list &l, user_list &u) {
    user_address node;

    node = user_first(u);

    if (user_first(u) != null) {
        while (node != null) {
            show_user_borrowed_book(l, node);

            cout << endl;

            node = user_next(node);
        }
    }
}

void borrow_book(book_list l, book_address book, user_address user, bool seed_mode) {
    borrower borrower;
    borrow_address b;
    borrow_address borrow;

    if (get_borrowed_count(l, user) < 3) {
        borrower.id = to_string(get_borrow_id(book));
        borrower.tanggalPinjam = get_today_date();
        borrower.tanggalKembali = get_14d_date();
        borrower.sudahKembali = false;

        borrow = borrow_new_element(borrower);
        borrow_user(borrow) = user;

        if (book_first_borrower(book) == null) {
            book_first_borrower(book) = borrow;
        } else {
            b = book_first_borrower(book);

            while (borrow_next(b) != null) {
                b = borrow_next(b);
            }

            borrow_next(b) = borrow;
        }

        // Reduce the stock
        book_info(book).stok--;

        if (!seed_mode) {
            cout << "Buku " << book_info(book).judul << " berhasil dipinjam." << " Kembalikan buku sebelum " << borrower.tanggalKembali.tanggal << "/" << borrower.tanggalKembali.bulan << "/" << borrower.tanggalKembali.tahun << "." << endl;
        }
    } else {
        if (!seed_mode) {
            cout << "Gagal meminjam buku, kuota peminjaman anda telah habis." << endl;
        }
    }
}

void return_book(book_address book, user_address user, string id) {
    bool found;
    borrow_address borrow;

    found = false;
    borrow = book_first_borrower(book);

    while (borrow != null && !found) {
        if (borrow->user == user && borrow_info(borrow).id == id) {
            found = true;
            book_info(book).stok++;
            borrow_info(borrow).sudahKembali = true;
        } else {
            borrow = borrow_next(borrow);
        }
    }

    if (!found) {
        cout << "Gagal mengembalikan buku!" << endl;
    } else {
        cout << "Buku berhasil dikembalikan, terima kasih!" << endl;
    }
}
