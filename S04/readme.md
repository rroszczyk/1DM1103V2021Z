```
size a.out
objdump  a.out  -t
objdump -f ./a.out 
objdump -s -j .data a.out
objdump -s -j .text a.out 
objdump -s -j .bss a.out
objdump -S a.out
```
