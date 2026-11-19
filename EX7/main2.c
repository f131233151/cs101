/*
 * EX#7 - 第 2 題：書單程式
 * 建立 Books 結構，將 6 筆書籍資料存入 Book.bin，
 * 再透過 total_price() 計算總價，list_books() 輸出書籍資料。
 */

#include <stdio.h>
#include <stdlib.h>

#define BOOK_COUNT 6

typedef struct Books {
    int id;
    int price;
    char title[100];
} book_t;

/* 計算所有書籍的總價 */
int total_price(const book_t books[], int count)
{
    int i;
    int total = 0;

    for (i = 0; i < count; i++) {
        total += books[i].price;
    }

    return total;
}

/* 輸出所有書籍資料 */
void list_books(const book_t books[], int count)
{
    int i;

    printf("%-5s %-8s %s\n", "ID", "Price", "Title");
    printf("--------------------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%-5d %-8d %s\n",
               books[i].id, books[i].price, books[i].title);
    }
}

/* 將書籍結構資料寫入二進位檔案 */
int save_books(const char *filename, const book_t books[], int count)
{
    FILE *fp = fopen(filename, "wb");

    if (fp == NULL) {
        perror("無法建立 Book.bin");
        return 0;
    }

    if (fwrite(books, sizeof(book_t), count, fp) != (size_t)count) {
        perror("寫入 Book.bin 失敗");
        fclose(fp);
        return 0;
    }

    fclose(fp);
    return 1;
}

/* 從二進位檔案讀取書籍結構資料 */
int load_books(const char *filename, book_t books[], int capacity)
{
    FILE *fp = fopen(filename, "rb");
    size_t count;

    if (fp == NULL) {
        perror("無法開啟 Book.bin");
        return -1;
    }

    count = fread(books, sizeof(book_t), capacity, fp);
    fclose(fp);

    return (int)count;
}

int main(void)
{
    book_t books[BOOK_COUNT] = {
        {1, 1000, "All the Light We Cannot See"},
        {2,  300, "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4,  550, "Killers of the Flower Moon"},
        {5,  870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    book_t file_books[BOOK_COUNT];
    int count;

    if (!save_books("Book.bin", books, BOOK_COUNT)) {
        return 1;
    }

    count = load_books("Book.bin", file_books, BOOK_COUNT);
    if (count < 0) {
        return 1;
    }

    printf("Book list\n\n");
    list_books(file_books, count);
    printf("\nTotal price: %d\n", total_price(file_books, count));

    return 0;
}
