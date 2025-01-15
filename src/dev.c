#include <pcap.h>
#include <stdlib.h>

#pragma clang diagnostic ignored "-Wdeprecated-declarations"

int main(void) {
  char *dev, errbuf[PCAP_ERRBUF_SIZE];

  dev = pcap_lookupdev(errbuf);
  if (dev == NULL) {
    fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
    return EXIT_FAILURE;
  }
  printf("Default device: %s\n", dev);
  return EXIT_SUCCESS;
}
