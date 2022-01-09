//
// Created by Andika on 21/12/21.
//

#include "menu.h"

int main_menu() {
    int input = 0;

    cout << "=== Selamat Datang di Perpustakaan Universitas X ===" << endl;
    cout << "1. Masuk/Login" << endl;
    cout << "2. Daftar/Register" << endl;
    cout << "0. Exit" << endl << endl;

    cout << "Pilih menu: "; cin >> input;
    return input;
}

int user_menu(user_address user) {
    int input = 0;

    cout << "=== Halo, " << user_info(user).nama << " (user) selamat Datang di Perpustakaan Universitas X ===" << endl;
    cout << "1. Telusuri Buku" << endl;
    cout << "2. Pencarian Buku" << endl;
    cout << "3. Tampilkan Peminjaman Buku" << endl;
    cout << "4. Pinjam Buku" << endl;
    cout << "5. Kembalikan Buku" << endl;
    cout << "0. Logout" << endl << endl;

    cout << "Pilih menu: "; cin >> input;
    return input;
}

int admin_menu(user_address user) {
    int input = 0;

    cout << "=== Halo, " << user_info(user).nama << " (admin) selamat Datang di Perpustakaan Universitas X ===" << endl;
    cout << "1. Tampilkan Semua Buku" << endl;
    cout << "2. Tambahakan Buku" << endl;
    cout << "3. Hapus Buku" << endl;
    cout << "4. Pencarian Buku" << endl;
    cout << "5. Tampilkan Peminjam (Semua)" << endl;
    cout << "6. Tampilkan Peminjam (User)" << endl;
    cout << "7. Non-aktifkan Akun Pengguna" << endl;
    cout << "8. Aktifkan Akun Pengguna" << endl;
    cout << "9. Hapus Data Peminjaman" << endl;
    cout << "0. Logout" << endl << endl;

    cout << "Pilih menu: "; cin >> input;
    return input;
}

void main_menu_selection(int &mainSelection, string &email, string &password, user_list &userList, user_address &userData, user &newUserData) {
    while (mainSelection > 0 && mainSelection <= 2) {
        switch (mainSelection) {
            case 1:
                cout << "Email: "; cin >> email;
                cout << "Password: "; cin >> password;
                userData = login(userList, email, password);

                cout << endl;

                if (userData != null) {
                    mainSelection = -1;
                } else {
                    mainSelection = main_menu();
                }

                break;

            case 2:
                cout << "Nomor ID: "; cin >> newUserData.id;
                cout << "Nama: "; cin >> newUserData.nama;
                cout << "Email: "; cin >> newUserData.email;
                cout << "Password: "; cin >> newUserData.password;
                userData = create_user(userList, newUserData);

                if (userData != null) {
                    mainSelection = -1;
                } else {
                    mainSelection = main_menu();
                }

                break;
        }
    }
}

void user_menu_selection(book_list &bookList, book_address &bookData, user_address &userData, int &subSelection, char &ascending, char &backToMenu, char &byTitle, string &key) {
    while (subSelection >= 0 && subSelection <= 5) {
        switch (subSelection) {
            case 1:
                cout << "Telusuri buku secara ascending? (Y/N): "; cin >> ascending;

                show_book(bookList, tolower(ascending) == 'y');
                cout << endl;

                cout << "Kembali ke menu awal? (Y/N): "; cin >> backToMenu;

                if (tolower(backToMenu) == 'y') {
                    cout << endl;
                    subSelection = user_menu(userData);
                }

                break;
            case 2:
                cout << "Cari buku berdasarkan Judul? (Y/N): "; cin >> byTitle;

                if (tolower(byTitle) == 'y') {
                    cout << "Masukan judul buku: "; cin >> key;
                } else {
                    cout << "Masukan ISBN buku: "; cin >> key;
                }

                lookup_book(bookList, tolower(byTitle) == 'y', key);
                cout << endl;

                cout << "Kembali ke menu awal? (Y/N): "; cin >> backToMenu;

                if (tolower(backToMenu) == 'y') {
                    cout << endl;
                    subSelection = user_menu(userData);
                }

                break;
            case 3:
                cout << "Data buku yang kamu pinjam: " << endl;

                borrowed_book(bookList, userData);
                cout << endl;

                cout << "Kembali ke menu awal? (Y/N): "; cin >> backToMenu;

                if (tolower(backToMenu) == 'y') {
                    cout << endl;
                    subSelection = user_menu(userData);
                }

                break;
            case 4:
                cout << "Cari buku berdasarkan Judul? (Y/N): "; cin >> byTitle;

                if (tolower(byTitle) == 'y') {
                    cout << "Masukan judul buku: "; cin >> key;
                } else {
                    cout << "Masukan ISBN buku: "; cin >> key;
                }

                bookData = search_book(bookList, tolower(byTitle) == 'y', key);

                if (bookData != null) {
                    borrow_book(bookList, bookData, userData, false);
                } else {
                    cout << "Buku tidak ditemukan atau stok habis!";
                }

                cout << endl;

                cout << "Kembali ke menu awal? (Y/N): "; cin >> backToMenu;

                if (tolower(backToMenu) == 'y') {
                    cout << endl;
                    subSelection = user_menu(userData);
                }

                break;
            case 5:
                borrowed_book(bookList, userData);
                cout << endl;

                cout << "Masukan Judul Buku: "; cin >> key;
                bookData = search_book(bookList, true, key);

                cout << "Masukan ID Peminjaman: "; cin >> key;

                return_book(bookData, userData, key);

                cout << endl;

                cout << "Kembali ke menu awal? (Y/N): "; cin >> backToMenu;

                if (tolower(backToMenu) == 'y') {
                    cout << endl;
                    subSelection = user_menu(userData);
                }

                break;
            case 0:
                user_logout(userData);
                subSelection = -1;
        }
    }
}

void admin_menu_selection(book_list &bookList, book_address &bookData, user_list &userList, user_address &userData, int &subSelection, char &ascending, char &backToMenu, char &byTitle, string &key) {
    book book;
    user_address user_result;

    while (subSelection >= 0 && subSelection <= 9) {
        switch (subSelection) {
            case 1:
                cout << "Tampilkan buku secara ascending? (Y/N): "; cin >> ascending;

                show_book(bookList, tolower(ascending) == 'y');
                cout << endl;

                cout << "Kembali ke menu awal? (Y/N): "; cin >> backToMenu;

                if (tolower(backToMenu) == 'y') {
                    cout << endl;
                    subSelection = admin_menu(userData);
                }

                break;

            case 2:
                cout << "ISBN: "; cin >> book.isbn;
                cout << "Judul: "; cin >> book.judul;
                cout << "Penulis: "; cin >> book.penulis;
                cout << "Versi: "; cin >> book.versi;
                cout << "Tanggal Rilis (Tanggal): "; cin >> book.tanggalRilis.tanggal;
                cout << "Tanggal Rilis (Bulan): "; cin >> book.tanggalRilis.bulan;
                cout << "Tanggal Rilis (Tahun): "; cin >> book.tanggalRilis.tahun;
                cout << "Stok: "; cin >> book.stok;

                if (!book_is_duplicate(bookList, book.isbn)) {
                    bookData = book_create_element(book);
                    book_insert_ascending(bookList, bookData);

                    cout << endl;
                } else {
                    cout << "Buku duplikat! ISBN " << book.isbn << " ditemukan pada list." << endl;
                }

                cout << "Kembali ke menu awal? (Y/N): "; cin >> backToMenu;

                if (tolower(backToMenu) == 'y') {
                    cout << endl;
                    subSelection = admin_menu(userData);
                }

                break;

            case 3:
                cout << "Cari buku berdasarkan Judul? (Y/N): "; cin >> byTitle;

                if (tolower(byTitle) == 'y') {
                    cout << "Masukan judul buku: "; cin >> key;
                } else {
                    cout << "Masukan ISBN buku: "; cin >> key;
                }

                bookData = search_book(bookList, tolower(byTitle) == 'y', key);

                if (bookData != null) {
                    book_delete(bookList, bookData);
                } else {
                    cout << "Buku tidak ditemukan atau stok habis!";
                }

                cout << "Kembali ke menu awal? (Y/N): "; cin >> backToMenu;

                if (tolower(backToMenu) == 'y') {
                    cout << endl;
                    subSelection = admin_menu(userData);
                }

                break;

            case 4:
                cout << "Cari buku berdasarkan Judul? (Y/N): "; cin >> byTitle;

                if (tolower(byTitle) == 'y') {
                    cout << "Masukan judul buku: "; cin >> key;
                } else {
                    cout << "Masukan ISBN buku: "; cin >> key;
                }

                bookData = search_book(bookList, tolower(byTitle) == 'y', key);

                if (bookData != null) {
                    borrow_book(bookList, bookData, userData, false);
                } else {
                    cout << "Buku tidak ditemukan atau stok habis!";
                }

                cout << endl;

                cout << "Kembali ke menu awal? (Y/N): "; cin >> backToMenu;

                if (tolower(backToMenu) == 'y') {
                    cout << endl;
                    subSelection = admin_menu(userData);
                }

                break;

            case 5:
                show_all_user_borrowed_book(bookList, userList);

                cout << endl;

                cout << "Kembali ke menu awal? (Y/N): "; cin >> backToMenu;

                if (tolower(backToMenu) == 'y') {
                    cout << endl;
                    subSelection = admin_menu(userData);
                }

                break;
            case 6:
                cout << "Masukan email pengguna: "; cin >> key;

                user_result = user_search_email(userList, key);

                if (user_result != null) {
                    show_user_borrowed_book(bookList, user_result);
                } else {
                    cout << "Pengguna tidak ditemukan!";
                }

                cout << endl;

                cout << "Kembali ke menu awal? (Y/N): "; cin >> backToMenu;

                if (tolower(backToMenu) == 'y') {
                    cout << endl;
                    subSelection = admin_menu(userData);
                }

                break;
            case 7:
                cout << "Masukan email pengguna: "; cin >> key;

                user_result = user_search_email(userList, key);

                if (user_result != null) {
                    user_change_status(user_result, 0);
                } else {
                    cout << "Pengguna tidak ditemukan!";
                }

                cout << endl;

                cout << "Kembali ke menu awal? (Y/N): "; cin >> backToMenu;

                if (tolower(backToMenu) == 'y') {
                    cout << endl;
                    subSelection = admin_menu(userData);
                }

                break;
            case 8:
                cout << "Masukan email pengguna: "; cin >> key;

                user_result = user_search_email(userList, key);

                if (user_result != null) {
                    user_change_status(user_result, 1);
                } else {
                    cout << "Pengguna tidak ditemukan!";
                }

                cout << endl;

                cout << "Kembali ke menu awal? (Y/N): "; cin >> backToMenu;

                if (tolower(backToMenu) == 'y') {
                    cout << endl;
                    subSelection = admin_menu(userData);
                }

                break;
            case 9:
                cout << "Cari buku berdasarkan Judul? (Y/N): "; cin >> byTitle;

                if (tolower(byTitle) == 'y') {
                    cout << "Masukan judul buku: "; cin >> key;
                } else {
                    cout << "Masukan ISBN buku: "; cin >> key;
                }

                bookData = search_book(bookList, tolower(byTitle) == 'y', key);

                if (bookData != null) {
                    show_book_borrower(bookData);

                    cout << "Masukan ID Pinjaman: "; cin >> key;

                    borrow_delete_data(bookList, bookData, key);

                } else {
                    cout << "Buku tidak ditemukan atau stok habis!";
                }

                cout << endl;

                cout << "Kembali ke menu awal? (Y/N): "; cin >> backToMenu;

                if (tolower(backToMenu) == 'y') {
                    cout << endl;
                    subSelection = admin_menu(userData);
                }
                break;

            case 0:
                user_logout(userData);
                subSelection = -1;
        }
    }
}
