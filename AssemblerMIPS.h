/** @file AssemblerMIPS.cpp
 * A class to assemble MIPS code
 *
 * @author  Josh Lee
 * @date 3/25/2015
 **********************************************************/

#pragma once
#include <iomanip>
#include <string>
#include <cstddef>
#include <sstream>
#include <vector>

#define START_ADDR 0x00400000-4

using namespace std;

/** An enum to represent instruction types */
enum instructType
{
	rType,
	iType,
	jType,
};

/** A union to represent a MIPS command */
union command
{
	/** struct for rTypes */
	struct 
	{
		unsigned func : 6;
		unsigned shamt : 5;
		unsigned rd : 5;
		unsigned rt : 5;
		unsigned rs : 5;
		unsigned opcode : 6;
	} rType;

	/** struct for iTypes */
	struct
	{
		unsigned imm : 16;
		unsigned rt : 5;
		unsigned rs : 5;
		unsigned opcode : 6;
	}iType;

	/** struct for jTypes */
	struct
	{
		unsigned address : 26;
		unsigned opcode : 6;
	}jType;

	/** int represention of the command */
	unsigned int cmd;
};

/** A struct to represnt symbols such as regs and lables */
struct Symbol
{
	string symbolName;
	int value;
};

/** A struct to hold the command and address of that command */
struct AsmCommand
{
	command cmd;
	int addr;
};

/** A struct to represnt MIPS instructions */
struct Instruction
{
	string instruction;
	int opcode;
	int func;
	instructType type;
};

/** @class AssemblerMIPS
 * A class that assembles MIPS code into macheine code
 */
class AssemblerMIPS
{
private:
	/** The MIPS code to assemble */
	string mipsCode;
	/** The regs that can be used with their corrisponding number */
	static const Symbol REG_LIST[];
	/** A list of all implemented MIPS instructions with their relevant info */
	static const Instruction INSTR_LIST[];

public:
	/** A constructor that takes a string of MIPS code for assembling
	 * @param fileContent The code contained in the MIPS source file
	 * @post mipsCode is intialized and assigned fileContent
	 */
	AssemblerMIPS(string fileContent);
	/** Destructor */
	~AssemblerMIPS(void);
	/** A function that will assemble MIPS code into machine code
	 * @return A string containing the assembled code 
	 */
	string assembleCode();
	/** A function that will assemble MIPS code into machine code
	 * @param fileContent The code contained in the MIPS source file
	 * @return A string containing the assembled code 
	 */
	string assembleCode(string fileContent);
private:
	/** A function to remove comments from the code
	 * @param code The MIPS code
	 * @return MIPS code with no comments
	 */
	string removeComments(string code);
	/** NOT IMPLEMENTED */
	string alignLables(string code);
	/** A function to build my symbol table
	 * @param code The MIPS code
	 * @return A list of symbols and their values found in the code
	 */
	vector<Symbol> buildSymbolTable(string code);
	/** A function to remove the lables from the code
	 * @param code The MIPS code
	 * @param table The symbol table that was built
	 * @return the code without labels
	 */
	string removeLables(string code, vector<Symbol> table);
	/** A function to remove the lables from the code
	 * @param code The MIPS code
	 * @param table The symbol table that was built
	 * @return assemble A list of the assmbled commands
	 */
	vector<AsmCommand> assemble(string code, vector<Symbol> table);
	/** A function that takes a instruction and creats a machine code
	 * @param inst The MIPS instruction
	 * @param args The arguments for the instruction
	 * @param table The symbol table that was built
	 * @param addr The address of the instruction
	 * @return the machine code command
	 */
	command createMcode(Instruction inst, string args, vector<Symbol> table, int addr);
	/** A function that will get the number assigned to a regester
	 * @param reg The reg to check
	 * @return The decmial represntaion of the reg
	 */
	unsigned int getRegNumber(string reg);
	/** A function to get the mem adress a label repesents
	 * @param label The label to check
	 * @param table The symbol table that was built
	 * @return the memory address the label represents
	 */
	unsigned int getLables(string label, vector<Symbol> table);
};
