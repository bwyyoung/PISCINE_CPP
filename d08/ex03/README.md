##Successful Tests (See Folder "Testing"):
- hello_world.b
- hello_world_torture.b
- bitwidth.b
- Tribit.b
- al-count-1.b
- Mandelbrot.b
- Mandelbrot-extreme.b
- Mandelbrot-tiny.b
- Life.b
- Hanoi.b
- PIdigits.b
- Golden.b
- BusyBeaver.b
- Counter.b
- Beer.b
- Skiploop.b
- easy1.bf
- easy2.bf
- hard1.bf
- medium1.bf

testing files from:

https://github.com/rdebath/Brainfuck
- Original README.md is included as README_Repo.md

##Notes:

1. The BF program "bitwidth.b"; this is something of a torture test, if your interpreter correctly executes this anything else is likely to be dead easy. 

  But the official output of the Bitwidth program is a display of the cell size ie:

  <dl><dt>8 Bit cells<dd>Hello World! 255<dt>16 Bit cells<dd>Hello world! 65535<dt>32 bit cells<dd>Hello, world!</dl>

  Though before you try it you might like to try this slightly less nasty Hello World! 

  ```brainfuck
  1 []><[][]><[][]><[][]><[][]><[][]><[][]><[][]><[][]><[][]><[]
  2 []>+>+>++>++<[>[->++++<<+++>]<<]>----.>->+.+++++++..+++.<+[]
  3 [ This is hellbox, a 104 command Hello World               ]
  4 [   >+>+>++>++<[>[->++++<<+++>]<<]>----.>>+.+++++++..+++   ]
  5 [   .>.<<<+++++++++++++++.>>.+++.------.--------.>+.>++.   ]
  6 [ -- Robert de Bath -- 2014                                ]
  7 []>>.<<<+++++++++++++++.>>.+++.------.--------.>+.+>++.<<<[]
  8 []><[][]><[][]><[][]><[][]><[][]><[][]><[][]><[][]><[][]><[]
  ```
  Lines 2 and 7 are the code that should be run, lines 1 and 8 are decorative and lines 3 to 6 can contain anything where each line is enclosed in [] and contains balanced brackets.
