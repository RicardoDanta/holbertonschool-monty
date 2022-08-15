# The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode.

## The monty program

- Usage: _monty file_
  - where file is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status _**EXIT_FAILURE**_
  - where _**<file>**_ is the name of the file.
- If the file contains an invalid instruction, print the error message **L<line_number>**: unknown instruction _**<opcode>**_, followed by a new line, and exit with the status EXIT_FAILURE.
  - where is the line number where the instruction appears.
  - Line numbers always start at 1.
- The monty program runs the bytecodes line by line and stop if either:
  - it executed properly every line of the file.
  - it finds an error in the file.
  - an error occured.
- If you can’t malloc anymore, print the error message _**Error: malloc failed**_, followed by a new line, and exit with status _**EXIT_FAILURE**_.
- You have to use _malloc_ and _free_ and are not allowed to use any other function from man malloc (realloc, calloc, …)

# Tasks

**1. push, pall**

Implement the push and pall opcodes.

**The push opcode**

The opcode push pushes an element to the stack.

- Usage: _push <int>_
  - where _<int>_ is an integer
- if <int> is not an integer or if there is no argument given to push, print the error message _**L<line_number>**_: usage: _push integer_, followed by a new line, and exit with the status _**EXIT_FAILURE**_.
  - where is the line number in the file.
- You won’t have to deal with overflows. Use the _atoi_ function.

**The pall opcode**

The opcode pall prints all the values on the stack, starting from the top of the stack.

- Usage _pall_
- If the stack is empty, don’t print anything.
