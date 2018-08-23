/*
 * Stock.h
 *
 *  Created on: 2010-1-9
 *      Author: kwarph
 */

#ifndef STOCK_H_
#define STOCK_H_

#include <string>

namespace StockSystem {

namespace StdForward {
using std::string;
using std::cin;
using std::cout;
using std::endl;
}

struct Stock {
    std::string code;
    double value;
};

/**
 * @brief Get selection from standard input,
 *        this routine always return correct selection number.
 */
int handleSelection(const std::string& prompt, const int& end,
        const int& start = 1);

/**
 * @brief Print all stocks in an array.
 */
void listStocks(Stock stocks[], const int& stockCount);

/**
 * @brief Print the specified stock.
 */
void listStock(const Stock& stock, const int& num);

/**
 * @brief Update the specified stock.
 */
void updateStock(Stock& stock, const int& num);

void updateStocks(Stock stocks[], const int& stockCount);

bool handleCommands(Stock stocks[], const int& stockCount);

}

#endif /* STOCK_H_ */
