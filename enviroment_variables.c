//
// Created by root on 11/16/18.
//

#include "enviroment_variables.h"

int initiate_user_space(envv *head){
    head = malloc(sizeof(1024));
    if(head == NULL){
        return -1;
    }
    head->name = "h3xshell";
    head->value = "welcome";
    head->next = NULL;

    return 0;
}

void push(envv *head, char *var_name, char *value){
    envv *current = head;
    while(current->next != NULL){
        current = current->next;
    }

    current-> next = malloc(sizeof(envv));
    current->name = var_name;
    current->value = value;
}