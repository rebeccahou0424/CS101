#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define COUNTER_FILE "counter.bin"
#define MAX_LOTTO_NUM 7
#define MAX_LOTTO_NUMSET 5

void init_file() {
    int write_array[1] = {0};
    FILE* fp = fopen(COUNTER_FILE, "r");
    if (fp == NULL) {
        FILE* tmpfp = fopen(COUNTER_FILE, "wb");
        fwrite(write_array, sizeof(int), 1, tmpfp);
        fclose(tmpfp);
    } else {
        fclose(fp);
    }
}

int get_counter() {
    int read_array[1];
    FILE* tmpfp = fopen(COUNTER_FILE, "rb");
    fread(read_array, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
    return read_array[0];
}

int num_in_numset(int num, int numset[], int Len) {
    int ret = 0;
    for (int i = 0; i < Len; i++) {
        if (num == numset[i]) {
            ret = 1;
            break;
        }
    }
    return ret;
}

void print_lotto_row(FILE* tmpfp, int n) {
    int numset[MAX_LOTTO_NUM];
    fprintf(tmpfp, "[%d]: ", n);

    /* 產生前 6 個不重複的 1~69 號碼 */
    for (int i = 0; i < MAX_LOTTO_NUM - 1;) {
        int num = (rand() % 69) + 1;
        if (num_in_numset(num, numset, i))
            continue;
        numset[i] = num;
        i++;
    }

    /* 第 7 個號碼：1~10 */
    for (int i = 0; i < 1;) {
        int num = (rand() % 10) + 1;
        if (num_in_numset(num, numset, MAX_LOTTO_NUM - 1))
            continue;
        numset[MAX_LOTTO_NUM - 1] = num;
        i++;
    }

    /* 排序前 6 個 */
    for (int i = 0; i < MAX_LOTTO_NUM - 1; i++) {
        for (int j = 0; j < i; j++) {
            if (numset[j] > numset[i]) {
                int temp = numset[j];
                numset[j] = numset[i];
                numset[i] = temp;
            }
        }
    }

    /* 印出 */
    for (int i = 0; i < MAX_LOTTO_NUM; i++) {
        fprintf(tmpfp, "%02d ", numset[i]);
    }
    fprintf(tmpfp, "\n");
}

void print_lottofile(int num_set, int counter, char lotto_file[]) {
    time_t curtime;
    time(&curtime);
    srand(time(0));

    FILE* tmpfp = fopen(lotto_file, "w+");

    fprintf(tmpfp, "========= lotto649 =========\n");
    fprintf(tmpfp, "========+ No.%05d +========\n", counter);
    fprintf(tmpfp, "= %.24s =\n", ctime(&curtime));

    for (int i = 0; i < MAX_LOTTO_NUMSET; i++) {
        if (i < num_set) {
            print_lotto_row(tmpfp, i + 1);
        } else {
            fprintf(tmpfp, "[%d]: -- -- -- -- -- -- --\n", i + 1);
        }
    }

    fprintf(tmpfp, "======= csie@CGU =======\n");
    fclose(tmpfp);
}

void set_counter(int counter) {
    int write_array[1];
    write_array[0] = counter;
    FILE* tmpfp = fopen(COUNTER_FILE, "wb");
    fwrite(write_array, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
}

void do_lotto_main(int counter) {
    char lotto_file[32];
    int num_set = 0;

    snprintf(lotto_file, 32, "lotto[%05d].txt", counter);

    printf("歡迎光臨長庚樂透購買機台\n");
    printf("請問您要購買幾組樂透彩：");
    scanf("%d", &num_set);

    print_lottofile(num_set, counter, lotto_file);

    printf("已為您購買的 %d 組樂透組合輸出至 %s\n", num_set, lotto_file);
}

int main() {
    int counter;
    init_file();                     // (1) 初始化帳簿（不存在就建立 counter = 0）
    counter = get_counter();         // (2) 讀取帳簿
    do_lotto_main(++counter);        // (3) 輸出彩卷（先 ++counter）
    set_counter(counter);            // (4) 寫回帳簿
    return 0;
}
