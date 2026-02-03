#include <iostream>
#include <vector>
#include <iomanip> 

// Helper function to print the matrix
void printMatrix(const std::vector<std::vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int pixel : row)
        {
            // setw(4) keeps the numbers lined up in columns
            std::cout << std::setw(4) << pixel;
        }
        std::cout << std::endl;
    }
}

// [ 0,  1,  2,  3] --> [12,  8,  4, 0]
// [ 4,  5,  6,  7]     [13,  9,  5, 1]
// [ 8,  9, 10, 11]     [14, 10   6  2]
// [12, 13, 14, 15]     [15, 11,  7, 3]

void rotate(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    for (int layer = 0; layer < n / 2; ++layer) {
        int first = layer;
        int last = n - 1 - layer;

        for (int i = first; i < last; i++) {
            int offset = i - first;

            // Save the top row
            int top = matrix[first][i];
            
            // Rotate the left -> top 
            matrix[first][i] = matrix[last - offset][first];

            // Rotate bottom -> left
            matrix[last - offset][first] = matrix[last][last - offset];

            // Rotate right -> bottom
            matrix[last][last - offset] = matrix[i][last];

            // Rotate top -> right
            matrix[i][last] = top;
        }
    }
}


int main()
{
    // Initialize a 4x4 matrix
    // Think of these as pixel values
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    std::cout << "Original Matrix:" << std::endl;
    printMatrix(matrix);
    std::cout << "--------------------" << std::endl;

    // Call your rotation logic
    rotate(matrix);

    std::cout << "Rotated 90 Degrees (In-Place):" << std::endl;
    printMatrix(matrix);

    return 0;
}