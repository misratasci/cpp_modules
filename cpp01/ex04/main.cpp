

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

	
}