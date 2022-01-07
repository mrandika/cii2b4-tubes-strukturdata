#include "borrower.h"

borrow_address borrow_new_element(borrow_infotype value) {
    borrow_address p = new borrow_node;
    borrow_info(p) = value;
    user_next(p) = NULL;
    borrow_next(p) = NULL;

    return p;
}