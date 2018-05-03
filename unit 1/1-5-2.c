#include "apue.h"
int main()
{
	int c;
	while((c=getc(stdin))!=EOF)
		if(putc(c,stdout)==EOF)
			err_sys("putc error");
	if(ferror(stdin))
		err_sys("stdin error");
	return 0;
}

