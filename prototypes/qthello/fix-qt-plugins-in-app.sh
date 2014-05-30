#!/bin/bash
appdir=./hello.app
qtdir=~/Qt/5.3/clang_64

set -o verbose

# install libqcocoa library
mkdir -p $appdir/Contents/PlugIns/platforms
cp $qtdir/plugins/platforms/libqcocoa.dylib $appdir/Contents/PlugIns/platforms
# fix its identity and references to others
install_name_tool -id @executable_path/../PlugIns/platforms/libqcocoa.dylib $appdir/Contents/PlugIns/platforms/libqcocoa.dylib
#install_name_tool -change $qtdir/lib/QtPrintSupport.framework/Versions/5/QtPrintSupport @executable_path/../Frameworks/QtPrintSupport.framework/Versions/5/QtPrintSupport $appdir/Contents/PlugIns/platforms/libqcocoa.dylib
install_name_tool -change $qtdir/lib/QtWidgets.framework/Versions/5/QtWidgets @executable_path/../Frameworks/QtWidgets.framework/Versions/5/QtWidgets $appdir/Contents/PlugIns/platforms/libqcocoa.dylib
install_name_tool -change $qtdir/lib/QtGui.framework/Versions/5/QtGui @executable_path/../Frameworks/QtGui.framework/Versions/5/QtGui $appdir/Contents/PlugIns/platforms/libqcocoa.dylib
install_name_tool -change $qtdir/lib/QtCore.framework/Versions/5/QtCore @executable_path/../Frameworks/QtCore.framework/Versions/5/QtCore $appdir/Contents/PlugIns/platforms/libqcocoa.dylib
# install QtPrintSupport framework
#cp -r $qtdir/lib/QtPrintSupport.framework $appdir/Contents/Frameworks
# fix its identity and references to others
#install_name_tool -id @executable_path/../Frameworks/QtPrintSupport.framework/Versions/5/QtPrintSupport $appdir/Contents/Frameworks/QtPrintSupport.framework/Versions/5/QtPrintSupport
#install_name_tool -change $qtdir/lib/QtWidgets.framework/Versions/5/QtWidgets @executable_path/../Frameworks/QtWidgets.framework/Versions/5/QtWidgets $appdir/Contents/Frameworks/QtPrintSupport.framework/Versions/5/QtPrintSupport
#install_name_tool -change $qtdir/lib/QtGui.framework/Versions/5/QtGui @executable_path/../Frameworks/QtGui.framework/Versions/5/QtGui $appdir/Contents/Frameworks/QtPrintSupport.framework/Versions/5/QtPrintSupport
#install_name_tool -change $qtdir/lib/QtCore.framework/Versions/5/QtCore @executable_path/../Frameworks/QtCore.framework/Versions/5/QtCore $appdir/Contents/Frameworks/QtPrintSupport.framework/Versions/5/QtPrintSupport

