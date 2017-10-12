#!/bin/bash

for name in *.c ; do
	touch ${name%%c}h
done
