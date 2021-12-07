#!/bin/bash
#script to execute with standard cmd like ls to test malloc : sh test.sh ${CMD}

export DYLD_LIBRARY_PATH=.
export DYLD_INSERT_LIBRARIES=libft_malloc.so
export DYLD_FORCE_FLAT_NAMESPACE=1
$@