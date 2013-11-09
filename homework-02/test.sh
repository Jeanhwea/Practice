#!/bin/bash
until [ $# -eq 0 ]; do
	echo "/v"
	./run /v $1 
	echo "/h"
	./run /h $1 
	echo "/v /h"
	./run /v /h $1 
	./run /h /v $1 
	shift
done
