# Description #
## The Monty Language ##
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

**Monty byte code files**

Files containing Monty byte codes usually have the `.m`extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

~~~
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
~~~

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

~~~
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
~~~
## Allowable opcodes and what they do


|opcode  |  functionality|
| --- | --- |
| push | add element to the 'top' of stack and 'end' of queue  |
| pop  | remove element from 'top' of stack and 'end' of queue |
|pall  |print every member of the structure|
| pint | prints the member value at the top of stack |
| swap | swaps the order  of the 1st and 2nd elements in stack |
| add | add top two member values |
| sub | subtract the top element from the 2nd top element |
| div | divide the 2nd element by the top element |
| mul | multiply the top two elements of the stack |
| mod | the remainder when the 2nd element is divided by the top element |
| comment | there is the ability to parse comments found in bytecode ->'#'|
| pchar | print character at the top of the stack |
| pstr | print the character at the top of the stack|
| rotl | moves element at the top to the bottom of the stack |
| rotr | the bottom of the stack becomes the top |
| queue, stack | toggles the doubly link list implementation style |
| nop | opcode should do nothing |

## Compilation & Output ##
* Your code will be compiled this way:

~~~
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
~~~

## Authors ##
* Michael NWOGHA - [github](https://github.com/michaeldecent) || [linkedin](https://www.linkedin.com/in/michael-nwogha-2b3b8a246)
* Wonderful ADEYEMO - [github](https://github.com/Dev-wonderful) || [linkedin](https://www.linkedin.com/in/wonderful-adeyemo-4789121a3)

## Files and Functions ##
### add_node.c ###
add_node - adds a new node to the stack

### add_queue.c ###
f_queue - function that prints the top of the queue
addqueue - function that adds a node to the tail of the queue 

### handle_opscode.c ###
execute - executes the opcode

### mem_mgt.c ###
free_stack - frees the stack
f_stack - function that prints the top of the stack
