Answer to the Easy challenge for ShockSoc's brainfuck competition
Written by Nathan van Doorn!
Throughout the memory layout is as follows:
cell 0: the total so far
cell 1: working space used so we don't lose the number we're 
adding to the total as we add it
cell 2: the number we are adding
cell 3: the number of numbers we have left to add of this 
multiple
we add 666 multiples of 3 because 3*666 is less than 2000 is less 
than or equal to 3*667
we add 399 multiples of 5 because 5*399 is less than 2000 is less 
than or equal to 5*400
however this adds numbers that are multiples of 15 twice, so
we subtract 133 multiples of 15 because 15*133 is less than 200 
is less than or equal to 15*134

>>> move to working space to calculate 666
++++++[>++++++<-]>+ cell 4 is now 37 = 6*6 plus 1
[<+++ +++ +++ +++ +++ +++>-]< cell 3 is now 666 = 37 * 18
[<+++[<+<+>>-]<[>+<-]>>-]<[-]> adds all the multiples of 3

> move to working space
+++++[>+++++<-]>[<++++>-]<[<++++>-]<- calculate 399 
[<+++++[<+<+>>-]<[>+<-]>>-]<[-]> add all the multiples of 5

>+++ +++ +++ +++[<+++ +++ +++ ++>-]<+ calculate 133
[<+++ +++ +++ +++ +++[<+<->>-]<[>+<-]>>-]<[-] subtract all the 
multiples of 15

print the value; thanks esowiki!
<<[>>+>+<<<-]>>>[<<<+>>>-]<<+>[<->[>++++++++++<[->-[>+>>]>[+[-<+>]>+>>]<<<<<]>[-]
  
++++++++[<++++++>-]>[<<+>>-]>[<<+>>-]<<]>]<[->>++++++++[<++++++>-]]<[.[-]<]<