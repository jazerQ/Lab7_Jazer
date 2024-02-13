#pragma once // Директива препроцессора, которая гарантирует, что файл будет включен только один раз
#include <string.h>  // Включение библиотеки для работы со строками
#define MY_STR_LEN 33 // Определение константы для длины строк
#define MY_TAB_CX 54 // Определение константы для горизонтального размера таблицы
#define MY_TAB_CY 100 // Определение константы для вертикального размера таблицы
#include <iostream> // Включение библиотеки для ввода/вывода
#include <vector>
///////////////////types///////////////////////
typedef unsigned long long ULL; // Определение псевдонима для типа unsigned long long

struct PhN_s // Определение структуры для представления телефонного номера
{
    ULL Number : 44; // 44 бита для хранения номера телефона  – т.к нам нужно длинное число размером <=13 символов 2^44 = 17592186044415 а длина этого 14 символов нам хватает с головой
    ULL Plus : 1; // 1 бит для хранения значения "плюс"
    PhN_s() {} // Конструктор по умолчанию
    PhN_s(ULL num, bool plus) { Number = num; Plus = plus; } // Конструктор с параметрами
    //PhN_s(ULL num, bool plus) : Number(num), Plus(plus) {}
};


typedef struct PhBookRec_s // Определение структуры для представления записи в телефонной книге
{
    PhN_s Phone; // Поле для хранения телефонного номера
    unsigned int por = 0; // Порядковый номер записи
    char Nik[MY_STR_LEN]; // Поле для хранения имени
    PhBookRec_s() {}  // Конструктор по умолчанию
    PhBookRec_s(ULL num, bool plus, const char* pName) :Phone(num, plus) { strcpy_s(Nik, pName); } // Конструктор с параметрами
}PhBookRec_t;

///////////////////classes////////////////////////

class CPhN  // Определение класса для работы с телефонными номерами
{
protected:
    ULL Number : 44; //44 bits in 64 rtotal space for Number
    ULL Plus : 1; //1 bit for plus
public:
    CPhN() {} // Конструктор по умолчанию
    CPhN(ULL num, bool plus) { Number = num; Plus = plus; } // Конструктор с параметрами
    ~CPhN() {} // Деструктор
    //PhN_s(ULL num, bool plus) : Number(num), Plus(plus) {}
    void PrintPhoneNo(std::ofstream& MyFile);  // Метод для печати телефонного номера
    int InPhoneNo();  	// Метод для ввода телефонного номера

};

class CPhR : public CPhN  // Определение класса для работы с записями в телефонной книге
{
protected:
    std::string Nick;  // Поле для хранения имени
public:
    bool OnOrOff = true;  // Порядковый номер записи
    CPhR() :CPhN() {} 	// Конструктор по умолчанию
    ~CPhR() {}  // Деструктор
    CPhR& operator +(const char* surname) { Nick += std::string(" ") + surname; return *this; } // Перегрузка оператора "+" для добавления фамилии
    void write(size_t Len, int por, std::ofstream& MyFile); // Метод для записи информации
    std::string Up() { // метод для возведения в верхний регистр
        std::string NewNick = ""; // создаю новую строку для записи в нее
        for (int i = 0; i < Nick.length(); i++) { // пробегаюсь по всему слову и добавляю посимвольно в новую строку символы в верхнем регистре
            NewNick += toupper(Nick[i]);
        }
        return NewNick;
    }
    void read(); // Метод для считывания информации
    bool IsVald() { return 0 != Number; } // Метод для проверки наличия значения телефонного номера
    size_t GetNikLen() { return Nick.size(); } // Метод для получения длины имени
    bool operator <(const CPhR& other) { return Nick < other.Nick; } // оператор меньше
    bool operator >(const CPhR& other) { return Nick > other.Nick; } // оператор больше
    bool operator ==(const CPhR& other) { return Nick == other.Nick; } // оператор равно
    bool operator !=(const std::string other) { return Nick != other; } // оператор неравно
    bool operator >(const std::string other) { return Nick > other; } // оператор неравно
    bool operator <(const std::string other) { return Nick < other; } // оператор неравно
};



///////////////////func/////////////////////////
int PrintfBin(int A); //1

int PrintfBin(int* A); //2

int PrintfBin3(int& A); //3

int CheckStr(char* pAr);

int CheckStr(char* pAr, size_t sz);

void TestDinArray();

void MakeTab(char* Tab, int cx, int cy);

void Print_XY_Tab(int x, int y, const char* strA, char* Tab, int cx, int cy);

void PrintPhoneNo(PhN_s* pPh, std::ofstream MyFile); // Функция для печати телефонного номера

void PrintPhoneBookRec(PhBookRec_t& PhBookRec); // Функция для печати записи в телефонной книге

int InPhoneNo(PhN_s* pPh); // Функция для ввода телефонного номера

int InPhoneRec(PhBookRec_t& PhBookRec); // Функция для ввода записи в телефонной книге


size_t FindMin(std::vector<CPhR>& Book); // функция для поиска минимального индекса

std::vector<CPhR> SimpleSort(std::vector<CPhR>& Book); // функция для простой сортировки

void rightLeftSort(std::vector<CPhR>& Book); // функция для сортировки пузырьком

int binS(std::vector<CPhR>& Book, std::string name);
