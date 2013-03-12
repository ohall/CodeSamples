#!/bin/bash
# Enters every submodule "include" directory and does a git pull. If there were any updates,
# the new commit id is commited.


set -e
set -u

PROJECTS=`ls -1 | grep -v -E '*.sh$' | grep -v Servers`

for i in ${PROJECTS}; do
	echo "PROJECT==== $i;"
	cd $i;
	if [[ -d include ]]; then
		cd include
		git checkout master
		git pull
		cd ..
		SOMETHINGNEW=`git status | grep 'modified:   include' | wc -l | awk '{print $1}'`
		if [[ ${SOMETHINGNEW} -eq "1" ]]; then
			echo "== Commiting includes"
			git add include
			git commit -m "updating includes"
		else
			echo "== Nothing to do"
		fi
	fi
	echo "END========"
	cd ..
done;