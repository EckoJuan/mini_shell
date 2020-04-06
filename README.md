> # Everything you need to know to start coding your own shell!

---

 ![README](https://img.shields.io/badge/README-OK-green.svg?colorB=00C106) ![Shell](https://img.shields.io/static/v1?label=Shell&message=Basic&color=blue) ![PRUEBA](https://img.shields.io/github/repo-size/EckoJuan/mini_shell)    ![made-with-Markdown](https://img.shields.io/badge/Made%20with-Markdown-1f425f.svg) ![LAST_COMMIT](https://img.shields.io/github/last-commit/EckoJuan/mini_shell)
![CONTRIBUTORS](https://img.shields.io/github/contributors/EckoJuan/mini_shell)
![activity](https://img.shields.io/github/commit-activity/m/EckoJuan/mini_shell)
---
![SHELL](![https://raw.githubusercontent.com/computingfoundation/gnu-linux-shell-scripting/images/logo.png](https://raw.githubusercontent.com/computingfoundation/gnu-linux-shell-scripting/images/logo.png)

---

> ## Table of Contents

* [Introduction](#Introduction)
* [Project information](#Project-information)
* [Documentation](#Documentation)
* [Extra information](#Extra_information)
	* [SYSCALL](#SYSCALL)
	*  [Fuction](#Fuction)
	* [Interactive mode / Non-interactive mode](#Interactive-mode-/-Non-interactive-mode)
* [You must know how this works](#You_must_know_how_this_works)
	* [PID](#PID)
	* [PPID](#PPID)
	* [GETLINE](#GETLINE)
	 * [STRTOK](#STRTOK)
	* [ARGUMENTS](#ARGUMENTS)
	 * [EOF](#EOF)
	* [FORK](#FORK)
	* [WAIT](#WAIT)
	* [EXCECVE](#EXCEVE)
	 * [STAT](#STAT)
	* [PATH](#PATH)
	* [ PRINTENV](#PRINTENV)
	* [main](#main)
	* [env Vs environ](#env-Vs-environ)
	* [GETENV](#GETENV)
	* [SET](#SET)
	* [UNSET](#UNSET)
	

* [Exercise super simple shell](#Exercise:-super-simple-shell)

---
  

> ## Structure of a readme [Temp]
### Introduction

### Project information

### Documentation

### Extra information

#### SYSCALL

#### Fuction

#### Interactive mode / Non-interactive mode
* Interactive mode 
* Non-interactive mode

### You must know how this works

#### PID

A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process’ ID, you can use the system call `getpid` (man 2 `getpid`)

Man pages: [Man Pages](https://pages.github.com/)

#### PPID
Man pages: [Man Pages](https://pages.github.com/)
#### GETLINE
Man pages: [Man Pages](https://pages.github.com/)
#### STRTOK
Man pages: [Man Pages](https://pages.github.com/)
#### ARGUMENTS

The command line arguments are passed through the `main` function: `int main(int ac, char **av);`

- `av` is a `NULL` terminated array of strings

- `ac` is the number of items in `av`

  `av[0]` usually contains the name used to invoke the current program. `av[1]` is the first argument of the program, `av[2]` the second, and so on.

#### EOF
Man pages: [Man Pages](https://pages.github.com/)
#### FORK - SYSCALL

The system call `fork` (man 2 `fork`) creates a new child process, almost identical to the parent (the process that calls `fork`). Once `fork` successfully returns, two processes continue to run the same program, but with different stacks, datas and heaps.

  

Using the return value of `fork`, it is possible to know if the current process is the father or the child: `fork` will return `0` to the child, and the PID of the child to the father.

Man pages: [Man Pages](https://pages.github.com/)

#### WAIT - SYSCALL

The `wait` system call (man 2 `wait`) suspends execution of the calling process until one of its children terminates.

Man pages: [Man Pages](https://pages.github.com/)
#### EXCEVE - SYSCALL
Man pages: [Man Pages](https://pages.github.com/)
#### STAT - SYSCALL
Man pages: [Man Pages](https://pages.github.com/)



#### main
Man pages: [Man Pages](https://pages.github.com/)
#### env Vs environ

#### Environ

We have seen earlier that the shell uses an environment list, where environment variables are “stored”. The list is an array of strings, with the following format: `var=value`, where `var` is the name of the variable and `value` its value. As a reminder, you can list the environment with the command `printenv`

#### PATH

We have seen earlier that the shell uses an environment list, where environment variables are “stored”. The list is an array of strings, with the following format: `var=value`, where `var` is the name of the variable and `value` its value. As a reminder, you can list the environment with the command `printenv`
#### PRINTENV
Man pages: [Man Pages](https://pages.github.com/)
...
#### GETENV
Man pages: [Man Pages](https://pages.github.com/)
#### SET
Man pages: [Man Pages](https://pages.github.com/)
#### UNSET
Man pages: [Man Pages](https://pages.github.com/)



> ## contact 💬

  

### | [Twitter](https://twitter.com/llanoJS) | [Linkedin](https://www.linkedin.com/in/juansllano/) | [Mail](1461@holbertonschool.com) | [Github](https://github.com/EckoJuan/) |
