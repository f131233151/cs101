#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;

    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1f, 1.2f, 1.3f};

    int ra[3];
    char rb[sizeof(b)];
    float rc[3];

    /* 開啟二進位檔案 */
    fp = fopen("a.bin", "wb+");

    if (fp == NULL) {
        perror("Cannot open a.bin");
        return 1;
    }

    /* 寫入三個陣列 */
    if (fwrite(a, sizeof(a), 1, fp) != 1 ||
        fwrite(b, sizeof(b), 1, fp) != 1 ||
        fwrite(c, sizeof(c), 1, fp) != 1) {
        printf("Write file error\n");
        fclose(fp);
        return 1;
    }

    /* 回到檔案開頭 */
    if (fseek(fp, 0, SEEK_SET) != 0) {
        printf("File seek error\n");
        fclose(fp);
        return 1;
    }

    /* 讀取三個陣列 */
    if (fread(ra, sizeof(ra), 1, fp) != 1 ||
        fread(rb, sizeof(rb), 1, fp) != 1 ||
        fread(rc, sizeof(rc), 1, fp) != 1) {
        printf("Read file error\n");
        fclose(fp);
        return 1;
    }

    /* 輸出整數陣列 */
    for (int i = 0; i < 3; i++) {
        printf("%d ", ra[i]);
    }
    printf("\n");

    /* 輸出字元陣列 */
    for (int i = 0; i < 3; i++) {
        printf("%c ", rb[i]);
    }
    printf("\n");

    /* 輸出浮點數陣列 */
    for (int i = 0; i < 3; i++) {
        printf("%.6f ", rc[i]);
    }
    printf("\n");

    /* 關閉檔案 */
    fclose(fp);

    return 0;
}
