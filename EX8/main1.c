#include <stdio.h>
#include <string.h>

#define MAX_LOTTO_NUM 7

int main(void) {
    int win[3];

    printf("請輸入中獎號碼三個： ");
    scanf("%d %d %d", &win[0], &win[1], &win[2]);

    printf("輸入中獎號碼為： %02d %02d %02d\n",
           win[0], win[1], win[2]);
    printf("以下為中獎彩卷：\n");

    FILE *fp = fopen("lotto.txt", "r");
    if (!fp) {
        printf("找不到 lotto.txt\n");
        return 0;
    }

    char line[128];
    char date[64];

    fgets(line, sizeof(line), fp);

    fgets(line, sizeof(line), fp);
    sscanf(line, "==== %63[^=] ====", date);

    while (fgets(line, sizeof(line), fp)) {
        int id;
        int nums[MAX_LOTTO_NUM];
        int match = 0;

        if (strstr(line, "--")) continue;

        if (sscanf(line,
                   "[%d]: %d %d %d %d %d %d %d",
                   &id,
                   &nums[0], &nums[1], &nums[2],
                   &nums[3], &nums[4], &nums[5], &nums[6]) != 8)
            continue;

        for (int i = 0; i < MAX_LOTTO_NUM; i++) {
            for (int j = 0; j < 3; j++) {
                if (nums[i] == win[j])
                    match = 1;
            }
        }

        if (match) {
            printf("售出時間： %s: [%d]: ", date, id);
            for (int i = 0; i < MAX_LOTTO_NUM; i++) {
                printf("%02d ", nums[i]);
            }
            printf("\n");
        }
    }

    fclose(fp);
    return 0;
}

