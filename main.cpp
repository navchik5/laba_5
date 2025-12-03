#include <windows.h>  

#include <iostream>

#include "lab5.h"

using namespace std;

int main() {
  SetConsoleOutputCP(1251);
  SetConsoleCP(1251);

  int choice;
  cout << "========================================" << endl;
  cout << "        ЛАБОРАТОРНАЯ РАБОТА №5" << endl;
  cout << "              Вариант 4" << endl;
  cout << "========================================" << endl;
  cout << endl;
  cout << "ВЫБЕРИТЕ ЗАДАНИЕ ДЛЯ ВЫПОЛНЕНИЯ:" << endl;
  cout << "1. Подсчет пар противоположных чисел" << endl;
  cout << "2. Замена столбцов матрицы на максимальные значения" << endl;
  cout << "3. Разница масс багажа пассажиров" << endl;
  cout << "4. Проверка файла на отсутствие нулей" << endl;
  cout << "5. Поиск максимального элемента" << endl;
  cout << "6. Копирование строк по последнему символу" << endl;
  cout << "========================================" << endl;
  cout << "Ваш выбор (1-6): ";
  cin >> choice;

  cout << endl << "========================================" << endl;

  switch (choice) {
    case 1: {
      string filename = "data1.bin";
      int count = 20; 
      cout << "ЗАДАНИЕ 1: ПОДСЧЕТ ПАР ПРОТИВОПОЛОЖНЫХ ЧИСЕЛ" << endl;
      cout << "------------------------------------------" << endl;
      cout << "Генерация " << count << " случайных чисел..." << endl;
      FileTasks::fillBinaryFile1(filename, count);
      int pairs = FileTasks::countOppositePairs(filename);
      cout << "----------------------------------------" << endl;
      cout << "РЕЗУЛЬТАТ: Найдено " << pairs << " пар противоположных чисел"
           << endl;
      break;
    }
    case 2: {
      string filename = "data2.bin";
      int n;
      cout << "ЗАДАНИЕ 2: ЗАМЕНА СТОЛБЦОВ МАТРИЦЫ" << endl;
      cout << "--------------------------------------" << endl;

     
      while (true) {
        cout << "Введите размер матрицы n (целое число > 0): ";
        if (cin >> n && n > 0) {
          break;
        } else {
          cout << "ОШИБКА: Введите целое положительное число!" << endl;
          cin.clear();             
          cin.ignore(1000, '\n');  
        }
      }

      int count = 20;
      cout << "Генерация " << count << " чисел для матрицы " << n << "x" << n
           << "..." << endl;
      FileTasks::fillBinaryFile2(filename, count);
      cout << "----------------------------------------" << endl;
      cout << "ОБРАБОТКА МАТРИЦЫ..." << endl;
      FileTasks::replaceColumnsWithMaxInColumn(filename, n);
      break;
    }
    case 3: {
      string filename = "data3.bin";
      cout << "ЗАДАНИЕ 3: РАЗНИЦА МАСС БАГАЖА ПАССАЖИРОВ" << endl;
      cout << "----------------------------------------" << endl;
      double diff = FileTasks::massDifferenceMaxMin(filename);
      cout << "РЕЗУЛЬТАТ: Разница масс = " << diff << " кг" << endl;
      break;
    }
    case 4: {
      string filename = "data4.txt";
      int count = 15; 
      cout << "ЗАДАНИЕ 4: ПРОВЕРКА ФАЙЛА НА ОТСУТСТВИЕ НУЛЕЙ" << endl;
      cout << "--------------------------------------------" << endl;
      cout << "Генерация " << count << " случайных чисел..." << endl;
      FileTasks::fillTextFile4(filename, count);
      cout << "----------------------------------------" << endl;
      bool noZero = FileTasks::fileContainsZero(filename);
      if (noZero) {
        cout << "true" << endl;
      } else {
        cout << "false" << endl;
      }
      break;
    }
    case 5: {
      string filename = "data5.txt";
      int rows = 8;  
      int cols = 1;  
      cout << "ЗАДАНИЕ 5: ПОИСК МАКСИМАЛЬНОГО ЭЛЕМЕНТА" << endl;
      cout << "----------------------------------------" << endl;
      cout << "Генерация файла с " << rows << " строками чисел..." << endl;
      FileTasks::fillTextFile5(filename, rows, cols);
      cout << "----------------------------------------" << endl;
      int maxElem = FileTasks::findMaxElement(filename);
      cout << "РЕЗУЛЬТАТ: Максимальный элемент = " << maxElem << endl;
      break;
    }
    case 6: {
      string src = "data6.txt", dst = "output6.txt";
      char ch;
      int lineCount = 10;  
      cout << "ЗАДАНИЕ 6: КОПИРОВАНИЕ СТРОК ПО ПОСЛЕДНЕМУ СИМВОЛУ" << endl;
      cout << "========================================" << endl;

      
      cout << "Введите символ для фильтрации (один символ): ";
      cin >> ch;

      cout << "Генерация " << lineCount << " строк..." << endl;
      FileTasks::fillTextFile6(src, lineCount);
      cout << "----------------------------------------" << endl;
      cout << "ФИЛЬТРАЦИЯ СТРОК..." << endl;
      FileTasks::copyLinesEndingWithChar(src, dst, ch);
      cout << "----------------------------------------" << endl;
      cout << "Результат сохранен в файле: " << dst << endl;
      break;
    }
    default:
      cout << "ОШИБКА: Неверный выбор!" << endl;
  }

  cout << "========================================" << endl;
  cout << "Нажмите Enter для выхода...";
  cin.ignore();
  cin.get();

  return 0;
}