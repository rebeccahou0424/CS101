#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    FILE* fp;
    
    int   a_write[3]   = {0, 1, 2};
    char  b_write[3]   = {'A', 'B', 'C'};  
    float c_write[3]   = {1.1f, 1.2f, 1.3f};
    
    int   a_read[3] = {0};
    char  b_read[3] = {0};
    float c_read[3] = {0};
    
    fp = fopen("a.bin", "wb+");
    if (!fp) {
        perror("fopen");
        return 1;
    }
    
    fwrite(a_write, sizeof(int),   3, fp);  
    fwrite(b_write, sizeof(char),  3, fp);  
    fwrite(c_write, sizeof(float), 3, fp);  

    fseek(fp, 0, SEEK_SET);
    
    fread(a_read, sizeof(int),   3, fp);
    fread(b_read, sizeof(char),  3, fp);
    fread(c_read, sizeof(float), 3, fp);

    fclose(fp);

    for (int i = 0; i < 3; i++) printf("%d ", a_read[i]);
    printf("\n");

    for (int i = 0; i < 3; i++) printf("%c ", b_read[i]);
    printf("\n");

    for (int i = 0; i < 3; i++) printf("%f ", c_read[i]); 
    printf("\n");

    return 0;
}
