#!/bin/bash

minargs=6

if [ $# -lt $minargs ]
then
    echo "som.sh error: expects 6 arguments; actual arguments count is $#";
else
    cat som.cpp | sed s/ASED/$1/g | sed s/BSED/$2/g | sed s/CSED/$3/g | sed s/DSED/$4/g | sed s/ESED/$5/g | cat > kohonen.cpp
    make ndebug
    rm kohonen.cpp
    if [ $6 == 'gnuplot' ]
    then
        ./kohonen > som.out
        cat som.out | sed s/\(.*\)//g > kohonen.out
        cat gnuplot.in | sed s/ASED/$1/g > kohonen.in
        gnuplot < kohonen.in
        rm kohonen.in kohonen.out
        mv kohonen.png "$1-$3x$4.png"
        mv som.out "$1-$3x$4.out" 
    elif [ $6 == 'stdout' ]
    then
        ./kohonen
    fi
fi
