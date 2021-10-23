# Hack Assembler
An assembler for the Hack platform written in C++. 
Translates the given `.asm` file to a `.hack` file.

### Pong
Here's the translated `Pong.hack` file running on a Hack CPU Emulator.
![Pong](https://github.com/Dennis-Johnson/hack_assembler/blob/main/examples/pong.gif)

### A shorter example
`Add.asm` translated to `Add.hack`
```
  // Computes R0 = 2 + 3  (R0 refers to RAM[0])            
  @2                                            // 0000000000000010
  D=A                                           // 1110110000010000
  @3                                            // 0000000000000011
  D=D+A                                         // 1110000010010000
  @0                                            // 0000000000000000
  M=D                                           // 1110001100001000
```

[Language Specification](https://b1391bd6-da3d-477d-8c01-38cdf774495a.filesusr.com/ugd/44046b_7ef1c00a714c46768f08c459a6cab45a.pdf)
