# PIPEX
shell에 있는 pipe(|) 기능을 간단하게 구현한 프로그램
## 구현한 pipe (|) 기능과 사용법
### **mandatory 기능**
**input을 file1로 받고 cmd1, cmd2를 pipe로 연결해 output를 file2에 저장**
> **pipe (|)**
>```
>< file1 cmd1 | cmd2 > file2
>```
> **pipex program**
>```
>./pipex file1 cmd1 cmd2 file2
>```


### **bonus 기능**
**cmd를 여러개 받을 수 있는 기능 추가**
>
> **pipe (|)**
> ```
>< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
>```
> **pipex program**
>```
>./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
>```
**LIMITER 입력 전까지 표준 입력을 input으로 받는 here_doc 기능 추가**
> **pipe (|)**
>```
>cmd << LIMITER | cmd1 | cmd2 >> file
>```
> **pipex program**
>```
>./pipex here_doc LIMITER cmd1 cmd2 file
>```

## 구현에 필요한 개념
- fork(), dup2(), execve(), pipe(), wait() 등 systemcall을 이용한 프로세스 통신

## 빌드
```
make
```
- madatory 기능을 포함한 pipex 프로그램 생성
```
make bonus
```
- mandatory + bonus 기능을 포함한 pipex 프로그램 생성
```
make clean
```
- make 로 인해 만들어진 .o 파일 삭제
```
make fclean
```
- make clean + pipex 삭제
```
make re
```
- make fclean + make
---
<img width="208" alt="스크린샷 2024-06-25 오후 4 17 01" src="https://github.com/seonjo1/PIPEX/assets/127729846/262d13e5-e780-4bb9-9c32-b424200b152a">
