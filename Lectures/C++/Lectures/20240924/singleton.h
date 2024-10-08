#pragma once


template <typename T>
class CSingleton 
{
public:
	static T& GetInstance() {
		static T inst;
		return inst;
	}
	CSingleton(const CSingleton&) = delete;
	void operator=(const CSingleton&) = delete;

protected:
	CSingleton(){}
	~CSingleton(){}
};