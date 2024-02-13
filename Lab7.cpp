#include <iostream>
#include "Lab7FuncLib.h"
#include <vector>
#include <fstream>


using namespace std;

int main()
{

    std::vector<CPhR> vecPhR;

    setlocale(LC_ALL, "RU-RU");
    //    //CPhN A(22332245678L, 1), B;//ctor
    //    //A.PrintPhoneNo();
    //    //A.InPhoneNo();
    //    //A.PrintPhoneNo();
    int n = 0;
    CPhR C;
    size_t MaxL = 0;
    std::string fileName;
    cout << "\nвведите название файла(txt) который хотите создать\n";
    cin >> fileName;
    ofstream MyFile("C:\\Users\\Jazer\\source\\repos\\ConsoleApplication6\\ConsoleApplication6\\" + fileName + ".txt");
    do
    {
        //C.InPhoneNo();
       //C.PrintPhoneNo();
       //C = C + "Александр" + "Македонский" + std::to_string(n+1).c_str();
       //C.write();
        C.read();
        if (C.IsVald())
            vecPhR.push_back(C);
        else
            break;
        if (C.GetNikLen() > MaxL)
            MaxL = C.GetNikLen();
    } while (1);
    std::vector<CPhR> newVec = SimpleSort(vecPhR);
    rightLeftSort(vecPhR);
    std::cout << "\n/////////////////////сортировка пузырьком/////////////////////\n";
    for (int i = 0; i < vecPhR.size(); i++)
        vecPhR[i].write(MaxL, i + 1, MyFile);
    std::cout << "\n/////////////////////сортировка обычная/////////////////////\n";
    MyFile.close();
    for (int j = 0; j < newVec.size(); j++)
        newVec[j].write(MaxL, j + 1, MyFile);
    ////std::vector<CPhR>::iterator it;
     //for (auto it = newVec.begin(); it != newVec.end(); it++)
     //    it->write(MaxL);//(*it).write(MaxL);
    string name;
    while (true) {
        cout << "\nвведите имя которое хотите найти пока не ноль\n";
        cin >> name;
        if (name != "0") {
            int t = binS(newVec, name);
            if (t == -1) {
                cout << "\nОшибка: такого имени нету\n";
            }
            else {
                newVec[t].write(MaxL, t + 1, MyFile);
            }
        }
        else {
            break;
        }
    }
    return 0;
}

