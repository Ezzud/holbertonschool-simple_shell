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
Open interactive mode:
```
./hsh
```

Execute script in non-interactive mode:
```
cat script.sh | ./hsh
```



### Examples
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
<details>
<summary>Valentin was in charge of process execution, PATH integration and "interactive/non-interactive" handling</summary>
- <a href="https://github.com/Ezzud/holbertonschool-simple_shell/tree/args-handling" target="_blank">branch: args-handling</a><br>
- <a href="https://github.com/Ezzud/holbertonschool-simple_shell/tree/exec-process" target="_blank">branch: exec-process</a>
</details>
<details>
<summary>Houcine was in charge of built-in functions, README.md, MAN page, Flowchart and AUTHORS file.</summary>
- <a href="https://github.com/Ezzud/holbertonschool-simple_shell/tree/README-update" target="_blank">branch: README-update</a><br>
- <a href="https://github.com/Ezzud/holbertonschool-simple_shell/tree/builtin-functions" target="_blank">branch: builtin-functions</a>
</details>
<details>
<summary>Us two were in charge of checking the code and approving update & merge.</summary>
- <a href="https://github.com/Ezzud/holbertonschool-simple_shell/pulls" target="_blank">pull requests</a><br>
  - <a href="https://github.com/Ezzud/holbertonschool-simple_shell/commits/master" target="_blank">commits</a><br>
</details>


<p align="center">
  <img src="https://raw.githubusercontent.com/Ezzud/holbertonschool-simple_shell/master/assets/kanban.png">
</p>
Screenshot of our Kanban board

## Flowchart
