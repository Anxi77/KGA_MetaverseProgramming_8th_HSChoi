#pragma once
#include<iostream>
class Scene
{
private:
	std::string name;
	std::string desc;
	
public:
	Scene(const std::string& name, const std::string& desc)
		:name(name),desc(desc){}

	void Print()const;
};

