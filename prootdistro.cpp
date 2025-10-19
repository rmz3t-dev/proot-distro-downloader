#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PD_DL "/data/data/com.termux/files/usr/var/lib/proot-distro/dlcache/debian-trixie-arm-pd-v4.29.0.tar.xz"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("\n- Download link is empty!\n\n");
		return 0;
	}
	
	printf("\n- Updating packages...\n\n");
	system("pkg update -y && pkg install curl -y && pkg install proot-distro -y");

	if (access(PD_DL, F_OK) == 0) {
		printf("\n- Removing old files...\n\n");
		remove(PD_DL);
	}
	
	printf("- Downloading debian from (%s)...\n\n", argv[1]);
	char download[1024];
	snprintf(download, sizeof(download), "curl -L %s -o %s", argv[1], PD_DL);
	system(download);

	if (access(PD_DL, F_OK) != 0) {
		printf("\n- Download failed!\n\n");
		return 0;
	}

	printf("\n- Download done!\n\n");
	return 0;
}
