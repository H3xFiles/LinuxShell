#include "enviroment_variables.h"
#include "functions.h"

#define MAX_LEN  1024
#define DEBUG 0
#define READ 0
#define WRITE 1

void execute(char *cmd, char *flags[]) {
    execvp(cmd, flags);
}

void prompt() {
    static int initialize = 1;
    if (initialize) {
        system("clear");
        initialize = 0;
    }
    char *user = getenv("USER");
    printf("\n%s#> ", user);

}

int main() {

    while (1) {
        char input[MAX_LEN];
        prompt();
        if (fgets(input, sizeof(input), stdin) != NULL) {
            Tokenized *tok;
            tok = tokenizer(input);

            pid_t pid_fd;
            pid_fd = fork();

            if (pid_fd == -1) {
                perror("Failed to fork");
            }
            if (pid_fd == 0) {
                execute(tok->cmd_tree[0], tok->cmd_tree);
            } else {
                wait(NULL);
            }

            fflush(stdin);
            fflush(stdout);
            free(tok);



//            pid_t pid_cmd1, pid_cmd2;
//            int pipe_fd[2];
//
//            if (pipe(pipe_fd) == -1) {
//                perror("Error: pipe");
//                return -1;
//            }
//
//            pid_cmd2 = fork();
//            if (pid_cmd2 == -1) {
//                perror("Error: fork");
//                return -1;
//            } else if (pid_cmd2 == 0) {
//                if (dup2(pipe_fd[WRITE], STDOUT_FILENO) == -1) {
//                    perror("Fail to duplicate");
//                    return -1;
//                }
//                close(pipe_fd[READ]);
//                execvp(cmd1, buffer_one);
//
//                return -1;
//            }
//
//            pid_cmd1 = fork();
//            if (pid_cmd1 == -1) {
//                perror("Error: fork");
//                return -1;
//            } else if (pid_cmd1 == 0) {
//                if (dup2(pipe_fd[READ], STDIN_FILENO) == -1) {
//                    perror("Fail to duplicate");
//                    return -1;
//                }
//                close(pipe_fd[WRITE]);
//                execvp(cmd2, buffer_two);
//                return -1;
//
//            } else {
//                close(pipe_fd[WRITE]);
//                close(pipe_fd[WRITE]);
//                wait(NULL);
//            }


        }

    }
    return 0;
}

