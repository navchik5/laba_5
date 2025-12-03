#ifndef LAB5_H
#define LAB5_H

#include <string>
#include <vector>

struct BaggageItem {
  std::string name;
  double weight;
};

struct Passenger {
  std::vector<BaggageItem> items;
};


class FileTasks {
 public:
  
  static void fillBinaryFile1(const std::string& filename, int count);
  static int countOppositePairs(const std::string& filename);

  static void fillBinaryFile2(const std::string& filename, int count);
  static void replaceColumnsWithMaxInColumn(const std::string& filename, int n);

  static void fillBinaryFile3(const std::string& filename, int passengerCount);
  static double massDifferenceMaxMin(const std::string& filename);

  static void fillTextFile4(const std::string& filename, int count);
  static bool fileContainsZero(const std::string& filename);

  static void fillTextFile5(const std::string& filename, int rows, int cols);
  static int findMaxElement(const std::string& filename);

  static void fillTextFile6(const std::string& filename, int lineCount);
  static void copyLinesEndingWithChar(const std::string& src,
                                      const std::string& dst, char ch);
};

#endif