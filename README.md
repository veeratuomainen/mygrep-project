This is a final project for C++ Advanced programming course. It is a program inspired by Linux grep command and works similarly to grep. 

You can start the program with no command line arguments. This way ut will ask for two strings: a string from which to search from and a search string. If search 
string is found in the other string, the program will tell the position it is found in. If not found, the program will tell that search string is not found.

You can also start the program with two command line arguments: the word you're searching for and the file you're searching from. The program will print out all of the rows
of the file in which the word appears in. 

You can also add a third command line argument. The options for this are "-oo", "-ol" and "-olo". "-oo" will tell how many rows are being printed. "-ol" will tell you the row
number in which the word was found. "-olo" will tell you both of these things.

Starting the program could look like this with all arguments: ./mygrep -olo hey test-file.txt
