#ifndef GETINFO_H
#define GETINFO_H

#include <curl/curl.h>
#include <sys/sysinfo.h>

// System info
unsigned long *getMem();
unsigned long getProcesses();


char *getWeatherInfo();

#endif