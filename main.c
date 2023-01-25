#include <unistd.h>
#include <stdio.h>
#include "main.h"
int main(void)
{
	int count_std;
	int count_hmd;
	write(1, "STANDARD:\n", 10);
	count_std = printf("TEST\n");
	printf("%d\n", count_std);
	write(1,"HOME_MADE:\n", 11);
	count_hmd =_printf("TEST\n");
	printf("%d\n", count_hmd);
	return (0);
}
