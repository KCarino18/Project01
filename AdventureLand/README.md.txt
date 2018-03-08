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

comparestring()

check_logics()


