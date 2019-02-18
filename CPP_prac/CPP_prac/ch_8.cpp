#include <iostream>
#include <cstring>

class Employee {
private:
	char name[100];

public:
	Employee(const char * name) {
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	void ShowYourName() const {
		std::cout << "name: " << name << std::endl;
	}

	virtual int GetPay() const = 0 {
		return 0;
	}

	virtual void ShowSalaryInfo() const = 0 {}
};

class Permanent : public Employee {

private:
	int salary;

public:
	Permanent(const char *name, int money) : Employee(name), salary(money) {}
	
	virtual int GetPay() const {
		return salary;
	}
	
	virtual void ShowSalaryInfo() const {
		ShowYourName();
		std::cout << "salary: " << GetPay() << std::endl << std::endl;
	}
};

class Temp : public Employee {

private:
	int workTime;
	int pay;

public:
	Temp(const char * name, int money) : Employee(name), workTime(0), pay(money) {}

	void AddWorkTime(int time) {
		workTime += time;
	}

	virtual int GetPay() const {
		return workTime * pay;
	}

	virtual void ShowSalaryInfo() const {
		ShowYourName();
		std::cout << "salary: " << GetPay() << std::endl << std::endl;
	}
};

class Sales : public Permanent {
private:
	int res;
	double bonus;

public:
	Sales(const char * name, int money, double ratio)
		: Permanent(name, money), res(0), bonus(ratio){}

	void AddSalesResult(int value) {
		res += value;
	}

	virtual int GetPay() const {
		return Permanent::GetPay() + (int) (res * bonus);
	}

	virtual void ShowSalaryInfo() const {
		ShowYourName();
		std::cout << "salary: " << GetPay() << std::endl << std::endl;
	}

};

namespace RISK_LEVEL {
	enum {
		RISK_A=3, RISK_B=2, RISK_C=1
	};
}

class ForeignSales : public Sales {
private:
	double level;
	
public:
	ForeignSales(const char *name, int salary, double ratio, int risk)
		: Sales(name, salary, ratio), level(risk) {}

	virtual int GetPay() const {
		int pay = Sales::GetPay();
		return pay + (int)(pay * (level/10));
	}

	virtual void ShowSalaryInfo() const {
		ShowYourName();
		std::cout << "salary: " << Sales::GetPay() << std::endl;
		std::cout << "risk pay: " << (int)(Sales::GetPay() * (level/10)) << std::endl;
		std::cout << "sum: " << GetPay() << std::endl << std::endl;

	}
};

class EmployeeHandler {
private:
	Employee *emp[50];
	int num;
public:
	EmployeeHandler() : num(0) { }
	
	void AddEmployee(Employee *empnew) {
		emp[num++] = empnew;
	}

	void ShowAllSalaryInfo() const {
		for (int i = 0; i < num; i++) {
			emp[i]->ShowSalaryInfo();
		}
	}

	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < num; i++) {
			sum += emp[i]->GetPay();
		}
		std::cout << "salary sum: " << sum << std::endl;
	}

	~EmployeeHandler() {
		for (int i = 0; i < num; i++) {
			delete emp[i];
		}
	}

};



int q8_1_1() {
	EmployeeHandler handler;
	
	ForeignSales * seller1 = new ForeignSales("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	seller1->AddSalesResult(7000);
	handler.AddEmployee(seller1);
	
	ForeignSales * seller2 = new ForeignSales("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	seller2->AddSalesResult(7000);
	handler.AddEmployee(seller2);
	
	ForeignSales * seller3 = new ForeignSales("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	seller3->AddSalesResult(7000);
	handler.AddEmployee(seller3);

	handler.ShowAllSalaryInfo();
	return 0;
}


int main(void) {
	q8_1_1();

	return 0;
}