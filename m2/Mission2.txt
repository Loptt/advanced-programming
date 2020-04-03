#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Please provide one book to change"
else
    cat $1 | sed 's/Sherlock/Carlos/g' | sed 's/hound/Erick/g' | sed 's/Hound/Erick/g' | sed 's/HOUND/ERICK/g' | sed 's/Baskervilles/Guatemala/g' | sed 's/Watson/10\/04\/20/g' | sed 's/danger/12\:30/g' > result.txt
fi 