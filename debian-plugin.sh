# This is a default distribution plug-in.
# Do not modify this file as your changes will be overwritten on next update.
# If you want customize installation, please make a copy.
DISTRO_NAME="Debian (bookworm)"
DISTRO_COMMENT="Previous version (aarch64 & arm only)"

TARBALL_URL['aarch64']="https://github.com/termux/proot-distro/releases/download/v4.17.3/debian-bookworm-aarch64-pd-v4.17.3.tar.xz"
TARBALL_SHA256['aarch64']=""
TARBALL_URL['arm']="https://github.com/termux/proot-distro/releases/download/v4.17.3/debian-bookworm-arm-pd-v4.17.3.tar.xz"
TARBALL_SHA256['arm']="85861ab139d4042302796cf46a93a9efbcb4808c06f7a1ae5fb71812f4564424"

distro_setup() {
	# Configure en_US.UTF-8 locale.
	sed -i -E 's/#[[:space:]]?(en_US.UTF-8[[:space:]]+UTF-8)/\1/g' ./etc/locale.gen
	run_proot_cmd DEBIAN_FRONTEND=noninteractive dpkg-reconfigure locales
}
