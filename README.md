# BSQ

This is a C program that search for the Biggest SQuare possible in a flield full of obstacles.
Project for semester 1 of the Epitech Elementary Programming in C module (B-CPE-110).

### Description

Algorithm for finding the largest possible square on a game board while avoiding obstacles. The array can be obtained in two ways. The first involves reading a file passed as an argument to the program.

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

## Acknowledgments

* [Epitech](https://www.epitech.eu/)

## Authors
* **Daniel Sanchez** ([GitHub](https://github.com/angsanch) / [LinkedIn](https://www.linkedin.com/in/angeldanielsanchez/))

## License
This project is licensed under the GNU Public License version 3.0 - see the [LICENSE](LICENSE) file for details.
