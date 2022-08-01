#!/bin/bash

for x in paper pencil pen
do
	echo $x
done

for x in paper "a pencil" "two pens"
do
	echo $x
done
