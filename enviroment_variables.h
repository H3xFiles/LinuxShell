//
// Created by root on 11/16/18.
//

#ifndef SHELL_ENVIROMENT_VARIABLES_H_H
#define SHELL_ENVIROMENT_VARIABLES_H_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct Enviroment_variables{
    char *name;
    char *value;
    struct Enviroment_variables *next;
}envv;

int initiate_user_space(envv *head);
void push(envv *head, char *var_name, char *value);

#endif //SHELL_ENVIROMENT_VARIABLES_H_H
