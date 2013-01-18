/*
#-------------------------------------------------------------------------------
# Author: Adnan Fanaswala
# Created: 18th January 2013
# The code helps convert a decimal number into a binary number 
# (stores the bits to an array) as well as converts the binary number
# back to decimal for verification
#-------------------------------------------------------------------------------
*/

//=============================================================================
// Includes
//=============================================================================
#include <stdio.h>
#include <memory.h>
#include <cmath>
#include <Windows.h>
#include <iostream>
#include <array>
#include <cmath>

//Creates a binary array when passed a decimal value
void toBinary(long long decimal, int binary_number_array[], int & NumBinaryBits)
{
   long long decimalToConvert = decimal;
   //Keeps track of the # of binary bits in the converted binary number
   NumBinaryBits = 0; 

   do
   {
	   //Keep the remainder after diving by 2 (always either 0 or 1)
       binary_number_array[NumBinaryBits++] = decimalToConvert % 2; 
	   //Divide the number by 2
       decimalToConvert /= 2;
   } 
   
   //Only enter this part when decimalToConvert = 1 (cannot divide by 2 anymore)
   //Else keep executing previous do loop
   while (decimalToConvert);
   //This gets the binary number the right way around (1000 instead of 0001)
   for (int i = 0; i <= NumBinaryBits / 2; ++i) std::swap(binary_number_array[i], binary_number_array[NumBinaryBits - i - 1]);
}

//Converts a binary array into decimal
double toDecimal(int binary_number_array[], int size)
{
	 int decimalValue=0;
	 int binarySize = size;

	 for(int i=0; i<size; i++) {
		 //Keep multiplying 2^(Bit position) + previous value
		 decimalValue = (binary_number_array[i] * pow(static_cast<double>(2),--binarySize)) + decimalValue;
	 }

	 return decimalValue;
} 

int 
main( int argc, char* argv[] )
{
  
	//Value to convert to binary
	long long decimalNumberToConvert = 1234;
         	
	  //binaryNumberArray to hold the binary number
	  //sizeBinaryNumber represents the number of bits of the converted decimal number
	  int sizeBinaryNumber, binaryNumberArray[100];
	  toBinary(decimalNumberToConvert, binaryNumberArray, sizeBinaryNumber);
	  
	  //Printing out the binary number
	  std::cout << " The binary equivalent of " << decimalNumberToConvert << " : ";
	  for (int i = 0; i < sizeBinaryNumber; ++i) std::cout << binaryNumberArray[i];
	  std::cout << std::endl;

	  //Check if the conversion was done correctly (convert back to decimal)
	  double decimalValueBack = 0;
	  decimalValueBack = toDecimal(binaryNumberArray,sizeBinaryNumber);

	  std::cout << "[Verification] Binary Number converted back to decimal : " << decimalValueBack  << std::endl;
	  std::cout << std::endl;

   system("PAUSE");
   return 0;
}