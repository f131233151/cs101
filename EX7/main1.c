/*
 * EX#7 - 第 1 題：長庚樂透購買程式
 * 規則：每組 7 個不重複數字，範圍 01～69。
 * 輸入購買組數 n（1～5），結果輸出至 lotto.txt。
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GROUPS 5
#define NUMBERS_PER_GROUP 7
#define MAX_NUMBER 69

/* 產生一組 7 個不重複的樂透號碼 */
void generate_lotto(int numbers[NUMBERS_PER_GROUP])
{
    int i, j, candidate;
    int duplicated;

    for (i = 0; i < NUMBERS_PER_GROUP; i++) {
        do {
            candidate = rand() % MAX_NUMBER + 1;
            duplicated = 0;

            for (j = 0; j < i; j++) {
                if (numbers[j] == candidate) {
                    duplicated = 1;
                    break;
                }
            }
        } while (duplicated);

        numbers[i] = candidate;
    }
}

/* 將樂透結果寫入檔案 */
void save_lotto(int n)
{
    FILE *fp;
    int numbers[NUMBERS_PER_GROUP];
    int i, j;
    time_t now;
    struct tm *local_time;

    fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        perror("無法建立 lotto.txt");
        return;
    }

    now = time(NULL);
    local_time = localtime(&now);

    fprintf(fp, "========== lotto649 ==========\n");
    if (local_time != NULL) {
        fprintf(fp, "  %s", asctime(local_time));
    }

    /* 固定顯示 5 組；未購買的組數以 -- 表示 */
    for (i = 0; i < MAX_GROUPS; i++) {
        fprintf(fp, "[%d]:", i + 1);

        if (i < n) {
            generate_lotto(numbers);

            for (j = 0; j < NUMBERS_PER_GROUP; j++) {
                fprintf(fp, " %02d", numbers[j]);
            }
        } else {
            for (j = 0; j < NUMBERS_PER_GROUP; j++) {
                fprintf(fp, " --");
            }
        }

        fprintf(fp, "\n");
    }

    fprintf(fp, "========== csie@CGU ==========\n");
    fclose(fp);
}

int main(void)
{
    int n;

    srand((unsigned int)time(NULL));

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透：");

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_GROUPS) {
        printf("輸入錯誤，請輸入 1～5 之間的整數。\n");
        return 1;
    }

    save_lotto(n);
    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
