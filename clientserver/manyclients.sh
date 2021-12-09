#!bin/bash

for j in $(seq 1 30)
do
	./wclient localhost 8000 /spin.cgi?10 &
	sleep 1
done
