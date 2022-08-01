#!/bin/bash

traverse(){

	echo $1

	for file in "$1"/*
	do
		traverse "${file}"
	done

}

traverse "$1"
