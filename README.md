
# Push_swap
I had a blast working on **push_swap**! This project was a serious logic puzzle. I decided to implement the Turk's algorithm, a complex but highly efficient sorting solution. The real challenge was adapting it to my code and fine-tuning each step of the movement strategy to ensure optimal performance. It was a great experience that proved my ability to understand, implement, and optimize existing solutions is just as valuable as creating a new one from scratch.

The project requires you to use two data structures: two stacks, which are named A and B. Initially, all the numbers are in stack A, and stack B is empty. The challenge is to manipulate these two stacks using the allowed operations to move all the numbers back to stack A in sorted order.

The permitted operations are:

+ sa ->	Swaps the top two elements of stack A.
+ sb ->	Swaps the top two elements of stack B.
+ ss ->	Performs sa and sb at the same time.
+ pa ->	Pushes the top element from stack B to the top of stack A.
+ pb ->	Pushes the top element from stack A to the top of stack B.
+ ra ->	Rotates stack A (the top element moves to the bottom).
+ rb ->	Rotates stack B.
+ rr ->	Performs ra and rb at the same time.
+ rra ->	Reverse rotates stack A (the bottom element moves to the top).
+ rrb ->	Reverse rotates stack B.
+ rrr ->	Performs rra and rrb at the same time.

This project is a fantastic exercise in algorithmic thinking and data structure optimization. The key is to find an efficient sorting strategy that can handle large numbers of elements while keeping the move count to a minimum.

## How use it

Clone the repo

```bash
git clone
```

Compile the code with

```bash
make
```
Use the checker_linux to validate the stack is sorter correctly (it will display OK)

```bash
ARG=" 9 7 12 3" ; ./push_swap $ARG | ./checker_linux $ARG
```

Use the pipe command and the wc -l command to count the number of movements

```bash
ARG=" 9 7 12 3" ; ./push_swap $ARG | wc -l
```

If you want more cases test, in the test_cases.txt there are some, you just have to copy and paste in the terminal


## resources I used to understand
+ https://medium.com/@ayogun/push-swap-c1f5d2d41e97
+ https://www.youtube.com/watch?v=wRvipSG4Mmk&t=1436s

