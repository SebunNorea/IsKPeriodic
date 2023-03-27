#include <iostream>
#include <string>

using namespace std;

bool IsKPeriodic(string str, int k) {
    int n = str.size();
    if (n % k != 0) { // если длина строки не кратна K, то она не является K-кратной
        return false;
    }
    for (int i = 0; i < k; i++) { // перебираем все символы из первой K-подстроки
        for (int j = i + k; j < n; j += k) { // перебираем символы из остальных K-подстрок
            if (str[j] != str[i]) { // если символы не совпадают, то строка не является K-кратной
                return false;
            }
        }
    }
    return true;
}

int main() {
    string str = "abcabcabcabc";
    int k = 3;
    if (IsKPeriodic(str, k)) {
        cout << "Строка является " << k << "-кратной." << endl;
    } else {
        cout << "Строка не является " << k << "-кратной." << endl;
    }
    return 0;
}
