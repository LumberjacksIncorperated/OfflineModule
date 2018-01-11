#!/bin/bash

#------------------------------------------------------------------------------------------
#*
#* PURPOSE
#* -------
#* For use by the 'Haystack Application Offline Module' to decrypt received message and
#* create the plaintext message files
#*
#* AUTHOR
#* ------
#* Lumberjacks Incorperated (2018)
#*
#------------------------------------------------------------------------------------------

#------------------------------------------------------------------------------------------
# MAIN
#------------------------------------------------------------------------------------------
main() {
    echo "Attempting to decrypt all encrypted messages..."
    iterateThroughFilesAndDecrypt
    echo "... Done"
}

#------------------------------------------------------------------------------------------
# INTERNAL FUNCTIONS
#------------------------------------------------------------------------------------------
function iterateThroughFilesAndDecrypt()
{
    let "i = 0"
    cwd=$(pwd)

    for filename in "$cwd"/ToDecrypt/*; do
        echo "Attempting to decrypt file $i which is $filename"
        cat "$filename" | openssl rsautl -decrypt -passin pass:passphrase  -inkey private.pem > "recieved$i.txt"
        mv ./"recieved$i.txt" ./Decrypted/
        i=$((i+1))
    done
}

#------------------------------------------------------------------------------------------
# SCRIPT
#------------------------------------------------------------------------------------------
    main
