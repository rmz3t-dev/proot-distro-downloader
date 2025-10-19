**NOTE: you need to compile it first before using downloader**

update and install required packages
```
pkg update -y && pkg install curl clang -y
```

download prootdistro.cpp
```
curl -LO https://raw.githubusercontent.com/rmz3t-dev/proot-distro-downloader/refs/heads/main/prootdistro.cpp
```

start compiling cpp files
```
clang -o prootdistro prootdistro.cpp
```

download proot distro rootfs
```
./prootdistro <alias>
```

login to proot distro
```
pd login <alias>
```
