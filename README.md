# BSQ

This is a C program that search for the **B**iggest **SQ**uare possible in a field full of obstacles.

Project for semester 1 of the Epitech Elementary Programming in C module.

### Description

This project is a coding challenge that focuses on identifying the largest square of empty cells in a grid filled with obstacles. The input consists of a rectangular grid filled with characters representing obstacles and free spaces, or a pattern to generate this grid with. The objective is to identify the largest contiguous square of free spaces and draw it on the map. This project requires you to use dinamic memory and basic optimization, brute force is not enough for tasks this big.

## Getting Started

### Dependencies

- [Linux](https://linux.org/)
- [Make](https://www.gnu.org/software/make/)
- [GCC](https://gcc.gnu.org/)
- [LibC](https://www.gnu.org/software/libc/)

### Installation

* Download/Clone the repository and enter its directory
* Compile the code typing `make`

## Usage
### File example
`./bsq file`
```
$ ./bsq tests/maps/small_example
...............
o.o............
......o........
.o.............
.o.........o...
o...o..........
....o....o.....
...xxxxx..o....
...xxxxx.o.....
...xxxxx.......
..oxxxxx..o...o
...xxxxx.......
....o...o....o.
.....o.........
........o......
```
### Pattern execution
`./bsq size "pattern"`
```
$ ./bsq 6 “..o..”
..oxx.$
.o.xx.$
o....o$
....o.$
...o..$
..o...$
```
### If you want to generate new random maps you can use this command
```
perl tests/generator.pl width height density > new_map && ./bsq new_map
```

## Innerworkings

### Data structure and data input

When loading bigger maps, performance really started to take a hit, this was caused by the amount of system calls that were being made. For each system call, your OS has to stop your program, change context, fulfill the call, change the context back and then it can continue executing your program. So to avoid loosing time its better to make bigger but less frequent system calls.

In the first implementation, the file was read, each line checked individually and then copied to an array. This is not optimal mainly for 2 reasons, space for each line had to be allocated(system call) individually and the information is duplicated in memory, so this approach is far from optimal in both processing and memory use.

In the second implementation, instead of copies of the lines, the array stores pointers to where the beginning of each line is expected to be inside of the buffer. The estimation is made based on the length of the first line, lines are later checked for correct length. This also facilitates the printing of the result as the buffer can be printed in one single block, in comparison to having to print each line individually.

In conclusion, the second implementation has much better memory management which makes the program faster and lighter, without any considerable drawbacks.

**n = number of lines**

|                                             | 1        | 2             |
|---------------------------------------------|----------|---------------|
| **Memory use (assuming square map)**        | 2n²  + n | _**n²  + n**_ |
| **System calls (allocate, read and print)** | 2n + 2   | _**3**_       |


### In the search of the square

This algorithm is almost as simple as can be, in every cell it will try to create the biggest square it can, taking the given cell as it top left corner. It remembers where the biggest square was the it draws it. But this has 2 small optimizations. To check size of the biggest square is the more time consuming task of this part of the program, so any small improvements in its performance will have a great impact. It is also important to be sure of when to use it, the least times it is used the better.

#### Square checking

The easy solution here would have been to make a function that takes a coordinate and a square size, then returns if a square of that size in that position is possible. Then call this function until a size no longer fits, but this would cause the same area to be checked several times. The solution to this is to check the square progressively, start checking the cell where the square starts (1x1 square), then add a row in the bottom and a row on the right (2x2 square), and keep adding columns and rows until it hits and obstacle.

#### Valid cells

This is used to discard cells where we are sure that a bigger square than of what has already been found is impossible. This is done taking the proximity to the lower and right borders of the map, the distance from these 2 borders has to be greater than the size of the current biggest square. If those cells are checked, it can be guaranteed that the square will hit the wall before being able to get the necessary size.

## Acknowledgments

* [Epitech](https://www.epitech.eu/)

## Authors
* **Daniel Sanchez** ([GitHub](https://github.com/angsanch) / [LinkedIn](https://www.linkedin.com/in/angeldanielsanchez/))

## License
This project is licensed under the GNU Public License version 3.0 - see the [LICENSE](LICENSE) file for details.
