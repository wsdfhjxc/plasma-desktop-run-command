#!/bin/bash

printUsage() {
    echo "Usage: helper.sh build|install|uninstall"
    echo "   or: helper.sh installBuildDependencies name-of-the-distro"
}

build() {
    mkdir -p build
    cd build || exit 1

    cmake .. && \
    make clean && \
    make && cd .. || {
        cd ..
        exit 1
    }
}

install() {
    build && cd build || exit 1
    sudo make install && cd .. || {
        cd ..
        exit 1
    }
}

case $1 in
    build)
        build
        ;;

    install)
        install
        ;;

    uninstall)
        cd build || install

        [[ -f install_manifest.txt ]] || {
            install
        }

        sudo make uninstall && cd .. || {
            cd ..
            exit 1
        }
        ;;

    installBuildDependencies)
        case $2 in
            ubuntu)
                sudo apt install cmake extra-cmake-modules qtbase5-dev libkf5plasma-dev
                ;;

            *)
                printUsage
                exit 1
                ;;
        esac
        ;;

    *)
        printUsage
        exit 1
        ;;
esac
