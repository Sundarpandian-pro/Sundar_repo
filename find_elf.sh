#!/bin/sh

echo "start of script"
find $1 -executable -exec du -h {} \; | sort -h
echo "end of script"
exit 0
