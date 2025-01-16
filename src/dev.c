#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#include <pcap.h>
#pragma clang diagnostic pop

#include <stdlib.h>
#include <netinet/in.h>


int main(void) {
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_if_t * alldevs;
  // TODO: get lo dev and try pcap_sendpacket
  /*pcap_if_t dev;*/

  int rc = pcap_findalldevs(&alldevs, errbuf);
  if (rc == PCAP_ERROR) {
    fprintf(stderr, "pcap_findalldevs: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  printf("Listing devices...\n");
  while (alldevs != NULL) {
    printf("- %s", alldevs->name);
    if (alldevs->description != NULL) {
      printf(": %s", alldevs->description);
    }
    printf("\n");
    alldevs = alldevs->next;
  }
  printf("Done!\n");

  pcap_freealldevs(alldevs);
  alldevs = NULL;
  return EXIT_SUCCESS;
}
