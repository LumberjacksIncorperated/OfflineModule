#!/bin/bash

#------------------------------------------------------------------------------------------
#*
#* PURPOSE
#* -------
#* For use by the 'Haystack Application Offline Module' to set up a clients OpenSSL Software
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
   printf "\n   >> The following steps are needed to set up this client\n"
   printf "   >> Please follow the given instructions\n\n"
   setupOpenSSLClient
   printf "\n\n   >> Done\n\n"
}

#------------------------------------------------------------------------------------------
# INTERNAL FUNCTIONS
#------------------------------------------------------------------------------------------
function setupOpenSSLClient()
{
   openssl genrsa -des3 -out private.pem 2048
}

#------------------------------------------------------------------------------------------
# SCRIPT
#------------------------------------------------------------------------------------------
    main