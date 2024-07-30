#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
    {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeToSign)
    {
        throw GradeTooLowException();
    }
    isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << "Form " << f.getName() << " (Sign grade: " << f.getGradeToSign()
        << ", Execute grade: " << f.getGradeToExecute() << ", Signed: "
        << (f.getIsSigned() ? "Yes" : "No") << ")";
    return out;
}
