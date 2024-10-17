#include "calс.h"

using namespace std;

void welcome()
{
    cout << "┌───────────────────────────────────────────────────────────────────────────────────────────┐\n";
    cout << "          ᠌ ᠌ ᠌᠌ ᠌ ᠌ ᠌ ᠌ ᠌  ᠌ ᠌ ᠌᠌ ᠌  ᠌ ᠌Добро пожаловать "
            "в "
            "логарифмический калькулятор\n";
    cout << "└───────────────────────────────────────────────────────────────────────────────────────────┘\n";
    cout << "┌───────────────────────────────────────────────────────────────────────────────────────────┐\n";

    cout << " Использование: ./calc -o e[log]|b[log] <число|числа>\n\n";

    cout << " Опции:\n";
    cout << "    -h, --help       - Показать справку\n\n";
    cout << "    -o, --operation  - Вызвать операцию вычесления\n\n";

    cout << " Операции вычисления:\n";
    cout << "     e, elog         - Натуральный логарифм\n";
    cout << "     b, blog         - Логарифм произвольных чисел\n\n";

    cout << " Примечание:\n";
    cout << "    Для выполнения вычисления натурального логарифма необходимо указать число в\n     подлогарифмическое "
            "выражение.\n";
    cout << "    Пример: ./сalc -o e 10\n";
    cout << "    Для выполнения вычисления произвольного логарифма необходимо указать два числа,\n     первое в "
            "основание, второе в подлогарифмическое выражение.\n";
    cout << "    Пример: ./сalc -o b 9 3\n";

    cout << "└───────────────────────────────────────────────────────────────────────────────────────────┘\n";
}

bool is_number(const string& s) {
    istringstream iss(s);
    double database;
    return !(iss >> database).fail();
}

int main(int argc, char* argv[]) {
    calc calculator;
    string operation;
    vector<double> operands;

    for (int i = 1; i < argc; ++i) {
        if (string(argv[i]) == "-h" || string(argv[i]) == "--help") {
            welcome();
            return 0;
        }
        if ((string(argv[i]) == "-o" || string(argv[i]) == "--operation") && (i + 1) < argc) {
            operation = argv[++i];
            if (operation != "e" && operation != "elog" && operation != "b" && operation != "blog") {
                cerr << "ОШИБКА: Неверный тип операции. Доступные операции: 'e' (elog), 'b' (blog)." << endl;
                welcome();
                return 1;
            }
        } else if (operation.empty()) {
            cerr << "ОШИБКА: Не указан тип операции. Доступные операции: 'e' (elog), 'b' (blog)." << endl;
            welcome();
            return 1;
        } else {
            if (!is_number(argv[i])) {
                cerr << "ОШИБКА: Неверный формат операнда: " << argv[i] << endl;
                return 1;
            }
            operands.push_back(stod(argv[i]));
        }
    }

    try {
        double result;
        if (operation == "e" || operation == "elog") {
            if (operands.size() != 1) {
                cerr << "ОШИБКА: Для вычисления натурального логарифма необходимо ввести ОДНО число." << endl;
                return 1;
            }
            result = calculator.nat_log(operands);
            cout << "┌───────────────────────────────────────────────────────────┐n";
            cout << " Результат вычисления натурального логарифма: " << result << "n";
            cout << "└───────────────────────────────────────────────────────────┘n";
        } else if (operation == "b" || operation == "blog") {
            if (operands.size() != 2) {
                cerr << "ОШИБКА: Для произвольного логарифма необходимо ввести ДВА числа." << endl;
                return 1;
            }
            result = calculator.base_log(operands);
            cout << "┌───────────────────────────────────────────────────────────┐n";
            cout << " Результат вычисления произвольного логарифма: " << result << "n";
            cout << "└───────────────────────────────────────────────────────────┘n";
        }
    } catch (const exception& e) {
        cerr << "ОШИБКА: " << e.what() << endl;
        return 1;
    }

    return 0;
}