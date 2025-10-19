NOTE: you need to compile it first before using downloader
```
pkg update -y && pkg install clang -y
```

start compiling
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
