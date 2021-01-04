#!/bin/bash

printUsage() {
    echo "Usage: helper.sh build|install|uninstall|upgrade"
    echo "   or: helper.sh package deb|rpm distro-name qt5-lib-dir-path"
}

build() {
    mkdir -p build && \
    cd build && \
    cmake .. && make || exit 1
}

install() {
    build && sudo make install || exit 1
}

uninstall() {
    install || exit 1
    [[ -f install_manifest.txt ]] || install || exit 1
    sudo make uninstall || exit 1
}

upgrade() {
    install || exit 1
}

package() {
    local pkg=$1
    local distro=$2
    local qt5Dir=$3

    [[ $# -lt 3 ]] && {
        printUsage
        exit 1
    }

    [[ -d build ]] || (build)

    # Requirements: fpm
    # https://fpm.readthedocs.io

    local readonly name=plasma-desktop-run-command
    local readonly version=$(grep -Po "Version=\K(.*)" src/metadata.desktop)
    local readonly package=NAME-VERSION-$distro-ARCH.TYPE
    local readonly maintainer=https://github.com/wsdfhjxc
    local readonly url=https://github.com/wsdfhjxc/plasma-desktop-run-command
    local readonly description="See the project's homepage for more information"

    fpm --input-type dir --output-type $pkg \
    --name $name --version $version --package $package \
    --maintainer $maintainer --url $url --description "$description" \
    build/plasma_containmentactions_runcommand.so=$qt5Dir/plugins/plasma/containmentactions/
}

main() {
    local command=$1

    shift

    case $command in
        build|install|uninstall|upgrade|package)
            $command $*
            ;;

        *)
            printUsage
            exit 1
            ;;
    esac
}

main $*
