#include <stdio.h>
#ifndef STRING1_H
#define STRING1_H


size_t OptimaStrlen(const char* s);
int find_digit(int number, int digit);
char *OptimaStrChr(const char *s, int c);
char *strcat(char *dest, const char *src);
void boom (int start_range, int end_range);
int OptimaStrcmp(const char* s1,const char*s2);
int OptimaStrCaseCmp (char* str1, const char* str2);
char *OptimaStrStr(const char *haystack, const char *needle);
size_t OptimaStrspn(const char * string, const char * accept);

#endif 

