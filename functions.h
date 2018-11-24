#ifndef SHELL_FUNCTIONS_H
#define SHELL_FUNCTIONS_H

struct Tokenized * tokenizer(char input[1024]);
typedef struct Tokenized {
    char *cmd_tree[1024];
    int size;
} Tokenized;



#endif //SHELL_FUNCTIONS_H
