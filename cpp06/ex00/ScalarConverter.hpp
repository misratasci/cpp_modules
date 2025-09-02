#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &src);
  ScalarConverter &operator=(const ScalarConverter &src);
  ~ScalarConverter();

  enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID };

  static Type detectType(const std::string &literal);
  static void convertFromChar(const std::string &literal);
  static void convertFromInt(const std::string &literal);
  static void convertFromFloat(const std::string &literal);
  static void convertFromDouble(const std::string &literal);
  static void printChar(double value);
  static void printInt(double value);
  static void printFloat(double value);
  static void printDouble(double value);

public:
  static void convert(const std::string &literal);
};