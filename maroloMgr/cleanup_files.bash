#!/bin/bash

# for file in */*; do if [ -f $file ]; then echo ${file%.c}; fi; done

for file in */*.c; do
#       if [ -d $file ]; then
       	       if [ -f $file ]; then
		       echo $file
		       #filename=${file##*/}
		       filename=${file%.c}
		       echo $filename
	
		       csplit $file --prefix $filename. \
	       		              --suffix-format='%03d.c' \
			             --elide-empty-files /\#include/

		       mv $filename.001.c $file
		       rm -f $filename.000.c
#	       fi
#       	       cd ..
       fi
done

