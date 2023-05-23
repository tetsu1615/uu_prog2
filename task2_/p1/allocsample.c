#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	char *p;

	p = malloc(1024 * 1024 * 500);
	if (p == NULL)
	{
		printf("Allocation failed.\n");
	}
	else
	{

		free(p);
	}

	// メモリリーク情報の表示
	_CrtDumpMemoryLeaks();

	return 0;
}