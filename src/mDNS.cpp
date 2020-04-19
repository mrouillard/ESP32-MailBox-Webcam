#include <ESPmDNS.h>

void mdnsInit(const char *name,const char *longname)
{
    //initialize mDNS service
    if(MDNS.begin(name)) {
        printf("mDNS responder started with hostname %s\n", name);
    } else {
        printf("mDNS Init failed\n");
        return;
    }
    //set default instance
    MDNS.setInstanceName(longname);
    //set default http service
    MDNS.addService("http", "tcp", 80);
}