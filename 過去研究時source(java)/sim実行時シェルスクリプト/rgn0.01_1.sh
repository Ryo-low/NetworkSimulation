#!/bin/bash
i=0;
x=10;
#for((i=0 i<x i++))
for i in `seq -w 1 100`
do
args=`echo $i| sed "s/^./&\./g"`
echo $args
/usr/java/default/bin/java at rgns 100 6 $args
done
