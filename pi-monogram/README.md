# cisc210 monogram

bssmith.c program:

    This program presents the initials B.S. followed by a shamrock on the 
    Raspberry Pi SenseHat. The first letter, B, is presented on the SenseHat
    for 1 second, followed by the S for 1 second, and finally the shamrock 
    for 1 second.

Compilation Instructions:

    Compile the bssmith.c program with the following command:

        cc -o bssmith bssmith.c -L ~/lib -I ~/include -lsense

