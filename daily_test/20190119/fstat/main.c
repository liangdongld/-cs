#include "func.h"
int main()
{
	args_check(argv,2);
	int fd=open(argv[1],O_RDONLY);
}
