#include "calc.h"

double calc::nat_log(const vector<double>& operands)
{
    double result = 0.0;
    if(operands.empty()) {
        throw invalid_argument("Нет операндов для вычисления логарифма.");
    }
    if(operands[0] > 0) {
        result += log(operands[0]);
    } else if(operands[0] <= 0) {
        throw runtime_error("Нельзя вычесть натуральный логарифм нуля и меньше.");
    }
    return result;
}

double calc::base_log(const vector<double>& operands)
{
    if(operands.empty()) {
        throw invalid_argument("Нет операндов для вычисления логарифма.");
    }
    double result = 0.0;
    double x = operands[0];
    double y = operands[1];
    if(x < 0) {
        throw runtime_error("Подлогарифмическое выражение должно быть больше 0.");
    }
    if(y <= 0 || y == 1) {
        throw runtime_error("Основание логарифма должно быть больше 0 и не равно 1.");
    }
    result = log(x) / log(y);
    return result;
}
