#pragma once
#include <cmath>
#include <cstdlib>
#include <getopt.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
class calc
{
public:
    double nat_log(const vector<double>& operands);
    double base_log(const vector<double>& operands);
};