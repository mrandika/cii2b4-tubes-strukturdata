//
// Created by Andika on 21/12/21.
//

#include <ctime>
#include "date.h"

date get_today_date() {
    date currentDate;
    time_t now;

    now = time(0);
    tm *ltm = localtime(&now);

    currentDate.tahun = 1900 + ltm->tm_year;
    currentDate.bulan = 1 + ltm->tm_mon;
    currentDate.tanggal = ltm->tm_mday;

    return currentDate;
}