#!/bin/bash

printUsage() {
    echo "Usage: helper.sh build|install|uninstall"
    echo "   or: helper.sh installBuildDependencies ubuntu|fedora|opensuse|arch"
}

build() {
    mkdir -p build && \
    cd build && \
    cmake .. && \
    make && cd .. || {
        cd ..
        return 1
    }
}

install() {
    build && \
    cd build && \
    sudo make install && cd .. || {
        cd ..
        return 1
    }
}

uninstall() {
    install && \
    cd build || return 1

    [[ -f install_manifest.txt ]] || {
        install
    }

    sudo make uninstall && cd .. || {
        cd ..
        return 1
    }
}

installBuildDependencies() {
    case $1 in
        ubuntu)
            sudo apt install g++ cmake extra-cmake-modules qtbase5-dev libkf5plasma-dev
            ;;

        fedora)
            sudo dnf install gcc-c++ cmake extra-cmake-modules qt5-qtbase-devel kf5-plasma-devel
            ;;

        opensuse)
            sudo zypper in gcc-c++ cmake extra-cmake-modules libqt5-qtbase-devel plasma-framework-devel
            ;;

        arch)
            sudo pacman -S gcc cmake extra-cmake-modules
            ;;

        *)
            printUsage
            exit 1
            ;;
    esac
}

case $1 in
    build)
        build
        ;;

    install)
        install
        ;;

    uninstall)
        uninstall
        ;;

    installBuildDependencies)
        installBuildDependencies "$2"
        ;;

    *)
        printUsage
        exit 1
        ;;
esac
