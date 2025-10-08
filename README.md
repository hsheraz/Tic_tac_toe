# Tic-Tac-Toe Engine

## Overview
- Evaluates every reachable tic-tac-toe position by constructing a graph of boards in `htable`.
- Supplies an interactive game (`alphatoe`) that lets you play against the solver's optimal strategy.
- Includes utilities for counting reachable states and inspecting individual board nodes.

## Prerequisites
- POSIX shell with `make`
- C compiler that understands C99 (`clang` or `gcc`)

## Build
```
make alphatoe

```
This also compiles the shared support code (`ttt1.c`, `ttt2.c`) into the executable.

To build everything (interactive game plus helper tools):

```
make all

```

## Run the Interactive Game

```
./alphatoe

```
- Choose whether you play as `X` or `O` when prompted.
- Enter moves as digits `0`–`8`; the board positions correspond to the labels shown on the initial board.
- The solver replies instantly with its best move until the game ends in a win, loss, or tie.

## Helper Utilities
- `count_nodes`: Counts how many board states are actually reachable.
  ```
  make count_nodes
  ./count_nodes
  ```
- `show_node`: Prints the stored data for one or more board hashes.
  ```
  make show_node
  ./show_node 0 3280
  
  ```
  Hashes map directly to positions in `htable`; invalid hashes report as unreachable.

## Repository Layout
- `ttt.h`: Shared definitions, constants, and function prototypes.
- `ttt1.c`: Hash table storage and debugging helpers such as `print_node`.
- `ttt2.c`: Graph construction (`init_boards`, `join_graph`, `compute_score`, etc.).
- `alphatoe.c`: CLI game interface that uses the solver to play perfectly.
- `count_nodes.c`, `show_node.c`: Command-line utilities for analysis.
- `Makefile`: Targets for building the executables and `make clean` to remove build artifacts.

