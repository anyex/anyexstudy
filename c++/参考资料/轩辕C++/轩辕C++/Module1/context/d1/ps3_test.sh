#!/bin/bash
PS3='Select an operation: '
select i in Time Info Users Quit
do
	case $i in
		Time) date;;
		Info) uname -a;;
		Users) w;;
		Quit) break;;
	esac
done
exit

