#include <curl/curl.h>
#include <sys/sysinfo.h>
#include <string.h>
#include <stdlib.h>

#define APIURL "https://api.openweathermap.org/data/2.5/weather"
#define MBYTE 1048576


static struct sysinfo sys;

// Returns MemUsed, MemTotal
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

char *append(const char *str1, const char *str2){
    char *new_str;
    if((new_str = malloc(strlen(str1)+strlen(str2)+1)) != NULL){
        new_str[0] = '\0';   // ensures the memory is an empty string
        strcat(new_str,str1);
        strcat(new_str,str2);
    } else {
        printf("malloc failed!\n");
    }
    return new_str;
}


char *getWeatherInfo(char *APIKEY, char *CITYCODE){
    CURL *curl;
    CURLcode res;
    static char *url = APIURL;

    url = append(url, "?id=");
    url = append(url, CITYCODE);
    url = append(url, "&appid=");
    url = append(url, APIKEY);
    url = append(url, "&units=metric");
    
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    

        res = curl_easy_perform(curl);

        if(res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    

        curl_easy_cleanup(curl);
    }

    return url;
}