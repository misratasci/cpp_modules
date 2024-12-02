
#include <iostream>
#include <fstream>

int main(int ac, char *av[]) {

	if (ac != 4) {
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}

	std::string infile = av[1];
	std::ifstream input_stream;
	input_stream.open(infile, std::fstream::in);
	if (input_stream.fail()) {
		std::cout << "Could not open " << infile << std::endl;
		return (1);
	}
	std::ofstream output_stream;
	std::string outfile = infile + ".replace";
	output_stream.open(outfile , std::fstream::out);
	if (output_stream.fail()) {
		std::cout << "Could not open " << outfile << std::endl;
		return (1);
	}

	std::string a = av[2];
	std::string b = av[3];
	int a_len = a.length();
	std::string line;
	
	while (!std::getline(input_stream, line).fail()) {
		unsigned int a_ind = line.find(a);
		while (a_ind < line.length()) {
			line.erase(a_ind, a_len);
			line.insert(a_ind, b);
			a_ind = line.find(a, a_ind + b.length());
		}
		output_stream << line << std::endl;
	}

	input_stream.close();
	output_stream.close();
}