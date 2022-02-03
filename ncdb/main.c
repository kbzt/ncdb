#include <string.h>
#include <stdio.h>

#include "ui.h"

int main(int argc, char const *argv[]){

<<<<<<< HEAD
    /*while (1){
      unsigned long *n = getMem();
      printf("Memory:     %lu / %lu\n", *n, *(n+1));
      //printf("Processes:  %lu\n", getProcesses());
      sleep(1);
    }*/
=======
    if (strcmp(argv[1], "-v") == 0)
    {
      printVerbose();
    } else
    {
      printf("Not Verbose!");
    }
>>>>>>> c6aa400 (remove weather, add fetch, update license to gpl)
    

    return 0;
}
