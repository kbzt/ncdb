#include <stdio.h>
#include <unistd.h>
#include <json-c/json.h>

#include "getInfo.h"

int main(int argc, char const *argv[]){

    /*while (1){
      unsigned long *n = getMem();
      printf("Memory:     %lu / %lu\n", *n, *(n+1));
      //printf("Processes:  %lu\n", getProcesses());
      sleep(1);
    }*/

    printf(getWeatherInfo("2d7b0899966721fd30b1be1f2511e55a", "6167865"));
    
    return 0;
}