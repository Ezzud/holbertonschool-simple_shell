<p align="center">
  <img width="500" height="300" src="https://camo.githubusercontent.com/f2324c1fa6438fbe14cc85a7a11948518e4a73cd1792abf27ae44dc7f6c24b5e/68747470733a2f2f692e6962622e636f2f4b3943367167582f53696d706c652d5368656c6c2e706e67">
</p>
<p align="center">
Hello👋🏻
</p>



## Task and Team
This project was released by Valentin and Houcine in Holbertonschool Bordeaux.
For this project called "Simple Shell" we had two weeks to complete it. The tasks were divided equally between myself and Valentin.
Objective is to create a `hsh` command, allowing us to execute script in different ways

### Usage
1. Interactive mode
```
$ ./hsh
($) ls
file1 file2 file3
($) unknown_command
./hsh: 1: No such file or directory
($) exit
$ 
```

2. Non-interactive mode
```
$ echo "ls" | ./hsh
file1 file2 file3
$
```


## Distribution of tasks
Valentin was in charge of process execution, PATH integration and "interactive/non-interactive" handling
Houcine was in charge of built-in functions, README.md, MAN page and AUTHORS file.
Us two were in charge of checking the code and approving update & merge.


<p align="center">
  <img src="https://raw.githubusercontent.com/Ezzud/holbertonschool-simple_shell/README-update/assets/kanban.png">
</p>
*Screenshot of our Kanban board*

## Flowchart
