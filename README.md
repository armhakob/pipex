# pipex

**pipex** is a project from the 42 curriculum that involves recreating the behavior of the Unix shell pipeline (`|`). It introduces the concepts of processes, file descriptors, and inter-process communication using pipes.

## Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [How It Works](#how-it-works)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Example](#example)

## About the Project

The **pipex** project replicates the Unix shell's pipeline functionality. It demonstrates the use of:

- Forking and executing processes.
- Redirecting input and output with file descriptors.
- Communicating between processes with pipes.

## Features

- Recreates the behavior of `cmd1 | cmd2 > outfile`.
- Handles errors gracefully, including invalid commands or file permissions.
- Processes multiple commands in a chain.

## How It Works

1. **Input redirection**: The program reads input from a file instead of standard input.
2. **Process creation**: It forks processes to execute commands.
3. **Piping**: Data from the first command's output is passed as input to the next command via pipes.
4. **Output redirection**: The final output is written to a file.

## Getting Started

### Prerequisites

- A C compiler (GCC or Clang).
- GNU Make.

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/armhakob/pipex.git
   cd pipex
2. Compile the program:
   ```bash
   make
   ```
This will create the `pipex` executable.

### Usage

Run the program with the following syntax:
```bash
./pipex infile "cmd1" "cmd2" outfile
```

- `infile`: The input file containing data for the first command.
- `cmd1`: The first command to execute.
- `cmd2`: The second command to execute.
- `outfile`: The file where the final output will be written.

### Example

Suppose you have the following input file `input.txt`:
```

Hello, world!
```
You can run:
```bash
./pipex input.txt "cat" "wc -w" output.txt
```
This will:
1. Read from `input.txt`.
2. Pass the output of `cat` (`Hello, world!`) to `wc -w` (count words).
3. Write the result (`2`) to `output.txt `.

Check the result:
```bash
cat output.txt
```
Output:
```

2
```
