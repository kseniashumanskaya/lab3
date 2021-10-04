#include <iostream>
#include <vector>
using namespace std;

int TheNumberOfTheFirstRowContaining0(vector <vector<int>>vec, int size) {
    int m, num;
    for (int i = 0; i < size; i++) {
        m = 0;
        num = -1;
        for (int j = 0; j < size; j++) {
            if (vec[i][j] == 0)
                m++;
        }
        if (m > 0)
        {
            num = i;
            break;
        }

    }
    return num;
}

int main() {

    int size;
    cout << "enter the size of the matrix:" << endl;
    cin >> size;

    cout << " enter 0 if you want to fill the matrix with random numbers and 1 - from consol" << endl;
    int matrix_filling_option;
    cin >> matrix_filling_option;
    vector <vector<int>> vec;
    if (matrix_filling_option == 0) {
        srand(time(0));
        for (int i = 0; i < size; i++) {
            vector <int> temp;
            for (int j = 0; j < size; j++) {

                temp.push_back(rand() % 20 - 10);
            }
            vec.push_back(temp);
        }
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec.size(); j++)
                vec[i][j] = vec[j][i];
        }
    }

    else {
        vector <vector<int>> vec2;
        cout << "enter matrix elements:" << endl;
        for (int i = 0; i < size; i++) {
            vector <int> vec1;
            int n;
            for (int j = 0; j < i + 1; j++) {
                cin >> n;
                vec1.push_back(n);
            }
            vec2.push_back(vec1);
            vector <vector<int>> vec;
        }
        for (int i = 0; i < size; i++) {
            vector <int> temp;
            for (int j = 0; j < size; j++) {

                temp.push_back(0);
            }
            vec.push_back(temp);
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (j < i + 1) {
                    vec[i][j] = vec2[i][j];
                }
                else vec[i][j] = vec2[j][i];
            }
            cout << endl;
        }
    }


    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++)
        {
            cout << vec[i][j] << "  ";
        }
        cout << endl;
    }

    if (TheNumberOfTheFirstRowContaining0(vec, size) < 0)
        cout << " there is no zero element in the matrix  " << endl;
    else
        cout << "the number of the first row containing 0 : " << TheNumberOfTheFirstRowContaining0(vec, size) + 1 << endl;

    int s = 0;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            s += abs(vec[i][j]);
        }
    }

    if (s == 0) {
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec.size(); j++) {
                vec.pop_back();
            }
        }
        cout << "matrix consisted of only zeros" << endl;
    }

    else {
        for (int k = 0; k < vec.size(); k++) {
            for (int i = 0; i < vec.size(); i++) {
                int s = 0;
                for (int j = 0; j < vec.size(); j++) {
                    s += abs(vec[i][j]);
                }
                if (s == 0) {
                    int  a = i;
                    while (i < vec.size() - 1) {
                        for (int j = 0; j < vec.size(); j++)
                            vec[i][j] = vec[i + 1][j];
                        i++;
                    }
                    for (int j = a; j < vec.size() - 1; j++) {
                        for (int i = 0; i < vec.size(); i++)
                            vec[i][j] = vec[i][j + 1];
                    }
                    vec.pop_back();
                    k--;
                }
            }
        }
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec.size(); j++)
            {
                cout << vec[i][j] << "  ";
            }
            cout << endl;
        }
    }
}

