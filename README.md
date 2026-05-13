*This project has been created as part of the 42 curriculum by lvan-win and yoneshev.*

# Description

In this project, we made a program that sorts a stack of integers in ascending order in the smallest amount of operations. We use two stacks, stack a and stack b. Before running the sorting algorithm, stack a contains the numbers from the input and stack b is empty.

The operations used are:
- sa (swap a): Swaps the first two elements at the top of stack a
- sb (swap b): Swaps the first two elements at the top of stack b
- ss: sa and sb at the same time
- pa (push a): Takes the first element at the top of b and put it at the top of a
- pb (push b): Takes the first element at the top of a and put it at the top of b
- ra (rotate a): Shifts up all elements of stack a by one, the first element becomes the last one
- rb (rotate b): Shifts up all elements of stack b by one, the first element becomes the last one
- rr: ra and rb at the same time
- rra (reverse rotate a): Shifts down all elements of stack a by one, the last element becomes the first one
- rrb (reverse rotate b): Shifts down all elements of stack b by one, the last element becomes the first one
- rrr: rra and rrb at the same time

(4 different sorting algorithms)

(output: print all operations, separated by newlines)

(benchmark mode)

# Instructions

# Resources

# Explanation and justification of selected algorithm

# Division of labour