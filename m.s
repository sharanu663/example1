# test code for all setup is working or not (gdb and qemu)
#_start:
#    j _start


#second code example code add two number unit became value is zero

#_start:
#    addi x1, x0, 2 #addition immendiate register
#    addi x2, x0, 5 #addition immendiate register
#    addi x3, x0, 0 #addition immendiate register

#lable:
#    add x3, x3, x1
#    addi x2, x2, -1
#    bne x2, x0, lable
#j .

# if you want to call c function in assembly file 

_start:
    li sp, 0x80002000
    jal fun
j .
