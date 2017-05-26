#include <stdio.h>
int main(int argc, char *argv[])
{
long long h = 0xDEADDEADDEADDEADll;
printf("%llx\n",h);
//printf("%lld\n",(long long)1971);
#if 0
long long ll = 1000000001;
ll *= 3;
printf("%lld\n",ll);

ll = 0x100000001;
ll *= 0x300000;
printf("%llx\n", ll);
#endif
return 0;
}

