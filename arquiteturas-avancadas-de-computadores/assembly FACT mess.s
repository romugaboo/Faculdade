addi x5, x0, 2     # Atribuindo valor de x5 para 2
addi x6, x0, 4     # MUDE O N DO FATORIAL AQUI
addi x7, x0, 2     # Utilizando x7 como contador de somas sucessivas
addi x9, x0, 1     # Atribuindo valor 1 para x9
sub x8, x6, x9     # Atribuindo valor n - 1 para x8
jal x1, FACT
jal x0, END

FACT:
    bne x8, x9, ELSE5   
    beq x0, x0, EXIT5
ELSE5:    
    beq x6, x9, ELSE     # Fatorial de 1 é 1
    beq x0, x0, EXIT
ELSE: 
    addi x10, x0, 1
    jal x0, END
EXIT:
    beq x6, x0, ELSE2    # Fatorial de 0 é 1
    beq x0, x0, EXIT2
ELSE2: 
    addi x10, x0, 1      
    jal x0, END
EXIT2:
MUL:
    beq x7, x5, ELSE4
    beq x0, x0, EXIT4
ELSE4:
    add x10, x6, x6
EXIT4:
    bne x8, x7, ELSE3
    sub x6, x6, x6
    add x6, x10, x0
    sub x7, x7, x7
    addi x7, x0, 2
    sub x8, x8, x9
    jal x1, FACT
    beq x0, x0, EXIT3
ELSE3:
    add x10, x10, x6
    addi x7, x7, 1
    jal x1, MUL
EXIT3:
EXIT5:
    beq x6, x5, ELSE6
    jal x0, END
ELSE6:
    add x10, x7, x0
END:
