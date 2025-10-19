# This is a default distribution plug-in.
# Do not modify this file as your changes will be overwritten on next update.
# If you want customize installation, please make a copy.
DISTRO_NAME="Debian (bookworm)"
DISTRO_COMMENT="Previous version (aarch64 & arm only)"

TARBALL_URL['aarch64']="https://github.com/termux/proot-distro/releases/download/v4.17.3/debian-trixie-aarch64-pd-v4.17.3.tar.xz"
TARBALL_SHA256['aarch64']="3834a11cbc6496935760bdc20cca7e2c25724d0cd8f5e4926da8fd5ca1857918"
TARBALL_URL['arm']="https://github.com/termux/proot-distro/releases/download/v4.17.3/debian-trixie-arm-pd-v4.17.3.tar.xz"
TARBALL_SHA256['arm']="99bcba87d8d1c66c0de06259ac0a270eb0a20f8b4af39beb0705d28846d78b90"

distro_setup() {
	# Configure en_US.UTF-8 locale.
	sed -i -E 's/#[[:space:]]?(en_US.UTF-8[[:space:]]+UTF-8)/\1/g' ./etc/locale.gen
	run_proot_cmd DEBIAN_FRONTEND=noninteractive dpkg-reconfigure locales
}
