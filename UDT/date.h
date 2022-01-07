//
// Created by Andika on 21/12/21.
//

#ifndef TUGAS_BESAR_DATE_H
#define TUGAS_BESAR_DATE_H

struct date {
    int tanggal;
    int bulan;
    int tahun;
};

void date_operation(struct tm* date, int days);

date get_today_date();
date get_14d_date();

#endif //TUGAS_BESAR_DATE_H
