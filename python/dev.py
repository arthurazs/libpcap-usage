import libpcap as pcap
import ctypes as ct
import sys

errbuf  = ct.create_string_buffer(pcap.PCAP_ERRBUF_SIZE)
devs = ct.POINTER(pcap.pcap_if_t)()
head = devs
rc = pcap.findalldevs(ct.byref(devs), errbuf)

if rc != 0:
    print("pcap_findalldevs:", errbuf.value)
    sys.exit(rc)

print("Listing devices...")
while devs:
    dev = devs.contents
    print("- ", dev.name.decode(), end="")
    if dev.description:
      print(":", dev.description.decode(), end="")
    print()
    devs = dev.next
print("Done!")
pcap.freealldevs(head)
