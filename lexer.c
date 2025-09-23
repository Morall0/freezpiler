#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fileLex(char *source_file_path) { // Read a file and iterate the buffer character by character
    FILE *f;
    char buff[4096];
    
    f = fopen(source_file_path, "r");

    if (!f) {
        printf("ERROR: The file `%s` doesn't exists.\n", source_file_path); return 1;
    }
     
    while (fread(buff, sizeof(char), 4096, f)) {
        printf("%s", buff);
        //TODO: check which type of token is.
    }

    fclose(f);
    return 0;
}

int strLex(char *source_str) { // Iterate a string character by character
    int len = strlen(source_str);
    char *HLL_code = (char *)malloc(len * sizeof(char));
    strcpy(HLL_code, source_str);

    for (int i=0; i<len; i++) {
        printf("%c", HLL_code[i]);
        //TODO: check which type of token is.
    }

    return 0;
}

// Arguments: [source_file_path] | [-s source_str]
// Examples of execution:
// ./test main.c
// ./test -s 'printf("Hello World!");'
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("ERROR: Please specify a file or a string to analize.");
        return 1;
    }

    if (argc == 2) { // A source file path is received
        fileLex(argv[1]); // Lexer applied to a file
    } else if (argc == 3 && strcmp(argv[1], "-s") == 0) { // A string is received
        strLex(argv[2]); // Lexer applied to a string
    }

    return 0;
}
