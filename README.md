# 42 Project - minishell

**minishell** is a simple Unix shell implementation written in C, created as part of the 42 curriculum. The goal is to replicate some basic functionalities of a shell, such as command execution, piping, redirection, and managing environment variables.

## Features

- **Command execution**: Execute commands and programs using the shell prompt.
- **Pipes**: Support for piping between commands (e.g., `command1 | command2`).
- **Redirection**: Handle input and output redirection (e.g., `command > file` or `command < file`).
- **Environment variables**: Get, set, and unset environment variables (e.g., `echo $PATH`, `export VAR=value`).
- **Command history**: Ability to store and cycle through previously executed commands.
- **Built-in commands**: Implements a few built-in shell commands:
  - `cd`: Change directory.
  - `exit`: Exit the shell.
  - `echo`: Print text to the terminal.

## Installation

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/forestbearx/minishell.git
   cd minishell
   ```

2. Compile the project using `make`:
   ```bash
   make
   ```

   This will generate the `minishell` executable.

## Usage

After compiling the project, you can run your shell with the following command:

```bash
./minishell
```

This will start your custom shell. You can execute commands, pipe them, or use redirection as in a typical Unix shell.

Example:

```bash
./minishell
$ echo "Hello, world!" > hello.txt
$ cat hello.txt
Hello, world!
$ exit
```

## Functionality

### Shell Commands

- **Command Execution**: The shell can execute external commands (e.g., `ls`, `cat`, etc.).
- **Pipes**: Supports piping between commands using the `|` symbol.
- **Redirection**: Supports both output (`>`) and input (`<`) redirection.
- **Environment Variables**: Allows reading and modifying environment variables.
- **Built-in Commands**:
  - `cd [directory]`: Change the current working directory.
  - `exit`: Exit the shell.
  - `echo [text]`: Print a string to the terminal.

### Example of usage

```bash
$ minishell
$ echo "This is a test" | grep "test"
This is a test
$ cd /home
$ echo $PWD
/home
$ exit
```

## Testing

You can test your shell with a series of test cases. There is a `tests` folder where a few example scenarios are provided to ensure that the functionality works as expected. Run:

```bash
make test
```

to execute the test cases.

## Contributing

Feel free to fork the repository and submit improvements. If you find any bugs or have suggestions, open an issue or submit a pull request.

## License

This project is open-source and licensed under the MIT License.
