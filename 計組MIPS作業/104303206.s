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
        addi  $t0, $zero, 1      # $t0=1
        slt 	$t0, $t0, $s0      # $t0=1 if 1<input
        beq   $t0, $zero, L5     # if $t0==$zero (1>=input) ,return input error
        bne   $t0, $zero, L2     # if $t0!=$zero (1<input) ,L2



# FOR LOOP INPUT > 1 (TODO: fill this procedure as an exercise)
L2:
        # int tmp=2;
        # while(tmp<n)
        #   if (n%tmp==0) return False;
        #   tmp++;
        # return True;

        addi  $t0, $zero, 2       # $t0=2  (int tmp=2)
        j     LOOP                # go to LOOP
LOOP:
        slt   $t1, $t0,   $s0     # $t1=1 if tmp<input
        beq   $t1, $zero, L4      # if $t1==$zero (tmp>=input) ,return True

        div   $s0, $t0
        mfhi  $t2                 # $t2=(input%tmp)

        slt   $t3, $zero, $t2     # $t3=1 if 0<(input%tmp)
        beq   $t3, $zero, L3      # if $t3==$zero (0>=(input%tmp)) ,return False

        addi  $t0, $t0, 1         # tmp++
        j     LOOP                # go to LOOP


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

#PRINT INPUT ERROR
L5:
        li      $v0, 4
        la      $a0, err
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
err:    .asciiz "Please input a num >1 !!!"
