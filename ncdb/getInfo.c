#include <sys/sysinfo.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MBYTE 1048576

static struct sysinfo sys;

unsigned long *getMem(){
    static unsigned long ret[2];
    sysinfo (&sys);
    //TODO fix used ram
    ret[0] = ((sys.totalram - sys.freeram - sys.bufferram) * sys.mem_unit / MBYTE);
    ret[1] = (sys.totalram * sys.mem_unit / MBYTE);
    return ret;
}

unsigned long getProcesses(){
    sysinfo (&sys);
    return sys.procs;
}

char *getUserString(){
    char *ret = strcat(getlogin(), "@");
    char host[1024];
    gethostname(host, 1024);
    strcat(ret, host);
    return ret;
}

long getUptime(){
    sysinfo (&sys);
    return sys.uptime;
    //in seconds
}