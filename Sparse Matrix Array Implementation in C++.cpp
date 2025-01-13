#include <iostream>
#include <vector>
using namespace std;

// Structure to represent non-zero elements in the sparse matrix
struct Element {
    int row;
    int col;
    int value;
};

// Class to implement the Sparse Matrix
class SparseMatrix {
private:
    vector<Element> elements;
    int rows, cols;

public:
    // Constructor
    SparseMatrix(int rows, int cols) : rows(rows), cols(cols) {}

    // Function to add a non-zero element
    void addElement(int row, int col, int value) {
        if (value != 0) {
            elements.push_back({row, col, value});
        }
    }

    // Function to display the sparse matrix representation
    void displaySparse() const {
        cout << "Sparse Matrix Representation:" << endl;
        cout << "Row\tCol\tValue" << endl;
        for (const auto& elem : elements) {
            cout << elem.row << "\t" << elem.col << "\t" << elem.value << endl;
        }
    }

    // Function to display the original matrix
    void displayOriginal() const {
        cout << "Original Matrix:" << endl;
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (k < elements.size() && elements[k].row == i && elements[k].col == j) {
                    cout << elements[k].value << " ";
                    k++;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    // Function to transpose the sparse matrix
    SparseMatrix transpose() const {
        SparseMatrix transposed(cols, rows);
        for (const auto& elem : elements) {
            transposed.addElement(elem.col, elem.row, elem.value);
        }
        return transposed;
    }
};

int main() {
    // Define the size of the matrix
    int rows = 4, cols = 5;

    // Create an instance of the SparseMatrix
    SparseMatrix sparse(rows, cols);

    // Input the matrix (can also be taken from user)
    int matrix[4][5] = {
        {5, 0, 0, 0, 0},
        {0, 8, 0, 0, 0},
        {0, 0, 0, 6, 0},
        {0, 0, 0, 0, 4}
    };

    // Populate the sparse matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sparse.addElement(i, j, matrix[i][j]);
        }
    }

    // Display the original matrix and sparse representation
    sparse.displayOriginal();
    sparse.displaySparse();

    // Transpose the sparse matrix and display it
    SparseMatrix transposed = sparse.transpose();
    cout << "\nTransposed Sparse Matrix:" << endl;
    transposed.displaySparse();

    return 0;
}
