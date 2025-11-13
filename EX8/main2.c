#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void lotto_print(int n, int counter) {
    char filename[64];
    sprintf(filename, "lotto[%05d].txt", counter);

    FILE *fp = fopen(filename, "w");
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "========+ No.%05d +========\n", counter);
    fprintf(fp, "= %s", asctime(tm));

    int lotto[6];
    for (int i = 1; i <= 5; i++) {
        if (i <= n) {
            fprintf(fp, "[%d]: ", i);
            for (int j = 0; j < 6; j++) {
                lotto[j] = rand() % 69 + 1;
                fprintf(fp, "%02d ", lotto[j]);
            }
            fprintf(fp, "\n");
        } else {
            fprintf(fp, "[%d]: -- -- -- -- -- --\n", i);
        }
    }

    fprintf(fp, "======= csie@CGU =======\n");
    fclose(fp);
}

int main(void) {
    srand(time(NULL));

    int counter = 1;
    FILE *fp = fopen("counter.bin", "rb");

    if (fp) {
        fread(&counter, sizeof(int), 1, fp);
        fclose(fp);
    }

    lotto_print(5, counter);

    counter++;
    fp = fopen("counter.bin", "wb");
    fwrite(&counter, sizeof(int), 1, fp);
    fclose(fp);

    return 0;
}
