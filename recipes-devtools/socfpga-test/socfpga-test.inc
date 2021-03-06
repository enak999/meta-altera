DESCRIPTION = "Linux Unit tests"
AUTHOR = "yvanderv@altera.com"
SECTION = "Tests"
LICENSE = "GPLv2"

S="${WORKDIR}/linux-test"
BP="${BPN}"
DEPENDS = "virtual/kernel vlan"

# git:/git.linaro.org/git-ro/arm/ds5/gator.git;protocol=http
# This variable points to rocketboards by default. It can be overridden
# by setting it in the shell env and by adding it to BB_WHITE_ENV
LINUX_TEST_REPO?="http://git.rocketboards.org/linux-test"
S = "${WORKDIR}/git"
SRC_URI = "${LINUX_TEST_REPO}"
SRCREV_pn-${PN} = "${AUTOREV}"

LIC_FILES_CHKSUM="file://${S}/LICENSE;md5=a2c916c096f4cf1974df39bedd5cb1bf"

do_compile() {

	cd ${S}
	make CROSS_COMPILE=${TARGET_PREFIX} clean
        make CROSS_COMPILE=${TARGET_PREFIX}
}

do_install() {
	
        echo "-------------${D}/unit-tests"
	install -d ${D}/unit-tests
	make INSTALLPATH=${D}/unit-tests/ install
}

FILES_${PN} = "/unit-tests/*"
