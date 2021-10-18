#include <iostream>
#include <vector>

using namespace std;

int TheNumberOfTheFirstRowContaining0(vector <vector<int>>vec, int size) {
    vector<int> RowsContaining0;
    int j;
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (j = 0; j < i + 1; j++) {
            if (vec[i][j] == 0) {
                RowsContaining0.push_back(min(i, j));
                k++;
            }     
        }      
    }
    int num = 11;
    for (int i = 0; i < k; i++) {
        if (num > RowsContaining0[i]) {
            num = RowsContaining0[i];
        }
    }
    return num;
}

int GetElements(const vector<vector<int>>& vec, int i, int j) {
    if (j < i + 1) {
        return vec[i][j];
    }
    else {
        return vec[j][i];
    }
}

void FillingTheMatrixFromConsol(vector<vector<int>> &vec, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i + 1; j++) {
            int n;
            cin >> n;
            vec[i].push_back(n);
        }     
    }   
}

void FillingTheMatrixWithRandomNumber(vector<vector<int>>& vec, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i + 1; j++) {
            vec[i].push_back(rand() % 20 - 10);
        }
    }
}

void matrixOutput(vector<vector<int>>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            cout << GetElements(vec, i, j) << " ";
        }
        cout << endl;
    }
}

void NewMatrixOutput(vector<vector<int>>& vec, int size) {
    for (int k = 0; k < size; k++) {
        int s = 0;
        for (int i = 0; i < size; i++) {
            if (i <= k) {
                s += abs(vec[k][i]);
            }
            else {
                s += abs(vec[i][k]);
            }
        }
        if (s == 0) {
            for (int i = k; i < size; i++) {
                for (int j = k; j < i; j++) {
                    swap(vec[i][j], vec[i][j + 1]);
                }
            }
            int i = k;
            while (i < size - 1) {
                for (int j = 0; j < i + 1; j++)
                    swap(vec[i][j], vec[i + 1][j]);
                i++;
            }
            for (int i = 0; i < size; i++)
                vec[size - 1].erase(vec[size - 1].begin());
            size--;
            k--;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
        {
            cout << GetElements(vec, i, j) << "  ";
        }
        cout << endl;
    }
}

int main() {
    int size;
    cout << "enter the size of the matrix < 10:" << endl;
    cin >> size;
    vector<vector<int>> vec(size, vector<int>());
    cout << " enter 0 if you want to fill the matrix with random numbers and 1 - from consol" << endl;
    int matrix_filling_option;
    cin >> matrix_filling_option;
    if (matrix_filling_option == 0) {
        FillingTheMatrixWithRandomNumber(vec, size);
    }
    else {
        FillingTheMatrixFromConsol(vec, size);
    }  
    matrixOutput(vec);
    if (TheNumberOfTheFirstRowContaining0(vec, size) > 10) {
        cout << " there is no zero element in the matrix  " << endl;
    }
    else {
        cout << "the number of the first row containing 0 : " << TheNumberOfTheFirstRowContaining0(vec, size) + 1 << endl;
    }

    NewMatrixOutput(vec, size);  
}
