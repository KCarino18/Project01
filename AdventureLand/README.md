This is the changes that have been made to Adventure Land whilst converting it to c++

wherex() - 
was originally unavaliable for C++ compilers due to only being on Borland compilers. I was able to find the windows version of it and made a function that is called wherex


clearScreen() - 
originally clrscr(), this function was also unavaliable in C++ due to the compiler, but was able to also find the windows version by doing #include <windows.h>

yes_no() - gets user input on y or n and returns 1 is y and 0 if n

empty_keyboardbuffer() - emptys keyboard buffer

welcome() - displays the welcome message

get_input() - gets users input

look() - prints location details

get_item_string() - discards unwanted strings at end of item desc.

turn() - makes you move in certain directions

action() - actions to do such as picking up

get_action_variable() - gets what you are going to do

carry_drop() - if you can carry or drop, does it

length() - gets length of space

copystring() - copies the name of item

comparestring() - Compares two different strings

check_logics() - Checks Boolean Value

- Changes Log -
1.0 - Able to Compile and function
    - fixed clearscreen

1.1 - Replaced all printf with cout and made changes to make the strings and variables work
    - Added AXE class that gives the axe its own class to judge whether the player has the axe in hand to kill the dragon

1.2 - Implemented a Player Class

1.3 - Implemented Treasure Classes

1.4 - Made some of the older functions take in the Player Class upon usage

1.5 - Made some changes to old classes and combined them into a vector of the classes to help reduce the amount of use.