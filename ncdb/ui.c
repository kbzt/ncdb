#include <stdio.h>
#include "getInfo.h"

void printVerbose(){
	printf("Host:\t\t%s\n", getUserString());
	printf("Processes:\t%ld\n", getProcesses());

	unsigned long *n = getMem();
	printf("Mem:\t\t%ld / %ld\n", *n, *(n+1));

	__uint32_t uptime = (__uint32_t) getUptime();
	printf("Uptime:\t\t%d\n", uptime);
}