#!/bin/bash
set `users`
trap ctrl_c INT
ctrlccount=0

function ctrl_c() {
  if [ $ctrlccount -eq 1 ];then
    exit
  fi
  if [ $ctrlccount -eq 0 ];then
    echo "(SIGINT) ignored. enter ^C 1 more time to terminate program."
    ((ctrlccount++))
  fi
}
func()
{
	i=0
nerds2=0
diff=0
set `users`
users2=("$@")
while [ true ];
do
  set `users`
  users1=("$@")
  date
  echo "# of users: "
  nerds1=`who | wc -l`
  who | wc -l
  ((diff=$nerds1-$nerds2))
  while [ $diff -gt 0 ]; do
     echo "> ${users1[$diff-1]} logged in to `hostname`"
     ((diff--))
  done
  if [ $diff -lt 0 ]; then
     temp=1
     missing=0
     while(${#users2[*]} -gt $temp-1); do
	if [ ${users2[$temp+$missing]} -ne ${users1[$temp]} ]; then
	  echo "> ${users2[$temp+$missing]} logged out of `hostname`"
	  ((missing++))
	fi
	((temp++))
     done
  fi
  ((nerds2=nerds1))
  sleep 10
  ((i++))
  users2=("$@")
done
}
func


