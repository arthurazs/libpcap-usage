# libpcap usage

```bash
# dependencies
apt install autoconf flex bison

# download libpcap
git clone --depth=1 --branch libpcap-1.10.5 git@github.com:the-tcpdump-group/libpcap.git
cd libpcap

# build
./autogen.sh
./configure
make

# link files
ln -s libpcap.so.1.10.5 libpcap.so.1
ln -s libpcap.so.1 libpcap.so
```
