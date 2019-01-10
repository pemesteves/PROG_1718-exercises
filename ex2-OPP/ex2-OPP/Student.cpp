#include "Student.h"
#include <string>

using namespace std;

Student::Student()
{
}
void Student::setGrades(double shortExam, double project, double exam)
{
	this->shortExam = shortExam;
	this->project = project;
	this->exam = exam;
	this->finalGrade = (double)weightShortExam*exam / 100 + (double)weightProject*project / 100 + (double)weightExam*exam / 100;
}

