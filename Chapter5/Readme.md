Ques1 

Output
```
------Parent Process------
Value of x in parent process 100
New Value of x in parent process 300
------Child Process------
Value of x in child process 100
New Value of x in child process 200

```
* The value is the same variable in the child and parent process until changed.

* They both change the value in their own process.

Ques2 

Output
```
-------Parent Process-----
File discriptor in parent process: 3
File contents
First Line.
Parent Line.

-------Child Process------
File discriptor in child process: 3
File contents
First Line.
Child Line.

```
* Both parent and child can access the file descriptor.

* One overwrites another while writing contents to file.
