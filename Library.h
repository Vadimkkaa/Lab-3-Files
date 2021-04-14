#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void text_add(FILE* , fpos_t*);
int bin_add(FILE* );
void text_add_1(FILE* , fpos_t* , int , char* );
void text_matches(FILE* );
void bin_matches(FILE* );
void text_out(FILE* , char );
void bin_out(FILE* );
void text_shift(FILE* , fpos_t , fpos_t , int , char*);
int bin_max(FILE* );
void bin_replace(FILE* , int , int );