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
			std::cout << "\t\tМеню:\n"
				<< "\tПоказать оценки группы - 1\n"
				<< "\tСреднии оценки студентов - 2\n"
				<< "\tСредние оценки по предметам - 3\n"
				<< "\tСредний балл группы - 4\n"
				<< "\tМаксимальная и минимальная  - 5\n";

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

		std::cout << "Если хотите продожить - 1,выйти - 0: ";
		std::cin >> out;
	} while (out);

	return 0;
}
