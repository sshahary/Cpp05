#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Execute method
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream ofs((target + "_shrubbery").c_str());
    if (ofs.fail()) {
        throw std::ofstream::failure("Failed to open file");
    }

    ofs << "       _-_" << std::endl;
    ofs << "    /~~   ~~\\" << std::endl;
    ofs << " /~~         ~~\\" << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  /" << std::endl;
    ofs << "   ~  \\\\ //  ~" << std::endl;
    ofs << "       | |" << std::endl;
    ofs << "       | |" << std::endl;
    ofs << "       | |" << std::endl;
    ofs << "      // \\\\" << std::endl;

    ofs.close();
}
