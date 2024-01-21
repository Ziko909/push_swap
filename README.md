# PushSwap

![intro](pushswap.gif)

## Table of Contents

- [Description](#description)
- [Usage](#usage)
- [Algorithm Implementation](#algorithm-implementation)
- [Helpful Resources](#helpful-resources)
- [Contact Information](#contact-information)

## Description

PushSwap stands as one of my significant achievements. This project revolves around efficiently sorting data using a restricted number of operations, adding complexity to the task. Instead of relying on existing algorithms, I collaborated with peers to devise an innovative solution. Our approach proved to be lightning-fast and remarkably effective, successfully sorting the data with the minimal required operations.

## Usage

### Mandatory Part

To use the mandatory part of PushSwap, follow these steps:

1. Run the `make` command to compile the program.
2. Execute the binary with some numbers as arguments. For example:

```
$ ./push_swap 1 2 3 4 5
```

### Bonus Part

To use the bonus part of PushSwap, follow these steps:

1. Run the `make bonus` command to compile the program.
2. Execute the binary with some numbers as arguments. For example:

```
$ ./checker 1 2 3 4 5 
```

## Algorithm Implementation

1. **Index the numbers on stack A by their order in the list.** Assign an index to each number in the list, starting from 0 for the smallest number and incrementing by 1 for each larger number. For instance, in the list [7, 2, 0], 7 would have the highest index, followed by 2 and then 0.

2. **Determine the appropriate range based on the size of stack A.** The range defines the numbers that will be pushed onto stack B during each iteration. If the size of stack A is less than or equal to 250, use a range of [0, 15]. For larger stacks (size greater than 250), use a range of [0, 35].

3. **Push numbers within the range onto stack B.** Iterate through the numbers in stack A and push those that fall within the current range onto stack B.

4. **With each push operation, increment the range by 1.** This ensures that a wider range of numbers is considered during subsequent iterations.

5. **Return numbers from stack B to stack A in reverse order.** After emptying stack A, start returning numbers from stack B to stack A. Begin with the number that has the highest index in stack B and continue returning numbers in decreasing order of their indices.

By following these steps, you can effectively implement the algorithm.

## Helpful Resources

- [Sorting Algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Data Structures](https://en.wikipedia.org/wiki/Data_structure)
- [Divide and Conquer Algorithms](https://en.wikipedia.org/wiki/Divide_and_conquer_algorithm)

## Contact Information

- GitHub: [Ziko909](https://github.com/Ziko909)
- LinkedIn: [Zakaria Aabou](https://www.linkedin.com/in/zakaria-aabou)
- Gmail: aabou.zakaria909@gmail.com
