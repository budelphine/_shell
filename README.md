# _shell
*My own little shell like bash or zsh*

**Task**   
*This is a group project where I developed a parser and implemented the story of the commands.*

- Command history
- Work with $PATH and env
- Implement some builtins:
  - echo with option -n
  - cd with only a relative or absolute path
  - pwd with no options
  - export with no options
  - unset with no options
  - env with no options
  - exit with no options
- ’ inhibit all interpretation of a sequence of characters
- " inhibit all interpretation of a sequence of characters except for $.
- Redirections (<, >, >>)
- Pipes
- $?
- ctrl-C ctrl-D ctrl-\

**How to use**   
Do ```make``` and welcome to our shell:

**Result**
- [x] - Executor work via execve and fork's
- [x] - Command history via termcap
- [x] - Redirections work like in bash
- [x] - Pipe's work like in bash
- [x] - Signal's (ctrl+d, ctrl+c) work like in bash
- [x] - No leak's

