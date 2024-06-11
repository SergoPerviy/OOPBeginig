#include <iostream>
#include <string>

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	//Создание класса
	class Student {
	//Все данные до public находятся в зоне private
		std::string name;
		int* marks;
		int marks_number;
		int age;

	public:
		//Конструктор по умолчанию
		Student() {
			std::cout << "Конструктор по умолчанию.\n";
			name = "noname";
			marks = nullptr;
			marks_number = 0;
			age = 0;
		}

		//Параметрический конструктор
		Student(std::string other_name, int other_age = 0) {
			std::cout << "Параметрический конструктор.\n";
			name = other_name;
			marks = nullptr;
			marks_number = 0;
			setAge(other_age);
		}
		
		//Дестрактор (удаляет данные переменных в конце программы)
		~Student() {
			std::cout << "Деструктор.\n";
			delete[] marks;
		}

		//Метод класса (функция внутри класса)
		void say_name() {
			std::cout << "My name is " << name << "\n";
		}

		//Метод класса, который является свойством сеттера класса, позволяющим передать значения класса
		void setMark(int mark) {
			if (marks == nullptr) {
				marks = new int[1] { mark };
				marks_number = 1;
				return;
			}
			int* tmp = new int[marks_number + 1];
			for (size_t i = 0; i < marks_number; ++i)
				tmp[i] = marks[i];
			tmp[marks_number] = mark;
			delete[] marks;
			marks = tmp;
			++marks_number;
		} 

		//Метод класса, который является свойством геттера класса, позволяющим получить значения класса
		int getMark(size_t index) {
			return marks[index];
		}

		void setAge(int other_age) {
			if (other_age >= 5 && other_age <= 55) {
				age = other_age;
				return;
			}
			age = 0;
		}

		int getAge() {
			return age;
		}

	};

	Student s1("Alex", 10);

	//s1.name = "Alex"; //Ошибка! (инкапсуляция) 

	s1.say_name(); //Вызов метода класса, вывод имени
	s1.setMark(6); //Вызов метода сеттера передача оценки №1
	s1.setMark(12); //Вызов метода сеттера передача оценки №2
	std::cout << "Оценка №1: " << s1.getMark(0) << std::endl;
	std::cout << "Оценка №2: " << s1.getMark(1) << std::endl;
	std::cout << "Возраст: " << s1.getAge() << std::endl; //Вызов метода геттера вывод возраста через std

	return 0;
}