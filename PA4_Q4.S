	.text
	.global main
	.arch armv8-a+fp+simd
	.type main, %function

main:
	FMOV D1, XZR    // Set D1 to 0.0
	MOV X1,X19		// Move a from X19 to temp register X1
	BL Exp			// branch to exp function
	B exit			// branch to exit

Exp:
	CMP  X1, XZR	// check if a == 0
	B.LT ToExit		// if a is ≤ 0 branch to ToExit
	FMOV D2, #1.0	// set power = 1.0
	FMOV D3, #1.0	// set fact = 1.0
	MOV X10, XZR	// n = 0
	MOV X11, #1		// i = 1
Nr:
	CMP X10, X1		// compares n to a
	B.GE Dr			// go to Dr to calc the fact once n > a
	FMUL D2,D2,D0	// find the numerator
	ADD X10,X10,#1	// n++
	B Nr
Dr:
	CMP X11, X1		// compares i to a
	B.GT Divide		// go to Divide loop once i is > a
	UCVTF D5,X11	// convert i from int to double
	FMUL D3,D3,D5	// find the denominator
	ADD X11,X11,#1	// i++
	B Dr

Divide:
	FDIV D4,D2,D3	// divides product/fact
	FADD D1, D1, D4	// keep update the sum in D1
	SUB  X1, X1,#1	// a-1 before calling functions
	B Exp			// branch back to Exp

ToExit:
	BR X30			// return to caller

Exit: