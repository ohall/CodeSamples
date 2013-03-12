#!/bin/bash
set -u
set -e





case "$1" in
	"compile-publish")
	command='compile publish';;
	
	"submodule")
	command='submodule';;
	
	"status")
	command='git status';;
	
	"pull")
	command='git pull';;
	
	"stash")
	command='git stash';;
	
	"push")
	echo "push not yet enabled"
	exit 1;;
	
	"checkout")
	command="git checkout $2";;

	"branch")
	command="git branch";;
	
	"man")
	echo 'commands:'
	echo './gitAll.sh compile'
	echo './gitAll.sh status'
	echo './gitAll.sh pull'
	echo './gitAll.sh submodule'
	echo './gitAll.sh stash'
	echo './gitAll.sh checkout <branch>'
	exit 1;;
	
	*)
	echo "wrong, try again!";;
esac

echo -e "\n\nperforming $1 for all S44jr ONLY repos in this workspace...\n\n"

for dir in $(ls) 
do	
	if echo $dir | grep -v '\.sh' | grep -v 'r180' | grep -v 'spi' | grep -v 'system44' | grep -v 'vendor' | grep -v 'Bulkloader' ; then
		cd $dir
		if [ "$command" = "submodule" ]; then
			echo "submodule..."
			git submodule init
			git submodule update
		elif [ "$command" = "compile publish" ]; then
			if [ -d "build" ]; then
				cd "build"
				echo "implement ant compile publish here  !!"
				cd ".."
			fi
		else
			$command
			echo -e "\n"
		fi
		cd ".."
	fi
done
echo "all $1 complete"

