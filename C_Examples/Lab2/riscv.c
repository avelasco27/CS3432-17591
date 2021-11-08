//this is the riscv.c code
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // malloc & free
#include <stdint.h> // use guaranteed 64-bit integers
#include "tokenizer.h" // Create header file and reference that
#include "memory.h" // built-in functions to read and write to a specific file

int32_t* reg; // Array of 32 32-bit registers

void init_regs();
bool interpret(char* instr);
void write_read_demo();

/**
 * Initialize register array for usage.
 * Malloc space for each 32-bit register then initializes each register to 0.
 * Do not alter this function!
 */
void init_regs(){
	int reg_amount = 32;
	reg = malloc(reg_amount * sizeof(int32_t)); // 32 * 4 bytes
	for(int i = 0; i < 32; i++)
		reg[i] = i;
}



/**
 * Fill out this function and use it to read interpret user input to execute RV64 instructions.
 * You may expect that a single, properly formatted RISC-V instruction string will be passed
 * as a parameter to this function.
 */
bool interpret(char* instr){
  char **user_input = (char **)malloc(sizeof(char *) * (1));
  user_input = tokenize(instr, " ");//tokenize user input delim of spaces
  char lw[] = "LW", sw[] = "SW", add[] = "ADD", addi[] = "ADDI";
}
if (str_compare(user_input[0], add) == 1) {
    char **var = (char**)malloc(sizeof(char*) * (1));
    //var will be updating to each token
    //tokenize element 2 from instruction
    var = tokenize(user_input[2], "X");//saving what is after X into variable
    int register1 = atoi(var[0]);
	
    //tokenize element 3 from instruction
    var = tokenize(user_input[3], "X");
    int register2 = atoi(var[0]);
	
    //tokenize element 1 (register to save added values)
    var = tokenize(user_input[1], "X");
    int save_to_Reg = atoi(var[0]);//destination reg.
    int add = (long long int)reg[reg1] + (long long int)reg[reg2];/*adding
instructions[2] and [3]*/
    reg[save_to_Reg] = add;//updating what is in register
  }
  else if (str_compare(user_input[0], addi) == 1) {
    char **var = (char**)malloc(sizeof(char*) * (1));
    //Tokenize register 1 and add with constant
    var = tokenize(user_input[2], "X");
    int reg1 = atoi(var[0]);
    int constant = atoi(user_input[3]);//turning last part of the token from string to int, which what atoi does.
    int add = (long long int)reg[reg1] + constant;//adding
    //Save in destination register
    var = tokenize(user_input[1], "X");
    int save_to_Reg = atoi(var[0]);
    reg[save_to_Reg] = add;
  }
  else if (str_compare(user_input[0], sw) == 1) {
	  char* mem_file = "mem.txt";
	  char **var = (char**)malloc(sizeof(char*(char*) * (1));
	
	//offset tokenize
	  var = tokenize(user_input[2], "(");
	  int offset = atoi(var[0]);
	  var = tokenize(var[1], ")");
	
	//tokenize register
	  var = tokenize(var[0], "X");
	  int regi = atoi(var[0]);
	  int32_t memory_addy = regi + offset;
				      
	//tokenize memory address to save
	  var = tokenize(user_input[1], "X");
	  int saveW = atoi(var[0]);
				    
	//Saving word to memory
	int32_t write = write_address(reg[saveW], memory_addy, mem_file);
	if(write == (int32_t NULL)
	   printf("ERROR: unsucessful write to address %0X\n", 0x40);
	//printf(" Entered Stores Method :)");
    /*Here would have gone code for Store instruction*/
  }
  else if (str_compare(user_input[0], "LW") == 1) {
	  char* mem_file = "mem_file";
	  char** var = (char**)malloc(sizedof(char*) * (4));
	  
	  //tokenize destination register
	  var = tokenize(user_input[1], "X");
	  int save_to_Reg = atoi(var[0]);
	  
	  //tokenize memory address to load
	  var = tokenize(user_input[2], "(");
	  int offset = atoi(var[0]);
	  var = tokenize(var[1], ")");
	  var = tokenize(var[0], "X");
	  int regi = atoi(var[0]);
	  int32_t address = offset + regi;
	  
	  //loading word from memory
	  int32_t read_value = read_address(address, "mem.txt");
	  reg[save_to_Reg] = (long long int)read_value;
	//printf(" Entered Load Method :)");
    /*Here would have gone code for load instruction*/
 // }
  //else {
    return false;//Return false if user input is not vaild
  }
  //return true;//Return true when user input is vaild
//}
/*checking user instruction to above parameter set
  to make sure instruction is a match
  by checking it length*/
int str_compare(char *inStr, char*inStr2){
  int counter = 0; 
  int counter2 = 0;
/*trasvering through instruction string 1, and 
  incrementing counter then returning total counter*/
  for (int i = 0; *(inStr + i) != '\0'; i++){
    counter++;
  }
/*trasvering through parameter 2, and incrementing counter
  then returning total counter2 */
  for (int i =0; *(inStr2 + i) != '\0'; i++) {
    counter2++;
  }
/*condition checking for comparsion, if theyre
  the same or not in length*/
  if (counter == counter2) {
    for (int i = 0; i < counter; i++) {
      if (*(inStr+i) != *(inStr2+i)) {
	return 0;
      }
    }
  }
  else {
    return 0;
  }
  return 1;
}


/**
 * Simple demo program to show the usage of read_address() and write_address() found in memory.c
 * Before and after running this program, look at mem.txt to see how the values change.
 * Feel free to change "data_to_write" and "address" variables to see how these affect mem.txt
 * Use 0x before an int in C to hardcode it as text, but you may enter base 10 as you see fit.
 */
void write_read_demo(){
	int32_t data_to_write = 0xFFF; // equal to 4095
	int32_t address = 0x98; // equal to 152
	char* mem_file = "mem.txt";

	// Write 4095 (or "0000000 00000FFF") in the 20th address (address 152 == 0x98)
	int32_t write = write_address(data_to_write, address, mem_file);
	if(write == (int32_t) NULL)
		printf("ERROR: Unsucessful write to address %0X\n", 0x40);
	int32_t read = read_address(address, mem_file);

	printf("Read address %lu (0x%lX): %lu (0x%lX)\n", address, address, read, read); // %lu -> format as an long-unsigned
}

void print_regs(){
  int col_size = 10;
  for(int i = 0; i < 8; i++){
    printf(" X%02i:%.*lld", i, col_size, (long long int) reg[i]);
    printf(" X%02i:%.*lld", i+8, col_size, (long long int) reg[i+8]);
    printf(" X%02i:%.*lld", i+16, col_size, (long long int) reg[i+16]);
    printf(" X%02i:%.*lld\n", i+24, col_size, (long long int) reg[i+24]);
  }
}
/**
 * Your code goes in the main
 *
 */
int main(){
	// Do not write any code between init_regs
	init_regs(); // DO NOT REMOVE THIS LINE

	// Below is a sample program to a write-read. Overwrite this with your own code.
	write_read_demo();
	print_regs();
	printf(" RV32 Interpreter.\nType RV32 instructions. Use upper-case letters and space as a delimiter.\nEnter 'EOF' character to end program\n");



	char* instruction = malloc(1000 * sizeof(char));
	bool is_null = false;
	// fgets() returns null if EOF is reached.
	is_null = fgets(instruction, 1000, stdin) == NULL;
	while(!is_null){
	  interpret(instruction);
	  printf("\n");
	  print_regs();
	  printf("\n");
	  is_null = fgets(instruction, 1000, stdin) == NULL;
	}
	printf("Good bye!\n");

	return 0;
}
