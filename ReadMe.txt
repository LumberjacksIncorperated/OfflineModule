###########################################################################################################
#
#
#                                      Haystack Application Offline Module
#
#                                         Lumberjacks Incorperated (2018)
#
###########################################################################################################

IMPORTANT NOTICE
----------------

    For this offline module to work as intended, the computer that runs this module should be pulled
    offline COMPLETELY as soon as the repo is intially cloned

    In other words, for complete security you need an offline OSX device.

    For the highest level of security possible, to make sure the device is completely offline, the wifi
    and other connection drivers must be PROPERLY deleted, not just removed from kernal, as well as if
    you are up for it, physically damaging the connection cards and ports beyond use.

    All damage is your own responsibility though....

Instructions For Setup
-----------------------
    
    1. Clone repo into a folder of your choice
    2. Run the 'Install.sh'
    3. Run 'HaystackOffline' application

Instruction For Use
--------------------

    (For Use In Conjuntion with the Haystack Online Module)
    
    For Adding A Contact:

        1. Place thier '*.pem' public key file into the base module foler (*/Offline/), as {thier-name}.pem

        When running the offline application to create an encrypted message, if the file you place
        is called 'Alice.pem', then the name you type when prompted for the recipient name is 'Alice'

    For Sending A Message:

        ************************************ WARNING *****************************************
        Never send the exact same message to the exact same person twice
        (Otherwise it is possible to gain information as an attacker about you as the user)
        **************************************************************************************


        1. Run application

        2. Choose send message
           -> You will have to enter recipient name (under 90 charcters)
           -> You will have to enter the message (under 90 characters)
           *If you dont stick to these limits, you will only sabotage yourself

        3. Plug a USB into computer onto which place the resulting 'encodedMessage' file onto the USB, and
           ONLY this file

        This is the encoded message file that you will place on the online OSX computer running the
        'Haystack Online Module' application.

        ***************************** TO WRITE A DUMMY MESSAGE ***********************************
        First, they must be unique, then encrypt with recipient name 'public' to use your own
        public key
        ******************************************************************************************

    Note: Do NOT place the plaintext file onto this USB, the only file that comes off is the encrypted file

    For Recieving Files:
    
        1.  After obtaining a folder containg the file from only 'Haystack Online Module' Application,
            put the USB containing these files into the offline computer

        2.  Places all of these encrypted message files in the (*/Offline/ToDecrypt/) folder

        3.  Run 'HaystackOffline' application

        4.  Choose Read Messages

        5.  After this is finished, you should find the plain text files in the decrypted file

        Note: Never copy these plain text files off the offline computer!
    
