#!/bin/sh
# The contents of this file are subject to the InterBase Public License
# Version 1.0 (the "License"); you may not use this file except in
# compliance with the License.
#
# You may obtain a copy of the License at http://www.Inprise.com/IPL.html.
#
# Software distributed under the License is distributed on an "AS IS"
# basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
# the License for the specific language governing rights and limitations
# under the License.  The Original Code was created by Inprise
# Corporation and its predecessors.
#
# Portions created by Inprise Corporation are Copyright (C) Inprise
# Corporation. All Rights Reserved.
#
# Contributor(s): ______________________________________.

cd ..
FBTCS="$(pwd)"
export FBTCS
echo "FBTCS=$FBTCS"
cd bin

date

PATH=./bin:$PATH
export PATH
LD_LIBRARY_PATH=/usr/lib:./bin
export LD_LIBRARY_PATH
SHLIB_PATH=/usr/lib:./bin
export SHLIB_PATH
LD_RUN_PATH=/usr/lib:$FBTCS:./bin
export LD_RUN_PATH


echo Adding the necessary users to security.fdb...

gsec -delete qa_user1
gsec -delete qa_user2
gsec -delete qa_user3
gsec -delete qa_user4
gsec -delete qa_user5

gsec -add qa_user1 -pw qa_user1
gsec -add qa_user2 -pw qa_user2
gsec -add qa_user3 -pw qa_user3
gsec -add qa_user4 -pw qa_user4
gsec -add qa_user5 -pw qa_user5

# test v4_api15
gsec -delete guest
gsec -add guest    -pw guest
# series gf_shutdown &  gf_shut_l1
gsec -delete shut1
gsec -add shut1    -pw shut1
# series gf_shut_l1
gsec -delete shut2
gsec -add shut2    -pw shut2
# series nist3
# series procs_qa_bugs, test bug_6015
gsec -delete qatest
gsec -add qatest             -pw qatest


if [ $? != 0 ]; then
    echo "ERROR: Failure adding users"
    exit 1		# failure adding users
fi

echo Testing...

echo test type : $1
echo test name : $2
mkdir -p ../temp
mkdir -p ../output

./tcs $1 $2