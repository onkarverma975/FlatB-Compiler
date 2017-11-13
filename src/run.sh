#!/bin/bash
make;
./bcc $1 2>llout;
llc llout;
gcc -o static llout.s;
rm llout.s;