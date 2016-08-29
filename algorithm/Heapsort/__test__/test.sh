#!/bin/bash

printf "\x1b[90m"
# mkdir compile
if [ -d __compile__ ]; then
    echo "Directory for compilation exists. Skipping."
else
    echo "Making directory for compilation."
    mkdir __compile__ -v
fi

# rm -rf ./compile/* -v
echo "Cleaning all files exist in ./compile/"

rm -rf ./__compile__/* -v

printf "\x1b[92mTesting starts.\x1b[90m\n"

cp ../*.cpp ./__compile__ -v
cp ../*.hpp ./__compile__ -v

printf "\x1b[0m"

declare -i cext eext 
# cext: compilation exit code
# eext: execution exit code

for var in *.cpp; do
    echo "===================="
    printf "Using test case\x1b[33m $var \x1b[0m\n"
    cp $var ./__compile__/main.cpp
    # Compilation
    cd __compile__
    echo "--------------------"
    printf "\x1b[92mCompilation starts.\x1b[0m\n"
    g++ ./*.cpp -g
    cext=$?
    printf "Compiler exit code: $cext\n" 

    # redirect error message
    if [ $cext -ne 0 ]; then
        g++ ./*.cpp ./*.hpp &> ../$var-compile.log -g
        printf "\x1b[31mCompiler message redirected to ../$var-compile.log.\x1b[0m\n"
    fi
    printf "\x1b[92mCompilation finished.\x1b[0m\n"
    echo "--------------------"

    # Execution
    if [ $cext -eq 0 ]; then
        printf "\x1b[94mExecution starts.\x1b[0m\n"
        echo "------OUTPUT-STARTS------"
        ./a.out
        eext=$?
        echo "-------OUTPUT-ENDS-------"
        printf "Test case exit code: $eext\n"

        # redirect stdout output when non-zero exit code
        if [ $eext -ne 0 ]; then
            printf "\x1b[31mNon-zero exit code.\x1b[0m\n"
            ./a.out &> ../$var-exec.log
            cp ./a.out ../$var.out
            printf "\x1b[91mExecution output is redirected to ../$var-exec.log.\x1b[0m\n"
            printf "\x1b[91mExecutable is copied to ../$var.out\x1b[0m\n"
        fi

        printf "\x1b[94mExecution finished.\x1b[0m\n"
        echo "--------------------"
    fi
    cd ..
done

echo "===================="
printf "\x1b[92mTesting finished.\x1b[0m\n"