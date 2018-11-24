#include "enviroment_variables.h"
#include "functions.h"

#define MAX_LEN  1024
#define DEBUG 0


Tokenized *tokenizer(char input[MAX_LEN]) {
    const char *token_break = " \t\n";
    Tokenized *token;
    token = malloc(sizeof(struct Tokenized));
    token->size = 0;
    char *tp;
    tp = input;
    for (int argc = 0; argc < MAX_LEN; argc++) {
        if ((token->cmd_tree[argc] = strtok(tp, token_break)) == NULL) {
            token->size = argc;
            break;
        }
        token->size = argc;
        tp = NULL;
    }
    if (DEBUG == 0) {
        for (int argc = 0; argc < MAX_LEN; argc++) {
            if (token->cmd_tree[argc] == NULL)
                break;
            printf("token[%s]\n", token->cmd_tree[argc]);

        }
    }

    return token;
}

