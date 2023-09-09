#include <string>
#include <cstdlib>  // C-style string library

int main()
{
	// atoi: convert C-style string to integer
	const char* str = "123";
	int value = atoi(str);

	// atof: convert C-style string to double
	const char* piStr = "3.14";
	double piValue = atof(piStr);

	// create C++ string
	std::string str1 = "Hello";
	std::string str2(str1);
	std::string str3 = "World";
	
	// append and concatenate
	std::string message = "Hello, ";
	message.append("Guan.");
	message += "How are you?";

	// string length
	int len1 = message.size();
	int len2 = message.length();

	// finding and searching
	int firstIndex = message.find("Guan");  // find the first occurrence of substring
	int lastIndex = message.rfind("He");  // find the last occurrence of substring
	int firstCharIndex = message.find_first_of("aeiou");  // find the first occurence of any chars in "aeiou"

	// replacing
	// replace(start_pos, length, new_substring)
	message.replace(0, 4, "Hi,Hi");  // replace the substring starting at 0 with a length of 4 with "Hi,Hi"

	// erasing
	// erase(start_pos, length)
	message.erase(0, 4);  // erase substring starting at 0 with a length of 4; size changes

	// string comparison
	std::string strG = "Guan";
	std::string strZ = "Zhang";
	int comparison = strG.compare(strZ);

	// Conversion to other types
	// stoi: convert to integer
	// stol: convert to long
	// stof: convert to float
	// stod: convert to double
	// to_string: convert various types to string
	std::string numStr = "100";
	int numInt = stoi(numStr);
}
