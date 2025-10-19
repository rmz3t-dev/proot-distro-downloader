#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_SOURCE "https://raw.githubusercontent.com/rmz3t-dev/proot-distro-downloader/refs/heads/main/"
#define PD_DISTROPLUGIN "/data/data/com.termux/files/usr/etc/proot-distro"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("\n- Distro alias is empty!\n\n");
		return 0;
	}
	
	char DISTRO_ALIAS[1024];
	snprintf(DISTRO_ALIAS, sizeof(DISTRO_ALIAS), "%s", argv[1]);
	char DISTRO_PLUGIN[1024];
	snprintf(DISTRO_PLUGIN, sizeof(DISTRO_PLUGIN), "%s/%s-plugin.sh", FILE_SOURCE, DISTRO_ALIAS);
	
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-r") == 0) {
			printf("\n- Updating packages...\n\n");
			system("pkg update -y && pkg install curl -y && pkg install proot-distro -y");
		}
	}
	
	printf("\n- Downloading distro plugins (%s)...\n\n", DISTRO_PLUGIN);
	char download[1024];
	snprintf(download, sizeof(download), "curl -L %s -o %s/%s.sh", DISTRO_PLUGIN, PD_DISTROPLUGIN, DISTRO_ALIAS);
	system(download);

	printf("\n- Installing proot distro rootfs...\n\n");
	char installs[1024];
	snprintf(installs, sizeof(installs), "proot-distro install %s", DISTRO_ALIAS);
	system(installs);
	
	return 0;
}
