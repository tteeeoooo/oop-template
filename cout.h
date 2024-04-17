#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>

using namespace std;

class Cout {
public:
    static void menuText();

    static float priceCalculation(float oldPrice, float sale);

    static void underLine();

    static void upperLine();

    static int textToFinish();

    static void orderAndExit();

    static void coutFinishedOrder();

    static void coutAbortedOrder();

    static void todaysSales();

    static void exitText();
};
