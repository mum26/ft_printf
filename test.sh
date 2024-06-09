#!/bin/sh
source ~/.zshrc

# Enable alias
if [ -n "$ZSH" ]; then
    shopt -s expand_aliases
fi

# Files used
LIB_FILE="libftprintf.a"
SRC_FILE="test.c"
EXE_FILE="a.out"

# Compile
ccw $SRC_FILE $LIB_FILE -o $EXE_FILE

# Execution
if [ $? -eq 0 ]; then
    ./$EXE_FILE
else
    echo "Compilation failed."
fi

