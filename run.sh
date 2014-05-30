#!/bin/bash
#export GST_PLUGIN_PATH=/Library/Frameworks/GStreamer.framework/Libraries
#export GST_DEBUG=2
export LANG=C

unamestr=$(uname)

if [[ $unamestr == "Darwin" ]]; then
    export DYLD_PRINT_LIBRARIES=1
    #lldb ./MapMap.app/Contents/MacOS/MapMap
    ./MapMap.app/Contents/MacOS/MapMap
elif [[ $unamestr == "Linux" ]]; then
    ./mapmap
fi

