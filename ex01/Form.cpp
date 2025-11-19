#include "Form.hpp"

Form::Form(const std::string& name, int minGrade, int minExecute)
		 : m_name(name),
		   m_signatureStatus(false),
		   m_minGrade(minGrade),
		   m_minExecute(minExecute){}

Form::Form(const Form& other) 
	: m_name(other.m_name),
	  m_signatureStatus(other.m_signatureStatus),
	  m_minGrade(other.m_minGrade),
	  m_minExecute(other.m_minExecute) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
		this->m_signatureStatus = other.m_signatureStatus;
    }
    return *this;
}

Form::~Form() {
    
}


const std::string Form::getName(void) const {
	return m_name;
}

bool Form::getSignatureStatus(void) const {
	return m_signatureStatus;
}

int Form::getMinGrade(void) const {
	return m_minGrade;
}

int Form::getMinExecute(void) const {
	return m_minExecute;
}
