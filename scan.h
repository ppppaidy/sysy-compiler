// scan.h
// define constants and funcs for lex scan

#ifndef _SCAN_H_
#define _SCAN_H_

#define MAXTOKENLEN 256

extern char tokenString[MAXTOKENLEN+1];

int getToken();

#endif