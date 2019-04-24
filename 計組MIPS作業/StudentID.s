.text
    .globl  main

# INPUT
main:
        li 	$v0, 4
        la 	$a0, input
        syscall
        
        li 	$v0, 5
        syscall
        move 	$s0, $v0        # $s0 = input

# CHECK IF INPUT > 1 (TODO: fill this procedure as an exercise)
L1:

# FOR LOOP INPUT > 1 (TODO: fill this procedure as an exercise)
L2:

#PRINT OUTPUT (FALSE)
L3:
        li      $v0, 4
        la      $a0, false
        syscall

        j Exit

#PRINT OUTPUT (TRUE)
L4:
        li      $v0, 4
        la      $a0, true
        syscall

        j Exit

#EXIT
Exit:
        li      $v0, 10
        syscall	

        .data
input:	.asciiz "Input: "
true: 	.asciiz "True"
false:  .asciiz "False"