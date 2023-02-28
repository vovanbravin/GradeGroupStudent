#include "Student.h"

void PlusItem(Group &group);
void PlusStudent(Group&group);
void ShowGradeStudent(Group& group);


int main()
{
	setlocale(LC_ALL, "RUS");

	Group group;
	
	PlusItem(group);
	
	PlusStudent(group);

	ShowGradeStudent(group);



	return 0;
}

bool �heckTwoName(Group& group, Item a)
{
	for (size_t i = 0; i < group.GetItems().size(); i++)
	{
		if (a.GetName() == group.GetItems().at(i).GetName())
		{
			std::cout << "�� ����� ���� ���� ���������� ���������!\n";
			return true;
		}
	}
	return false;
}

void PlusItem(Group &group) 
{
	uint32_t col;
	std::cout << "������� ��������� � ������: ";
	std::cin >> col;

	std::cin.get();
	for (size_t i = 0; i < col; i++)
	{
		Item a;
		std::string name;
		do {
			std::cout << "������� �������� ��������: ";
			getline(std::cin, name);
			a.SetName(name);
		} while (�heckTwoName(group, a));
		group.SetItems(a);
	}

}

void PlusStudent(Group &group)
{
	int out;
	do {
		Student a;
		std::string name;
		std::cout << "������� ��� ��������: ";
		getline(std::cin, name);
		a.SetName(name);

		std::vector<uint32_t>grade;
		for (size_t i = 0; i < group.GetItems().size(); i++)
		{
			uint32_t count;
			std::cout << "������� � ���� ������ �� " << group.GetItems().at(i).GetName() << ": ";
			std::cin >> count;
			std::cout << "������� ������ �� �������� " << group.GetItems().at(i).GetName() << " : ";
			for (size_t i = 0; i < count; i++)
			{
				int gra;
				std::cout << "������� ������: ";
				std::cin >> gra;
				grade.push_back(gra);
			}
			a.SetGrade({ group.GetItems().at(i).GetName(),grade });
		}
		group.SetStudents(a);
		std::cout << "�������� ��� �������� - 1,��� - 0:  ";
		std::cin >> out;
		std::cin.get();
	} while (out);

}

void ShowGradeStudent(Group& group)
{
	for (size_t i = 0; i < group.GetItems().size(); i++)
	{
		std::cout << "������ �� �������� " << group.GetItems().at(i).GetName() << ": \n";
		for (size_t j = 0; j < group.GetStudents().size(); j++)
		{
			std::cout << "������� " << group.GetStudents().at(j).GetName() << ": ";
			for (size_t x = 0; x < group.GetStudents().at(j).GetGrade().size(); x++)
			{
				if (group.GetStudents().at(j).GetGrade().at(x).first == group.GetItems().at(i).GetName())
				{
					for (size_t c = 0; c < group.GetStudents().at(i).GetGrade().at(x).second.size(); c++)
					{
						std::cout << group.GetStudents().at(i).GetGrade().at(x).second.at(c) << " ";
					}
					break;
				}
				break;
			}
		}
	}
}