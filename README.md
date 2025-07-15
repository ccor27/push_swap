# push_swap

## Arguments validation
All of this should show a "Error" followed by new line

- dupllicated numbers
- numbers ordered
- more than 1 sign
- no-digit characters
- numbers and strings 1 2 "8 9" 0 5 (mixed)
- empty/blank strings "1 5 4" "" or "1 5 4" " "

# Turk algorithm

- validate that the stack A has more than 3 elements
	- if it not, just order it without the algorithm
	- if it so, apply the turk algorithm

- applying the algorithm
	- pass to the stack B 2 elements (it doesn't matter the order, I mean without calculating the cost and those things)
	- then each element of A has to have a target, in order to calculate the cost of movements
	- once the cost is calculated, we work with the one that has the minor cost
	- that will be repeated until the stack A has 3 elements
	- the stack B has to be ordered in descending order, in order to when we pass the elements from B o A, A will be ordered in ascending order

- how find out the target
	- know the value of the A's element we want to move
	- know each value of B's nodes/elements (values and order)
	- find out the smallest number that be larger than A's value (it is the target)
		- if there is not grater number, it will be the largest number, so it will be above the largest number of the stack
		- but what if A's value is smallest than each of the stack B?, then it will be the smallest of that stack

- the struct
	- index: a number to represent how each node should be (really I need this??)
	- pos: position of the node in the stack
