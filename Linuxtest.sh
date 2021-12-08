#!/bin/bash
#script to execute with standard cmd like ls to test malloc : sh test.sh ${CMD}

export LD_PRELOAD=$PWD/libft_malloc.so
$@