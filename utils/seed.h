//
// Created by Andika on 22/12/21.
//

#include "../modules/user/user.h"
#include "../modules/book/book.h"


#ifndef TUGAS_BESAR_SEED_H
#define TUGAS_BESAR_SEED_H

void populateUserList(user_list &userList);
void populateBookList(book_list &bookList);
void populateBorrower(book_list l, user_list u);

#endif //TUGAS_BESAR_SEED_H
