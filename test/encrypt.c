#include "encrypt.h"
#include "stdio.h"

void encode(char* name,char* newName,int code) {
	FILE *fw = fopen(newName,"w+");	
	FILE *fr = fopen(name,"r+");	
	char ch = EOF;
	while((ch = fgetc(fr)) && (!feof(fr))){
		fputc(ch^code,fw);
	}
	fclose(fw);
	fclose(fr);
}

void decode(char *name,char* newName ,int code) {
	FILE *fw = fopen(newName,"w+");	
	FILE *fr = fopen(name,"r+");	
	char ch = EOF;
	while((ch = fgetc(fr)) && (!feof(fr))){
		fputc(ch^code,fw);
	}
	fclose(fw);
	fclose(fr);
}
