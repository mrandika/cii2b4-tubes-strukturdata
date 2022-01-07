//
// Created by Andika on 21/12/21.
//

#include <ctime>
#include "date.h"

void date_operation(struct tm* date, int days) {
    const time_t ONE_DAY = 24 * 60 * 60 ;

    time_t date_seconds = mktime( date ) + (days * ONE_DAY);
    *date = *localtime( &date_seconds );
}

date get_today_date() {
    date currentDate;
    time_t now;

    now = time(nullptr);
    tm *ltm = localtime(&now);

    currentDate.tahun = 0;
    currentDate.bulan = 0;
    currentDate.tanggal = 0;

    currentDate.tahun = 1900 + ltm->tm_year;
    currentDate.bulan = 1 + ltm->tm_mon;
    currentDate.tanggal = ltm->tm_mday;

    return currentDate;
}

date get_14d_date() {
    date addedDate;
    struct tm date = { 0, 0, 12 };

    int year = get_today_date().tahun;
    int month = get_today_date().bulan;
    int day = get_today_date().tanggal;

    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;

    date_operation(&date, 14);

    addedDate.tahun = 1900 + date.tm_year;
    addedDate.bulan = 1 + date.tm_mon;
    addedDate.tanggal = date.tm_mday;

    return addedDate;
}