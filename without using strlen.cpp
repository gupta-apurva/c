#include<stdio.h>
#include<conio.h>
main()
{
	int len=0;
	char name[30],*ptr;
	gets(name);
	for(ptr=name;*ptr!='\0';ptr++)
	len++;
	printf("%d",len);
	getch();
}
