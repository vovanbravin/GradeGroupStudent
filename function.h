#pragma once
#include "Student.h";
bool СheckTwoName(Group& group, Item a)
{
	for (size_t i = 0; i < group.GetItems().size(); i++)
	{
		if (a.GetName() == group.GetItems().at(i).GetName())
		{
			std::cout << "Не можнт быть двух одинаковых предметов!\n";
			return true;
		}
	}
	return false;
}

bool  CheckInt(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i]>'9') return true;
	}
	return false;
}

void PlusItem(Group& group)
{
	std::string col;
	do {
		std::cout << "Сколько предметов у группы: ";
		getline(std::cin, col);
	} while (CheckInt(col));


	for (size_t i = 0; i < std::stoi(col); i++)
	{
		Item a;
		std::string name;
		do {
			std::cout << "Введите название предмета: ";
			getline(std::cin, name);
			a.SetName(name);
		} while (СheckTwoName(group, a));
		group.SetItems(a);
	}

}

bool ChackGrade(std::string grade)
{
	for (size_t i = 0; i < grade.length(); i++)
	{
		if (grade[i] < '1' || grade[i]>'5') return true;
	}
	return false;
}

void PlusStudent(Group& group)
{
	int out;
	do {
		Student a;
		std::string name;
		std::cout << "Введите имя студента: ";
		getline(std::cin, name);
		a.SetName(name);

		std::vector<uint32_t>grade;
		for (size_t i = 0; i < group.GetItems().size(); i++)
		{
			std::string count;
			do {
				std::cout << "Сколько у него оценок по " << group.GetItems().at(i).GetName() << ": ";
				getline(std::cin, count);
			} while (CheckInt(count));
			std::cout << "Введите оценки по предмету " << group.GetItems().at(i).GetName() << " :\n ";
			for (size_t i = 0; i < std::stoi(count); i++)
			{
				std::string grad;
				do {
					std::cout << "Введите оценку: ";
					getline(std::cin, grad);
				} while (ChackGrade(grad));
				grade.push_back(std::stoi( grad));
			}
			a.SetGrade({ group.GetItems().at(i).GetName(),grade });
		}
		group.SetStudents(a);
		std::cout << "Добавить еще студента - 1,нет - 0:  ";
		std::cin >> out;
		std::cin.get();
	} while (out);

}

void ShowGradeStudent(Group& group)
{
	for (size_t i = 0; i < group.GetItems().size(); i++)
	{
		std::cout << "Оценки по предмету " << group.GetItems().at(i).GetName() << ": \n";
		for (size_t j = 0; j < group.GetStudents().size(); j++)
		{
			std::cout << "Студент " << group.GetStudents().at(j).GetName() << ": ";
			for (size_t x = 0; x < group.GetStudents().at(j).GetGrade().size(); x++)
			{
				if (group.GetStudents().at(j).GetGrade().at(x).first == group.GetItems().at(i).GetName())
				{
					for (size_t c = 0; c < group.GetStudents().at(j).GetGrade().at(x).second.size(); c++)
					{
						std::cout << group.GetStudents().at(j).GetGrade().at(x).second.at(c) << " ";
					}
					std::cout << std::endl;
				}
			}
		}
	}
}

void AverageGrades(Group& group)
{
	for (size_t i = 0; i < group.GetStudents().size(); i++)
	{
		double sum = 0.0;
		int count = 0;
		std::cout << "Средняя оценка " << group.GetStudents().at(i).GetName() << " :\n ";
		for (size_t j = 0; j < group.GetStudents().at(i).GetGrade().size(); j++)
		{
			for (size_t c = 0; c < group.GetStudents().at(i).GetGrade().at(j).second.size(); c++)
			{
				sum += group.GetStudents().at(i).GetGrade().at(j).second.at(c);
				count++;
			}
		}
		std::cout << sum / count;
		std::cout << std::endl;
	}
}

void AverageGradeGroup(Group& group)
{
	double sum = 0.0;
	int count = 0;
	for (size_t i = 0; i < group.GetStudents().size(); i++)
	{
		for (size_t j = 0; j < group.GetStudents().at(i).GetGrade().size(); j++)
		{
			for (size_t c = 0; c < group.GetStudents().at(i).GetGrade().at(j).second.size(); c++)
			{
				sum += group.GetStudents().at(i).GetGrade().at(j).second.at(c);
				count++;
			}
		}
	}
	std::cout << "Средняя оценка группы: " << sum / count;
	std::cout << std::endl;
}

void AverageCradeItems(Group& group)
{
	for (size_t i = 0; i < group.GetStudents().size(); i++)
	{
		double sum = 0.0;
		int count = 0;
		std::cout << "Средняя оценка " << group.GetStudents().at(i).GetName() << " :\n ";
		for (size_t j = 0; j < group.GetStudents().at(i).GetGrade().size(); j++)
		{
			std::cout << "По предмету " << group.GetStudents().at(i).GetGrade().at(j).first << " : ";
			for (size_t c = 0; c < group.GetStudents().at(i).GetGrade().at(j).second.size(); c++)
			{
				sum += group.GetStudents().at(i).GetGrade().at(j).second.at(c);
				count++;
			}
			std::cout << sum / count;
			std::cout << std::endl;
		}
	}
}

void MaxMinItems(Group& group)
{
	for (size_t i = 0; i < group.GetStudents().size(); i++)
	{
		std::cout << "У студента " << group.GetStudents().at(i).GetName() << " : \n";
		for (size_t j = 0; j < group.GetStudents().at(i).GetGrade().size(); j++)
		{
			std::cout << "По предмету " << group.GetStudents().at(i).GetGrade().at(j).first << " :\n ";
			uint32_t max = group.GetStudents().at(i).GetGrade().at(j).second.at(0);
			uint32_t min = group.GetStudents().at(i).GetGrade().at(j).second.at(0);
			std::cout << "По предмету " << group.GetStudents().at(i).GetGrade().at(j).first << " : \n";
			for (size_t c = 0; c < group.GetStudents().at(i).GetGrade().at(j).second.size(); c++)
			{
				if (max < group.GetStudents().at(i).GetGrade().at(j).second.at(c))
					max = group.GetStudents().at(i).GetGrade().at(j).second.at(c);
				else if (min > group.GetStudents().at(i).GetGrade().at(j).second.at(c))
					min = group.GetStudents().at(i).GetGrade().at(j).second.at(c);
			}
			std::cout << "Максимальная - " << max << std::endl;
			std::cout << "Минимальная  - " << min << std::endl;
		}
	}
}