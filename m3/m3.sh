#!/bin/bash

if [ $# -ne 1 ]
then
    echo "You must provide the HTML file as argument"
else
    cat $1 | egrep -e '>#[a-zA-Z0-9]+</' -o | tr -d '>#' | tr -d '</' | sort | uniq -c | sort -nr
fi

