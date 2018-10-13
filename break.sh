#!/bin/sh

for i in `seq 99 999`;
        do
                var=$(./access <<< $'david\n'$i'8\n')

                if echo "$var" | grep 'Success'; then
                  echo "The Password is: "$i'8'
                  break
                fi
        done
