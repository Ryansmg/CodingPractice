#include <stdio.h>

struct chulpansa {
    int code;
    char name[20];
    char tel[15];
};

struct bookname {
    char b_name[20];
    char w_name[20];
    char year[12];
    int price;
    int su;
};

struct book_store {
    struct chulpansa chull;
    struct bookname book;
};

int main()
{
    struct book_store sale = {10, "생능출판사", "031-912-2398", "아주쉬운C언어", "권기석", "1998/04/02", 10000, 5};
    int ssang = sale.book.price*sale.book.su;
    printf("출판사 : %s\n제목 : %s\n판매금액 : %d\n", sale.chull.name, sale.book.b_name, ssang);
}