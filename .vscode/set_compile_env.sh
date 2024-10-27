#!/bin/bash

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    if grep -q Microsoft /proc/version; then
        echo "Detected WSL"
        export C_COMPILER="/usr/bin/gcc"
        export CXX_COMPILER="/usr/bin/g++"
        export executableExtension=""
        export cmakeGenerator="Unix Makefiles"
    else
        echo "Detected Linux"
        export C_COMPILER="/usr/bin/gcc"
        export CXX_COMPILER="/usr/bin/g++"
        export executableExtension=""
        export cmakeGenerator="Unix Makefiles"
    fi
elif [[ "$OSTYPE" == "darwin"* ]]; then
    echo "Detected macOS"
    export C_COMPILER="/usr/bin/clang"
    export CXX_COMPILER="/usr/bin/clang++"
    export executableExtension=""
    export cmakeGenerator="Unix Makefiles"
else
    echo "Unsupported OS: $OSTYPE"
    exit 1
fi

echo "C_COMPILER: $C_COMPILER"
echo "CXX_COMPILER: $CXX_COMPILER"
echo "executableExtension: $executableExtension"
echo "cmakeGenerator: $cmakeGenerator"
