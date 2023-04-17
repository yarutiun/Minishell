<p align="center">
  <img src = "https://user-images.githubusercontent.com/91738456/215802454-136c717c-c15a-4b3a-98db-44d4852b5ca8.png" />
</p>

# Minishell (As beautiful as shell ☺️)

Minishell is a 42 school project. 

The main goal of this project is to simulate bash shell.

## Usage

```bash
Make
./minishell
```

## But what is implemented?
Minishell can be used to run bash commands (with or without pipe ```|```)

It can handle redirections such as ```<```  ```>```  ```<<```  ```>>```

Some commands are implemented by us: ```cd, pwd, echo (with -n flag), env, export, unset```

It can also handle ctrl+c and ctrl+d keyboard input to interrupt and exit processes

It also has expansion feature such as echo ```$USER``` that will print ```/yarutiun``` or anything that can be expanded from env

It can expand echo ```$?``` and print the last exit code.

You can navigate through your last input using arrows Up and Down

## Contributors
Danil Sas:
https://github.com/Daneality

Ilya Bellash:
https://github.com/shokunin48
