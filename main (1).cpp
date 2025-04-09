/*
 * Matrix Operations Program
 * Author: Sreeja Narahari
 * Date: 04/01/2025
 * Description: This program performs various matrix operations such as addition,
 * multiplication, diagonal sum calculation, row/column swapping, and element updates.
 * Collaborators: None
 * Other sources: ChatGPT, Geeksforgeeks
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Matrix class template
template <typename T>
class Matrix {
private:
    vector<vector<T>> data; // 2D vector to store matrix data
    int size; // Size of the matrix

public:
    // Constructor to initialize the matrix
    Matrix(int n) : size(n) {
        data.resize(n, vector<T>(n));
    }

    // Function to load matrix data from a file
    void loadFromFile(const string &filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file!" << endl;
            exit(1);
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> data[i][j];
            }
        }
    }

    // Function to display the matrix
    void display() const {
        for (const auto &row : data) {
            for (const auto &elem : row) {
                cout << setw(5) << elem << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Overloading the + operator for matrix addition
    Matrix operator+(const Matrix &other) {
        Matrix result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Overloading the * operator for matrix multiplication
    Matrix operator*(const Matrix &other) {
        Matrix result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < size; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Function to calculate the sum of the main and secondary diagonals
    T diagonalSum() const {
        T sum = 0;
        for (int i = 0; i < size; i++) {
            sum += data[i][i] + data[i][size - i - 1];
        }
        return sum;
    }

    // Function to swap two rows in the matrix
    void swapRows(int r1, int r2) {
        if (r1 >= 0 && r1 < size && r2 >= 0 && r2 < size) {
            swap(data[r1], data[r2]);
        }
    }

    // Function to swap two columns in the matrix
    void swapCols(int c1, int c2) {
        if (c1 >= 0 && c1 < size && c2 >= 0 && c2 < size) {
            for (int i = 0; i < size; i++) {
                swap(data[i][c1], data[i][c2]);
            }
        }
    }

    // Function to update a specific element in the matrix
    void updateElement(int row, int col, T value) {
        if (row >= 0 && row < size && col >= 0 && col < size) {
            data[row][col] = value;
        }
    }
};

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    
    ifstream file(filename);
    if (!file) {
        cerr << "File not found!" << endl;
        return 1;
    }

    int N, type;
    file >> N >> type;
    
    // Handling integer or double matrices based on type flag
    if (type == 0) {
        Matrix<int> A(N), B(N);
        A.loadFromFile(filename);
        B.loadFromFile(filename);
        cout << "Matrix A:" << endl;
        A.display();
        cout << "Matrix B:" << endl;
        B.display();
        
        cout << "A + B:" << endl;
        (A + B).display();

        cout << "A * B:" << endl;
        (A * B).display();
    } else {
        Matrix<double> A(N), B(N);
        A.loadFromFile(filename);
        B.loadFromFile(filename);
        cout << "Matrix A:" << endl;
        A.display();
        cout << "Matrix B:" << endl;
        B.display();
        
        cout << "A + B:" << endl;
        (A + B).display();

        cout << "A * B:" << endl;
        (A * B).display();
    }

    return 0;
}
