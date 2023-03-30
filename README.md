# push_swap
Sorting a stack with basic operations such as pushes, swaps and rotations... in the least amount of moves possible!


# Overview
First, a random amout of integers is given, these number are going to be stored inside a stack called A.
- N.B. a stack is a basic data structure that allows to insert (and remove) elements only from the end of it (LIFO)
- N.B. there cannot be any duplicate among the numbers 

Also an auxiliary empty stack B is provided, it is going to be used as temporary deposit for elements from stack A.
The goal is to sort the numbers inside stack A in ascending orders (stack B must be empty at the end): the output of the program is going to be the sequence of operations to apply on stack A and B to sort the set of numbers.

As mentioned before, only the following operation on stacks are allowed:

| NAME	            | COMMAND |	DESCRIPTION																		    						|
|-------------------|---------|-------------------------------------------------------------------------------------------------------------|
| PUSH A            | pa      | puts the element on top of stack B to the top of stack A													|
| PUSH B            | pb      | puts the element on top of stack A to the top of stack B													|
| SWAP A            | sa      | swaps the positin of the first two elements of stack A														|
| SWAP B            | sa      | swaps the positin of the first two elements of stack B														|
| SSWAP				| ss      | does SWAP A and SWAP B at the same time																		|
| ROTATE A          | ra      | shifts the position of every element of the stack A by 1, ascending order (n -> n+1, last became the first)	|
| ROTATE B          | rb      | shifts the position of every element of the stack B by 1, ascending order (n -> n+1, last became the first) |
| RROTATE           | rr      | does ROTATE A and ROTATE B at the same time																	|
| REVERSE ROTATE A  | rra     | shifts the position of every element of the stack A by 1, descending order (n -> n-1, first became the last)|
| REVERSE ROTATE B  | rra     | shifts the position of every element of the stack B by 1, descending order (n -> n-1, first became the last)|
| REVERSE RROTATE	| rrr     | does REVERSE ROTATE A and REVERSE ROTATE B at the same time										     		|

Lastly, a checker is available to verify that a sequence of actions actually sorts the stack: it takes the list of instructions and then will prints 'OK' or 'KO' depending on the outcome.


# Execute
- the command `make` creates the executable `push_swap` for standard part;
- the command `make bonus` creates the executable `checker` for bonus part;
- both the executables take as a parameter the set of integers (**no duplicates!**) given as a sequence of numbers separated by a space either inside or not double quotes
- other make commands: `re`, `clean`, `fclean`


# Structure
	include\  	--> header files
	objects\  	--> deposit for object files
	libft\    	--> libft directory with auxiliary functions
	sources\  	--> source files:
		basic_moves.c     --> implementation of the operations swap, push, ..., on stacks
		bonus.c           --> helper functions for the bonus part (checker)
		checker.c         --> main file for bonus part
		checks.c          --> controls of various type
		count_moves.c     --> manages basic rotations/rrotations on stacks
		finder.c          --> functions to find certain target inside a stack
		push_swap.c       --> main file for main part
		sort.c            --> higher level sorting functions
		stack.c           --> functions to work with stacks
		turk.c            --> middle-level functions to sort the stack using the turk algorithm (see #References)

# Note
Because of the requirements of this projects, it hasn't been used a 'famous' sorting algorithm, instead, every move is carefully calculated and weighed in a way that, at the end, only the least amount of actions is going to be executed; see #References for more info about the algorith used.


# References
- About the [algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- 42 project: [push_swap](https://cdn.intra.42.fr/pdf/pdf/73983/en.subject.pdf)
- By: Francesco Aru, francesco.aru25@gmail.com, intra42/slack nickname: @faru, Codam, Amsterdam
