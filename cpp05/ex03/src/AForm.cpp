#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("default"), _isSigned(false), _gradeToSign(150) , _gradeToExecute(150) {
    std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const AForm& other): _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return (*this);
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Parameterized AForm constructor called" << std::endl;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

const std::string& AForm::getName() const {
    return this->_name;
}

bool AForm::getIsSigned() const {
    return this->_isSigned;
}

int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->_gradeToSign)
        throw GradeTooLowException();
    this->_isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!this->_isSigned)
        throw NotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw GradeTooLowException();
    this->action();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "grade is too low!";
}

const char* AForm::NotSignedException::what() const throw() {
    return "form is not signed!";
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out << "Form Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No") 
        << ", Grade to Sign: " << f.getGradeToSign() << ", Grade to Execute: " << f.getGradeToExecute();
    return out;
}