#include "lab5.h"

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 1 задача
void FileTasks::fillBinaryFile1(const string& filename, int count) {
  ofstream file(filename, ios::binary);
  srand((unsigned int)time(nullptr));
  for (int i = 0; i < count; i++) {
    int num = rand() % 201 - 100; 
    file.write((char*)&num, sizeof(num));
  }
  file.close();
}

int FileTasks::countOppositePairs(const string& filename) {
  ifstream file(filename, ios::binary);
  vector<int> numbers;
  int num;
  while (file.read((char*)&num, sizeof(num))) {
    numbers.push_back(num);
  }
  file.close();

  cout << "Числа в файле: ";
  for (size_t i = 0; i < numbers.size(); i++) {
    cout << numbers[i];
    if (i != numbers.size() - 1) cout << ", ";
  }
  cout << endl;

  int count = 0;
  for (size_t i = 0; i < numbers.size(); i++) {
    for (size_t j = i + 1; j < numbers.size(); j++) {
      if (numbers[i] + numbers[j] == 0) {
        count++;
      }
    }
  }
  return count;
}

// 2 задача
void FileTasks::fillBinaryFile2(const string& filename, int count) {
  ofstream file(filename, ios::binary);
  srand((unsigned int)time(nullptr));
  for (int i = 0; i < count; i++) {
    int num = rand() % 100;  
    file.write((char*)&num, sizeof(num));
  }
  file.close();
}

void FileTasks::replaceColumnsWithMaxInColumn(const string& filename, int n) {
  ifstream file(filename, ios::binary);
  vector<int> data;
  int num;
  while (file.read((char*)&num, sizeof(num))) {
    data.push_back(num);
  }
  file.close();

  vector<vector<int>> matrix(n, vector<int>(n, 0));

  int index = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (index < (int)data.size()) {
        matrix[i][j] = data[index++];
      }
    }
  }

  cout << "Исходная матрица " << n << "x" << n << ":\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << setw(4) << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  for (int col = 0; col < n; col++) {
    int maxVal = INT_MIN;
    for (int row = 0; row < n; row++) {
      if (matrix[row][col] > maxVal) {
        maxVal = matrix[row][col];
      }
    }
    for (int row = 0; row < n; row++) {
      matrix[row][col] = maxVal;
    }
  }

  cout << "Матрица после замены столбцов на максимальные значения:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << setw(4) << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

// 3 задача
void FileTasks::fillBinaryFile3(const string& filename, int passengerCount) {
  ofstream file(filename, ios::binary);
  srand((unsigned int)time(nullptr));
  string baggageNames[] = {"Чемодан", "Сумка", "Рюкзак", "Коробка", "Пакет"};

  for (int p = 0; p < passengerCount; p++) {
    int itemsCount = rand() % 5 + 1;  
    vector<BaggageItem> items;

    for (int i = 0; i < itemsCount; i++) {
      BaggageItem item;
      item.name = baggageNames[rand() % 5];
      item.weight = (rand() % 5000) / 100.0;  
      items.push_back(item);
    }

    int count = (int)items.size();
    file.write((char*)&count, sizeof(count));
    for (const auto& item : items) {
      size_t len = item.name.size();
      file.write((char*)&len, sizeof(len));
      file.write(item.name.c_str(), len);
      double weight = item.weight;
      file.write((char*)&weight, sizeof(weight));
    }
  }
  file.close();
}

double FileTasks::massDifferenceMaxMin(const string& filename) {
  ifstream file(filename, ios::binary);
  double maxMass = 0, minMass = 1e9;

  while (file.peek() != EOF) {
    int count;
    file.read((char*)&count, sizeof(count));
    double totalMass = 0;

    for (int i = 0; i < count; i++) {
      size_t len;
      file.read((char*)&len, sizeof(len));
      string name(len, ' ');
      file.read(&name[0], len);
      double weight;
      file.read((char*)&weight, sizeof(weight));
      totalMass += weight;
    }

    if (totalMass > maxMass) maxMass = totalMass;
    if (totalMass < minMass) minMass = totalMass;
  }
  file.close();

  return maxMass - minMass;  
}

// 4 задача
void FileTasks::fillTextFile4(const string& filename, int count) {
  ofstream file(filename);
  srand((unsigned int)time(nullptr));
  for (int i = 0; i < count; i++) {
    int num = rand() % 21 - 10;  
    file << num << endl;
  }
  file.close();
}

bool FileTasks::fileContainsZero(const string& filename) {
  ifstream file(filename);
  int num;
  vector<int> numbers;

  while (file >> num) {
    numbers.push_back(num);
  }
  file.close();

  cout << "Содержимое файла: ";
  for (size_t i = 0; i < numbers.size(); i++) {
    cout << numbers[i];
    if (i != numbers.size() - 1) cout << ", ";
  }
  cout << endl;

  for (int n : numbers) {
    if (n == 0) return false;
  }
  return true;
}

//5 задача
void FileTasks::fillTextFile5(const string& filename, int rows, int cols) {
  ofstream file(filename);
  srand((unsigned int)time(nullptr));

  vector<vector<int>> lines(rows);

  for (int i = 0; i < rows; i++) {
    int numbersInLine = rand() % 5 + 2;  

    for (int j = 0; j < numbersInLine; j++) {
      int num = rand() % 100; 
      lines[i].push_back(num);
      file << num;
      if (j != numbersInLine - 1) file << " ";
    }
    file << endl;
  }
  file.close();

  cout << "Содержимое файла (числа по несколько в строке):\n";
  for (int i = 0; i < rows; i++) {
    cout << "Строка " << i + 1 << ": ";
    for (size_t j = 0; j < lines[i].size(); j++) {
      cout << lines[i][j];
      if (j != lines[i].size() - 1) cout << ", ";
    }
    cout << endl;
  }
}

int FileTasks::findMaxElement(const string& filename) {
  ifstream file(filename);
  int maxVal = INT_MIN, num;
  vector<int> numbers;

  while (file >> num) {
    numbers.push_back(num);
    if (num > maxVal) maxVal = num;
  }
  file.close();

  cout << "Все числа в файле (" << numbers.size() << " чисел): ";
  for (size_t i = 0; i < numbers.size(); i++) {
    cout << numbers[i];
    if (i != numbers.size() - 1) cout << ", ";
  }
  cout << endl;

  return maxVal;
}

// 6 задача
void FileTasks::fillTextFile6(const string& filename, int lineCount) {
  ofstream file(filename);
  srand((unsigned int)time(nullptr));
  string words[] = {"cat", "banana", "cherry", "date",
                    "dog", "fox",    "wolf",   "zebra"};

  for (int i = 0; i < lineCount; i++) {
    int wordsInLine = rand() % 8 + 1;
    string line;
    for (int j = 0; j < wordsInLine; j++) {
      string word = words[rand() % 8];
      line += word;
      if (j != wordsInLine - 1) line += " ";
    }
    file << line << endl;
  }
  file.close();
}

void FileTasks::copyLinesEndingWithChar(const string& src, const string& dst,
                                        char ch) {
  ifstream in(src);
  ofstream out(dst);
  string line;
  int lineNum = 1;

  cout << "Содержимое файла:" << endl;
  while (getline(in, line)) {
    cout << "Строка " << lineNum++ << ": \"" << line << "\"";
    cout << endl;
  }
  in.close();

  in.open(src);
  int copied = 0;

  cout << "\nСтроки, оканчивающиеся на '" << ch << "':" << endl;
  while (getline(in, line)) {
    if (!line.empty() && line.back() == ch) {
      out << line << endl;
      cout << "  \"" << line << "\"" << endl;
      copied++;
    }
  }
  in.close();
  out.close();

  cout << "Скопировано строк: " << copied << endl;
}