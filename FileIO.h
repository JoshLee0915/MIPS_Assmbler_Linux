/** @file AssemblerMIPS.cpp
 * A class to handle file IO
 *
 * @author  Josh Lee
 * @date 3/22/2015
 **********************************************************/

#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/** @class FileIO
 * A class the handles general file IO from a 
 * text file.
 */
class FileIO
{
private:
	/** The last ocurred error */
	string lastError;
	/** The file input stream */
	ifstream fInStream;
public:
	/** Default constructor */
	FileIO();
	/** Default constructor
	 * @post fInStream is closed
	 */
	~FileIO();
	/** A function that gets the last error possible
	 * @return The last error
	 */
	string getLastError() const;
	/** A function to open a file stream
	 * @return True on sucess
	 */
	bool openFile(string file);
	/** A function to close the file stream
	 * @return True on sucess
	 */
	bool closeFile();
	/** A function to load from a text file
	 * @return The contents of the text file
	 */
	string loadTxtFile();
	/** A function to load from a text file
	 * @param file The location of the file to load
	 * @return The contents of the text file
	 */
	string loadTxtFile(string file);
	/** A function to write to a text file
	 * @param fileName The name of the new file when saved
	 * @param text The text to save to the file
	 * @return True on sucess
	 */
	bool writeTextFile(string fileName, string text);
};
