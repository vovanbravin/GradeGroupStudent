#pragma once
#include <iostream>
#include <vector>
#include <string>

class Student
{
	std::string name;
	std::vector <std::pair<std::string,std::vector<uint32_t>>>grade;
public:
	Student() :name{ "NoName" } {};
	~Student() { grade.clear(); };
	inline std::string GetName() { return name; };
	inline void SetName(std::string name) { this->name = name; };
	inline std::vector<std::pair<std::string, std::vector<uint32_t>>> GetGrade() { return grade; };
	inline void SetGrade(std::pair<std::string, std::vector<uint32_t>>p1) { grade.push_back(p1); };
};


class Item
{
	std::string name;
public:
	Item() :name{ "NoItem" } {};
	inline std::string GetName() { return name; };
	inline void SetName(std::string name) { this->name = name; };
};


class Group
{
	std::string name;
	std::vector<Student>students;
	std::vector<Item>items;
public:
	//Group() :name{ "NoName" } {};
	~Group()
	{
		students.clear();
		items.clear();
	}
	inline std::string GetName() { return name; };
	inline std::vector<Item> GetItems() { return items; };
	inline std::vector<Student> GetStudents() { return students; };

	inline void SetName(std::string name) { this->name = name; };
	inline void SetStudents(Student a) { students.push_back(a); };
	inline void SetItems(Item a) { items.push_back(a); };
};