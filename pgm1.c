

#include <stdio.h>

int main()
{
	int sum = 0, i, n;  //set variables

	printf("Enter number integers to be sum\n");
	scanf("%d", &n); // scan for "n"

	for (i = 1; i <= n; i++)  //increment "i" until it equals "n"
	{
		sum += i;  // add up the sum
	};

	printf("Sum:%d\n", sum);  //print sum
	return 0;
};

/*

LEGv8 code for adding up the natural numbers to user defined n


 X19 n ->
 X20 sum ->
 X21 i ->


	ADDI X19,X19, #0  //set n to 0 in X19
	ADDI X20,X20, #0  //set sum to 0 in X20
	ADDI X21,X21, #0  //set i to 0 in X21

//here is where you scan in "n"

Loop: 	
	ADD  X20,X20,X21  //sum = sum + i
	SUBS X9,X19,X21   //compare n and i
	B.EQ Exit         //if i = n exit


	ADDI X21,X21,#1   //increment i
	B    Loop         //loop

	//print the sum
Exit: ...

*/



// X19 n ->
// X20 sum ->
// X21 i ->

	 ADD X20, X20, XZR  //Sum = 0
	 ADDI X21, X21, #1    //i = 1

loop: 
	 SUB X9, X19, X10  //X9_temp = n - X10_temp
     CBZ X9, Exit
	 ADD X20,X20, X10
	 ADD X10,X10, #1
	 B Loop
   DDDWADWDSDWDADdWDA2E23Q423Q2DQ32EQDAWEQ5DWD
Exit: ....

*/