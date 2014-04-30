#!/bin/bash
# Install qt4-default qt4-qmake
# On Mac, install it from http://qt-project.org/downloads

unamestr=$(uname)

if [[ $unamestr == "Darwin" ]]; then
    MAKE_CFLAGS_X86_64+="-Xarch_x86_64 -mmacosx-version-min=10.7"
    QMAKE_CFLAGS_PPC_64+="-Xarch_ppc64 -mmacosx-version-min=10.7"
    export MAKE_CFLAGS_X86_64
    export QMAKE_CFLAGS_PPC_64
    export QMAKESPEC=macx-g++
    #export QMAKESPEC=macx-xcode
    PATH=$PATH:~/Qt5.2.1/5.2.1/clang_64/bin
    qmake5=~/Qt5.2.1/5.2.1/clang_64/bin/qmake
    $qmake5 -spec macx-llvm 
elif [[ $unamestr == "Linux" ]]; then
    /usr/lib/x86_64-linux-gnu/qt5/bin/qmake
    #qmake-qt5
fi

make
lrelease mapmap_fr.ts

