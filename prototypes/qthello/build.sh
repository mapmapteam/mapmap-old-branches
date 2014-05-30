#!/bin/bash
# Install qt4-default qt4-qmake
# On Mac, install it from http://qt-project.org/downloads

unamestr=$(uname)

if [[ $unamestr == "Darwin" ]]; then
    #export QMAKESPEC=macx-llvm
    #PATH=$PATH:~/Qt5.2.1/5.2.1/clang_64/bin
    qmake5=~/Qt/5.3/clang_64/bin/qmake
    # qmake5=~/Qt5.2.1/5.2.1/clang_64/bin/qmake
    # $qmake5 -spec macx-llvm

    # XXX
    #$qmake5 -config release -spec macx-llvm
    #$qmake5 -config debug -spec macx-llvm
    $qmake5 -config debug -spec macx-g++

    make
    macdeployqt hello.app
elif [[ $unamestr == "Linux" ]]; then
    qmake-qt4
    make
    lrelease mapmap_fr.ts
fi

