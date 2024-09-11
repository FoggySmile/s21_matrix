#!/bin/bash
echo -e "\n"
echo "*********************_________*********
***********************_______*********
***********************_______*********
*****************************__**************
_____________________********________********
_____________________********________********
______***********************________********
______***************_*______________********
______***************_*______________********
______***************________________********
*********************________________********
********_____________________________********
********_____________________________********
*****************************________********
______***********************________********
______***********************________********
______***********************________********"

echo "__  ___/__  ____/___  / / /__  __ \__  __ \___  / 
_____ \ _  /     __  /_/ / _  / / /_  / / /__  /  
____/ / / /___   _  __  /  / /_/ / / /_/ / _  /___
/____/  \____/   /_/ /_/   \____/  \____/  /_____/"

echo -e "\nMiniVERTER is watching your code...¯\_(*_*)_/¯\n"
echo -e "-------------------------------------------------------------------------------\n"
echo -e "Style test\n"
STYLE_TEST_SCRIPT=tests/style_tests.sh
OUTPUT=$(bash ${STYLE_TEST_SCRIPT})
printf 'Style test output:\n %s\n' "$OUTPUT"
STYLE_TEST_RESULT=${OUTPUT: -1}
printf 'Style test result: %s\n' "$STYLE_TEST_RESULT"
echo -e "-------------------------------------------------------------------------------\n"
BUILD_SCRIPT=ci-scripts/build.sh
OUTPUT=$(bash ${BUILD_SCRIPT} part1)
printf 'Build output:\n %s\n' "$OUTPUT"
BUILD_RESULT=${OUTPUT: -1}
printf 'Build result: %s\n' "$BUILD_RESULT"
echo -e "-------------------------------------------------------------------------------\n"
echo -e "\nMiniVERTER is staring your code...¯\_(*_*)_/¯\n"
cd src
make clean && make && make test
