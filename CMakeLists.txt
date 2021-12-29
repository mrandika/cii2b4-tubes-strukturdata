cmake_minimum_required(VERSION 3.20)
project(Tugas_Besar)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tugas_Besar main.cpp modules/user/user.h UDT/date.h modules/user/user.cpp modules/auth/auth.h modules/auth/auth.cpp modules/menu/menu.h modules/menu/menu.cpp UDT/date.cpp utils/seed.h utils/seed.cpp modules/book/book.h modules/borrower/borrower.h)
