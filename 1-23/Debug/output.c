

#          include         <stdio.h>
#  include  <secure/_stdio.h>
#include      "/Users/apple/blog/zhanghaiba/KandR/test.h"
#define CHAR '\'' 
#  define LESS(i) ( ((i) << 31) / 2 )
#        define STRING "\"string\"" 

int main(void)
{
    int w; 
    int x;
    double y; 
    double z; 

    
    int idx;
    if (idx > 3 && idx < 6) idx = idx/100; 

        
    char a = '/';    
    char b = '*';    
    char c = '\'';    
    char d = '\n';    
    char e = '\"';    
    char f = '\\';    
    char h = '>';    
    char i = '"';    

    
    char special0[] = "\"hello, world!\"";
    char special1[] = "//test";
    char special2[] = "he\"/*hehe*/";
    char *special = " \' hi \0\b\t \\\\ \a\e\f\n\r\v wolegequ \\ ";
    return        0;
}s


#include <iostream> 
#include <fstream> 
#include <iomanip> 
#include <ctime> 