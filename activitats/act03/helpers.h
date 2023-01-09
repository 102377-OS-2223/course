#ifndef _HELPERS_H_
#define _HELPERS_H_

int split_line(char *line, char* separator, char ***tokens);
int read_line(char** line);
int ayuda(void);
int errors(char *c);
int enters(char *c);
int compareCommands(char *c);

#endif