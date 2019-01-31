#include <func.h>

int main()
{
    char *a=(char*)calloc(128,sizeof(char));
    printf("sizeof(a):%ld\nstrlen(a):%ld\n",sizeof(a),strlen(a));
    char b[128]={0};
    printf("sizeof(b):%ld\nstrlen(b):%ld\n",sizeof(b),strlen(b));
    return 0;
}

