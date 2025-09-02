
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
    Bureaucrat low("loww", 151);
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }
  try {
    Bureaucrat high("hehe", -1);
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  try {
    Bureaucrat inc("iii", 2);
    std::cout << inc << std::endl;
    inc.incrementGrade();
    std::cout << inc << std::endl;
    inc.incrementGrade();
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }
  try {
    Bureaucrat dec("ddd", 149);
    std::cout << dec << std::endl;
    dec.decrementGrade();
    std::cout << dec << std::endl;
    dec.decrementGrade();
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  Form f("form1", 50, 25);
  Bureaucrat def;
  Bureaucrat high("high", 20);
  std::cout << f << std::endl;
  def.signForm(f);
  std::cout << f << std::endl;
  high.signForm(f);
  std::cout << f << std::endl;

  return 0;
}