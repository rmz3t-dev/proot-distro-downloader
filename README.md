**NOTE: you need to compile it first before using downloader**

update and install required packages
```
pkg update -y && pkg install curl clang -y
```

download prootdistro.cpp
```
curl -LO https://github.com/rmz3t-dev/proot-distro-downloader/blob/main/prootdistro.cpp
```

start compiling cpp files
```
clang -o prootdistro prootdistro.cpp
```

download proot distro rootfs
```
./prootdistro <download_link>
```

install downloaded rootfs
```
pd install debian
```
