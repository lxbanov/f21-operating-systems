#/bin/bash

file="integers.txt"
lck="${file}.lock" 

if [ ! -f $file ]
then
	echo 0 > $file
fi

while [ -f $lck ]
do
  :	
done
echo 0 > $lck
LASTNUMBER=`tail -1 ${file}`
NEXTNUMBER=`expr 1 + ${LASTNUMBER}`
echo $NEXTNUMBER >> $file
rm $lck
