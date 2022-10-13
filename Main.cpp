#include <iostream>
#include "Circle.h"
#include "Figure.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <typeinfo>

using namespace std;
/*
Используя идентификацию типа времени исполнения
  (run - time type identification — RTTI) можно определить тип объекта во время исполнения программы.Для этого используется функция typeid. Для использования этой функции необходимо включить заголовочный файл typeinfo.Общая форма записи функции typeid имеет следующий вид :

typeid (объект)

Здесь объект является объектом, чей тип требуется определить.
Функция typeid возвращает ссылку на объект типа typeinfo, который описывает тип объекта. (В проекте стандарта С++ этот тип называется type_info.)
*/

Figure* GeneratorOfFigures()
{
	Figure* figure = nullptr;

	int choice = rand() % 3;// 0 1 2

	switch (choice)
	{
	case 0:
		figure = new Triangle(10.5, 6.5);
		break;
	case 1:
		figure = new Rectangle(10.5, 6.5);
		break;
	case 2:
		figure = new Circle(10);
		break;
	}

	return figure;
}

template<typename T>
void Test(T a)
{
	cout << typeid(a).name() << endl; // тип обьекта(переменной)

}

void Print(Figure* ptr)
{
	ptr->ShowArea();
	if (dynamic_cast<Circle*>(ptr)) // Нарушение принцыпа Барбары Лисков(SOLID) !!!! 
	{
		cout << "OK circle\n";
		dynamic_cast<Circle*>(ptr)->Test();
	}

}
int main()
{

	Figure* ptr = new Rectangle(12, 3);
	Print(ptr);
	delete ptr;
	ptr = new Circle(11);
	Print(ptr);
	delete ptr;


	Circle obj(10);
	Test(obj);
	Test(1);
	Test(1.4);
	Test('a');
	const unsigned int size = 10U;
	Figure* figures[size] = {};

	Circle* c = nullptr;
	Triangle* t = nullptr;
	Rectangle* r = nullptr;

	unsigned int countCircle = 0U;
	unsigned int countRectangle = 0U;
	unsigned int countTriangle = 0U;

	for (unsigned int i = 0U; i < size; ++i)
	{
		figures[i] = GeneratorOfFigures();

		c = dynamic_cast<Circle*>(figures[i]);

		if (c != nullptr)
		{
			++countCircle;
		}
		else
		{
			t = dynamic_cast<Triangle*>(figures[i]);
			if (t != nullptr)
			{
				++countRectangle;
			}
			else
			{
				++countTriangle;
			}
		}
	}
	cout << endl;
	cout << "Quantity of Circle: " << countCircle << endl;
	cout << "Quantity of Rectangle: " << countRectangle << endl;
	cout << "Quantity of Triangle: " << countTriangle << endl;


	system("pause");




	return 0;
}