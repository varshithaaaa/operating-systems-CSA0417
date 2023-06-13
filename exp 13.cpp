#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

struct file {
    char name[20];
    int size;
};

struct directory {
    char name[20];
    struct file files[MAX_FILES];
    int num_files;
};

int main() {
    struct directory cse;
    strcpy(cse.name, "CSE");
    cse.num_files = 0;

    struct file file1, file2, file3;
    strcpy(file1.name, "A");
    file1.size = 1024;
    strcpy(file2.name, "B");
    file2.size = 2048;
    strcpy(file3.name, "C");
    file3.size = 3072;

    cse.files[0] = file1;
    cse.files[1] = file2;
    cse.files[2] = file3;
    cse.num_files = 3;

    
    printf("Directory: %s\n", cse.name);
    printf("Number of files: %d\n", cse.num_files);
    printf("Files:\n");
    for (int i = 0; i < cse.num_files; i++) {
        printf("%s\t%d KB\n", cse.files[i].name, cse.files[i].size);
    }

    return 0;
}
