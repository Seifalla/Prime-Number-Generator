# Prime-Number-Generator
# Description:
This program implements an algorithm that generates prime numbers of any length. It consists of the following procedures:

1.	A method to generate random binary numbers with n-digits (Note: for the most significant digit, we have no choice, it will be 1; similarly, for the least significant digit there is no choice, it will have to be 1; for all other position, the method generates either 0 or 1 at random) 


2.	A method to compute modular exponentiation. This method uses the algorithms for modular addition, division and multiplication.
	
3.	A method to test primality. Since the numbers you will be testing are randomly generated, we are going to use the first the single test: 3^(N −1) ≡ 1(mod N).


To check if the algorithm has generated a prime number, we use the brute-force approach of trying all divisors up to the square root of the number.

# Implementation:

All number are stored in vectors.

# Modular Exponentiation Algorithm:
Input: vectors x, y, N
Output: x^y mod N

Initialize z to 1
Loop over the vector y:
	If the current bit is even
		z = z2 mod N
	if it’s odd
		z = x · z2 mod N 
return z









# Square Root Algorithm:
Input: a vector of integers
Output: a vector of integers representing the square root of the input

estimate = input/2
While input != (estimate^2)
estimate = ((estimate + Arg/estimate)/2)

return estimate

# Random Generator Algorithm:
Input: an integer L representing the length of the number
Output: a randomly generated number

Set the first and last bit to 1
Initialize the counter to 0
Create a vector N of length L
While counter is less than the length:
Use the Unix rand() function to generate a random number
If it’s even, set the current bit to 0
If it’s odd, set the current bit to 1
Return N
