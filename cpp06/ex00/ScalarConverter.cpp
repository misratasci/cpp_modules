#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
  (void)src;
  return *this;
}
ScalarConverter::~ScalarConverter() {}

ScalarConverter::Type ScalarConverter::detectType(const std::string &literal) {
  if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' &&
      std::isprint(literal[1]))
    return CHAR;
  if (literal == "nan" || literal == "nanf" || literal == "+inf" ||
      literal == "+inff" || literal == "-inf" || literal == "-inff") {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
      return FLOAT;
    else if (literal == "nan" || literal == "+inf" || literal == "-inf")
      return DOUBLE;
  }

  bool hasDecimal = false;
  bool hasF = false;
  unsigned int i = 0;
  if (literal[0] == '+' || literal[0] == '-')
    i = 1;
  for (; i < literal.length(); i++) {
    if (literal[i] == '.') {
      if (hasDecimal)
        return INVALID;
      hasDecimal = true;
    } else if (literal[i] == 'f' && i == literal.length() - 1)
      hasF = true;
    else if (!std::isdigit(literal[i]))
      return INVALID;
  }
  if (hasF)
    return FLOAT;
  else if (hasDecimal)
    return DOUBLE;
  else
    return INT;
}

void ScalarConverter::convert(const std::string &literal) {
  Type type = detectType(literal);

  if (type == CHAR) {
    convertFromChar(literal);
  } else if (type == INT) {
    convertFromInt(literal);
  } else if (type == FLOAT) {
    convertFromFloat(literal);
  } else if (type == DOUBLE) {
    convertFromDouble(literal);
  } else {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
  }
}

void ScalarConverter::convertFromChar(const std::string &literal) {
  char c = literal[1];
  double value = static_cast<double>(c);

  printChar(value);
  printInt(value);
  printFloat(value);
  printDouble(value);
}

void ScalarConverter::convertFromInt(const std::string &literal) {
  std::stringstream ss(literal);
  long long temp;
  ss >> temp;

  if (ss.fail() || temp > std::numeric_limits<int>::max() ||
      temp < std::numeric_limits<int>::min()) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return;
  }

  double value = static_cast<double>(temp);

  printChar(value);
  printInt(value);
  printFloat(value);
  printDouble(value);
}

void ScalarConverter::convertFromFloat(const std::string &literal) {
  if (literal == "nan" || literal == "nanf" || literal == "+inf" ||
      literal == "+inff" || literal == "-inf" || literal == "-inff") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << literal << std::endl;

    std::string doubleVersion = literal;
    if (doubleVersion.back() == 'f')
      doubleVersion.pop_back();
    std::cout << "double: " << doubleVersion << std::endl;
    return;
  }

  std::string floatStr = literal;
  if (floatStr.back() == 'f')
    floatStr.pop_back();

  std::stringstream ss(floatStr);
  float f;
  ss >> f;

  if (ss.fail()) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return;
  }

  double value = static_cast<double>(f);

  printChar(value);
  printInt(value);
  printFloat(value);
  printDouble(value);
}

void ScalarConverter::convertFromDouble(const std::string &literal) {
  if (literal == "nan" || literal == "nanf" || literal == "+inf" ||
      literal == "+inff" || literal == "-inf" || literal == "-inff") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << literal << "f" << std::endl;
    std::cout << "double: " << literal << std::endl;
    return;
  }

  std::stringstream ss(literal);
  double d;
  ss >> d;

  if (ss.fail()) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return;
  }

  printChar(d);
  printInt(d);
  printFloat(d);
  printDouble(d);
}

void ScalarConverter::printChar(double value) {
  if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
    std::cout << "char: impossible" << std::endl;
  else if (value < 32 || value == 127)
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value) {
  if (std::isnan(value) || std::isinf(value) ||
      value > std::numeric_limits<int>::max() ||
      value < std::numeric_limits<int>::min())
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value) {
  float f = static_cast<float>(value);
  std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
            << std::endl;
}

void ScalarConverter::printDouble(double value) {
  std::cout << "double: " << std::fixed << std::setprecision(1) << value
            << std::endl;
}
