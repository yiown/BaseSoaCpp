#!/bin/bash

cppcheck --enable=all --inconclusive --force --verbose --check-library -I ../src/main/ -I /usr/include/ --suppress=missingIncludeSystem ../src 2> ../bin/cppcheckResult.txt

