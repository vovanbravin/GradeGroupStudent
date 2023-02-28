#include "Student.h"
#include "function.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	Group group;
	
	PlusItem(group);
	
	PlusStudent(group);

	int out;
	do {
		system("cls");
		int action;
		do {
			std::cout << "\t\t����:\n"
				<< "\t�������� ������ ������ - 1\n"
				<< "\t������� ������ ��������� - 2\n"
				<< "\t������� ������ �� ��������� - 3\n"
				<< "\t������� ���� ������ - 4\n"
				<< "\t������������ � �����������  - 5\n";

			std::cin >> action;
		} while (action < 1 || action>5);

		enum action { Show = 1, AverageS, AverageItems, AverageGroup ,MinMax};

		switch (action)
		{
		case Show:
			ShowGradeStudent(group);
			break;
		case AverageS:
			AverageGrades(group);
			break;
		case AverageItems:
			AverageCradeItems(group);
			break;
		case AverageGroup:
			AverageGradeGroup(group);
			break;
		case MinMax:
			MaxMinItems(group);
			break;
		}

		std::cout << "���� ������ ��������� - 1,����� - 0: ";
		std::cin >> out;
	} while (out);

	return 0;
}
