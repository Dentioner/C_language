/*
 *This code make no sense(Compiled successfully), 
 *but for exercise1_23 in <<K&R>> to test remove all comments in C code.
 */

#          include         <stdio.h>
#  include  <secure/_stdio.h>
#include      "/Users/apple/blog/zhanghaiba/KandR/test.h"
#define CHAR '\'' /*/test/*/
#  define LESS(i) ( ((i) << 31) / 2 )
#        define STRING "\"string\"" //to ensure legal

int main(void)
{
    int w; // \a
    int x;/*hehe*/
    double y; // \ 
    double z; // \b \\\\
    int none;

    ///*testing*/
    int idx;
    if (idx > 3 && idx < 6) idx = idx/100; //go and \
    con_tinue\
    hehe

    /* // */    
    char a = '/';    // /
    char b = '*';    // *
    char c = '\'';    // '
    char d = '\n';    // enter
    char e = '\"';    // "    
    char f = '\\';    // \
    char g = '<';    // <
    char h = '>';    // >
    char i = '"';    // "

    /* special***string */
    char special0[] = "\"hello, world!\"";
    char special1[] = "//test";
    char special2[] = "he\"/*hehe*/";
    char *special = " \' hi \0\b\t \\\\ \a\e\f\n\r\v wolegequ \\ ";
    return        0;
}s

/*******************************************************************
// Programming problem 2 p672 
// Eight Queens Problem. 
//******************************************************************/
#include <iostream> // for cout
#include <fstream> // for file operations
#include <iomanip> // for setw
#include <ctime> // for run time counting