//
// Created by Andika on 22/12/21.
//

#include "seed.h"

void populateUserList(user_list &userList) {
    user userData;
    user_address user;

    for (int i = 0; i < 10; i++) {
        string uid = to_string(i);

        userData.id = uid + "100101";
        userData.nama = "Pengguna " + uid;
        userData.email = "pengguna" + uid + "@xuniversity.ac.id";
        userData.password = "password" + uid;
        userData.apakahAdmin = i == 3;
        userData.akunAktif = true;

        user = user_new_element(userData);
        user_insert_last(userList, user);
    }
}

void populateBookList(book_list &bookList) {
    book bookData;
    book_address book;

    for (int i = 75; i < 80; i++) {
        char uid = (char)i;

        bookData.judul = "";
        bookData.versi = "";

        bookData.isbn = to_string(i) + "-" + "123-098-567";
        bookData.judul.push_back(uid);
        bookData.penulis = "Penulis " + to_string(i);

        bookData.versi = "1-REV-";
        bookData.versi.push_back(uid);

        bookData.tanggalRilis.tanggal = 15;
        bookData.tanggalRilis.bulan = 3;
        bookData.tanggalRilis.tahun = 2021;
        bookData.stok = 3;

        book = book_create_element(bookData);
        book_insert_ascending(bookList, book);
    }

    for (int i = 65; i < 70; i++) {
        char uid = (char)i;

        bookData.judul = "";
        bookData.versi = "";

        bookData.isbn = to_string(i) + "-" + "123-098-567";
        bookData.judul.push_back(uid);
        bookData.penulis = "Penulis " + to_string(i);

        bookData.versi = "1-REV-";
        bookData.versi.push_back(uid);

        bookData.tanggalRilis.tanggal = 15;
        bookData.tanggalRilis.bulan = 3;
        bookData.tanggalRilis.tahun = 2021;
        bookData.stok = 3;

        book = book_create_element(bookData);
        book_insert_ascending(bookList, book);
    }
}

void populateBorrower(book_list l, user_list u) {
    book_address book;
    user_address user;

    book = search_book(l, true, "A");
    user = user_search_email(u, "pengguna0@xuniversity.ac.id");
    borrow_book(l, book, user, true);

    user = user_search_email(u, "pengguna1@xuniversity.ac.id");
    borrow_book(l, book, user, true);

    user = user_search_email(u, "pengguna2@xuniversity.ac.id");
    borrow_book(l, book, user, true);

    book = search_book(l, true, "B");
    user = user_search_email(u, "pengguna4@xuniversity.ac.id");
    borrow_book(l, book, user, true);

    book = search_book(l, true, "C");
    user = user_search_email(u, "pengguna5@xuniversity.ac.id");
    borrow_book(l, book, user, true);

    user = user_search_email(u, "pengguna6@xuniversity.ac.id");
    borrow_book(l, book, user, true);

    book = search_book(l, true, "D");
    user = user_search_email(u, "pengguna7@xuniversity.ac.id");
    borrow_book(l, book, user, true);

    user = user_search_email(u, "pengguna8@xuniversity.ac.id");
    borrow_book(l, book, user, true);

    book = search_book(l, true, "E");
    user = user_search_email(u, "pengguna8@xuniversity.ac.id");
    borrow_book(l, book, user, true);

    user = user_search_email(u, "pengguna9@xuniversity.ac.id");
    borrow_book(l, book, user, true);

    user = user_search_email(u, "pengguna10@xuniversity.ac.id");
    borrow_book(l, book, user, true);
}