#include <iostream>
#include <vector>
#include <ctime>
#include <math.h>
#include <time.h>       /* time */


using namespace std;
const vector<vector<int>> G = {
        {0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0}
};
const vector<vector<int>> S = {
        {1, 0, 0, 1},
        {0, 1, 0, 1},
        {0, 1, 0, 0},
        {0, 0, 1, 1}
};

// генерируемая матрица перестановки nxn P
vector<vector<int>> gen_for_p(int n) {

    int count = n;
    vector<int> positions;

    for (int i = 0; i < count; ++i) {
        positions.push_back(i);
    }

    vector<vector<int>> newMatrix;

    for (int i = 0; i < n; ++i) {
        int position = rand() % positions.size();
        int newPosition = positions[position];
        positions.erase(positions.begin() + position);
        vector<int> row;
        for (int j = 0; j < n; ++j) {
            if (j == newPosition) {
                row.push_back(1);
            } else {
                row.push_back(0);
            }
        }
        newMatrix.push_back(row);
    }

    return newMatrix;
}

// вычисляется матрица SGP
vector<vector<int>> matrix_mul(vector<vector<int>> first, vector<vector<int>> second) {
    int countColumnsFirst = first[0].size();
    int countRowsSecond = second.size();
    if (countColumnsFirst != countRowsSecond) {
        throw ("invalid arguments");
    }

    int countRowsFirst = first.size();
    int countColumnsSecond = second[0].size();

    vector<vector<int>> result;

    for (int i = 0; i < countRowsFirst; ++i) {
        vector<int> newColumn;
        for (int j = 0; j < countColumnsSecond; ++j) {
            int sum = 0;
            for (int k = 0; k < countColumnsFirst; ++k) {
                sum += (first[i][k] * second[k][j]);
            }
            sum %= 2;
            newColumn.push_back(sum);
        }
        result.push_back(newColumn);
    }

    return result;
}

vector<vector<int>> T(vector<vector<int>> matrix) {
    vector<vector<int>> new_matrix = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    vector<int> tmp;
    for (int i = 0; i < matrix.size(); ++i) {
        tmp = matrix[i];
        for (int j = 0; j < matrix.size(); ++j) {
            for (int k = 0; k < matrix.size(); ++k) {
                if (i == k)
                    new_matrix[j][k] = matrix[i][j];
            }
        }
    }
    return new_matrix;
}

vector<vector<int>> T2(vector<vector<int>> matrix) {
    vector<vector<int>> new_matrix = {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}};
    vector<int> tmp;
    for (int i = 0; i < matrix.size(); ++i) {
        tmp = matrix[i];
        for (int j = 0; j < matrix[0].size(); ++j) {
            for (int k = 0; k < matrix.size(); ++k) {
                if (i == k)
                    new_matrix[j][k] = matrix[i][j];
            }
        }
    }
    return new_matrix;
}

vector<vector<int>> T3(vector<vector<int>> matrix) {
    vector<vector<int>> new_matrix = {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}};
    vector<int> tmp;
    for (int i = 0; i < matrix.size(); ++i) {
        tmp = matrix[i];
        for (int j = 0; j < matrix[0].size(); ++j) {
            for (int k = 0; k < matrix.size(); ++k) {
                if (i == k)
                    new_matrix[j][k] = matrix[i][j];
            }
        }
    }
    return new_matrix;
}

double Determinant(vector<vector<int>> a, int n) {
    const double EPS = 1E-9;
    double det = 1;
    for (int i = 0; i < n; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j)
            if (abs(a[j][i]) > abs(a[k][i]))
                k = j;
        if (abs(a[k][i]) < EPS) {
            det = 0;
            break;
        }
        swap(a[i], a[k]);
        if (i != k)
            det = -det;
        det *= a[i][i];
        for (int j = i + 1; j < n; ++j)
            a[i][j] /= a[i][i];
        for (int j = 0; j < n; ++j)
            if (j != i && abs(a[j][i]) > EPS)
                for (int k = i + 1; k < n; ++k)
                    a[j][k] -= a[i][k] * a[j][i];
    }
    return det;
}

vector<vector<int>> inverseMatrix(vector<vector<int>> a) {
    int d = abs(Determinant(a, a[0].size()));
    d = 1 / d;
    a = T(a);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            a[i][j] = a[i][j] * d;
        }
    }
    return a;
}

vector<vector<int>> inverseMatrix2(vector<vector<int>> a) {
    vector<vector<int>> b = {
            {1, -1, 1,  0},
            {0, 0,  1,  0},
            {0, -1, 1,  1},
            {0, 1,  -1, 0}};
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            a[i][j] = b[i][j];
        }
    }
    return a;
}

// не больше t единиц, кол-во элементов = n
vector<vector<int>> getRandomZ(int t, int n) {
    vector<int> randomZ;
    int countOnes = 0; // количество единиц.
    for (int i = 0; i < n; ++i) {
        int r = rand() % 2;
        if (r == 0) {
            randomZ.push_back(0);
        } else {
            randomZ.push_back(1);
            if (++countOnes == 2) break;
        }
    }
    for (int i = randomZ.size(); i < n; ++i) {
        randomZ.push_back(0);
    }
    vector<vector<int>> result;
    result.push_back(randomZ);
    return result;
}

vector<vector<vector<int>>> getBlock(string &message, int k) {
    vector<vector<vector<int>>> resultBlocks;
    int count = 0;
    vector<vector<int>> block;
    vector<int> subBlock;
    int countToAdd = 0;
    if (message.size() % k != 0)
        countToAdd = k - message.size() % k;
    cout << "message before append: " << message << endl;
    message.append(countToAdd, '0');
    cout << "message after append: " << message << endl;

    for (char c : message) {
        if (c == '0') {
            subBlock.push_back(0);
            ++count;
        } else if (c == '1') {
            subBlock.push_back(1);
            ++count;
        }
        if (count == k) {
            block.push_back(subBlock);
            subBlock.clear();
            resultBlocks.push_back(block);
            block.clear();
            count = 0;
            continue;
        }
    }
    return resultBlocks;
}

void printMatrix(const vector<vector<int>> &matrix) {
    for (const vector<int> &row : matrix) {
        for (int item : row) {
            cout << item << " ";
        }
        cout << endl;
    }
}


int main(int argc, const char *argv[]) {

    srand(time(NULL));

    string message;

    cout << "Enter sequence : " << endl;
    cin >> message;
    vector<vector<vector<int>>> blocks = getBlock(message, 4);
    for (const auto &matrix : blocks) {
        cout << "{";
        for (const auto &subMatrix : matrix) {
            cout << "{";
            for (auto count : subMatrix) {
                cout << count;
            }
            cout << "}";
        }
        cout << "} ";
    }
    cout << endl;

    vector<vector<int>> P = gen_for_p(12);
    vector<vector<int>> SG = matrix_mul(S, G);
    vector<vector<int>> SGP = matrix_mul(SG, P);

    int count = 0;
    for (const vector<vector<int>> &block : blocks) {
        // шифрование
        vector<vector<int>> randomZ = getRandomZ(2, 12);
        cout << "random Z matrix :" << endl;
        printMatrix(randomZ);
        vector<vector<int>> c = matrix_mul(block, SGP);

        for (int i = 0; i < c.size(); ++i) {
            for (int j = 0; j < c[i].size(); ++j)
                c[i][j] = (c[i][j] + randomZ[i][j]) % 2;
        }

        // вывод зашифрованного блока...

        // дешифрование
        vector<vector<int>> P_ = {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
        P_ = inverseMatrix(P);

        vector<vector<int>> c_ = matrix_mul(c, P_);

        vector<vector<int>> c2_ = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
        for (int i = 0; i < c_.size(); i++) {
            for (int j = 0; j < 12; j++) {
                if (c_[i][j] == 0) {
                    c2_[i][j] = c_[i][j] + randomZ[i][j];
                } else {
                    c2_[i][j] = c_[i][j];
                }
            }
        }

        vector<vector<int>> Gt = T2(G);
        Gt = matrix_mul(c2_, Gt);
        vector<vector<int>> S_ = {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}};
        S_ = inverseMatrix2(S);
        // m=m`S^-1
        vector<vector<int>> m_ = matrix_mul(Gt, S_);

        cout << "result block number " << count++ << endl;
        printMatrix(m_);

    }


    // k = 4;n = 12;t = 2;
/*
    vector<vector<int>> P = gen_for_p(12);
    vector<vector<int>> SG = matrix_mul(S, G);
    vector<vector<int>> SGP = matrix_mul(SG, P);
    // m сообщение в виде двоичных символов
    vector<vector<int>> m = {{1, 0, 1, 0}};
    // генерирует случайный вектор z
    vector<vector<int>> z = {{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int t = 2; // вес Хемминга t
    // вычислется шифротекст c=mG+z
    vector<vector<int>> c = matrix_mul(m, SGP);
    for (int i = 0; i < c.size(); ++i) {
        for (int j = 0; j < c[i].size(); ++j)
            c[i][j] = (c[i][j] + z[i][j]) % 2;
    }
    // вычисление обратной матрицы P
    vector<vector<int>> P_ = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    P_ = inverseMatrix(P);

    vector<vector<int>> c_ = matrix_mul(c, P_);
    vector<vector<int>> c2_ = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    for (int i = 0; i < c_.size(); i++) {
        for (int j = 0; j < 12; j++) {
            if (c_[i][j] == 0) {
                c2_[i][j] = c_[i][j] + z[i][j];
            } else {
                c2_[i][j] = c_[i][j];
            }
        }
    }

    vector<vector<int>> Gt = T2(G);
    Gt = matrix_mul(c2_, Gt);
    vector<vector<int>> S_ = {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}};
    S_ = inverseMatrix2(S);
    // m=m`S^-1
    vector<vector<int>> m_ = matrix_mul(Gt, S_);

    do {
        int i = 0;
        printf("McEliece Cryptosystem\n\nSystem parameters: k=4, n=12, t=2\n\n1 Key generation\n2 Encryption\n3 Decryption\n4 Exit\n");
        scanf_s("%d", &i);
        switch (i) {
            case 1: {
                system("cls");
                printf("Key generation process\n\n");
                printf("Matrix G k*n:\n");
                for (auto now : G) {
                    for (auto t : now) {
                        cout << t << " ";
                    }
                    cout << endl;
                }
                printf("\n");
                printf("Matrix S k*k:\n");
                for (auto now : S) {
                    for (auto t : now) {
                        cout << t << " ";
                    }
                    cout << endl;
                }
                printf("\n");
                printf("Matrix P n*n:\n");
                for (auto now : P) {
                    for (auto t : now) {
                        cout << t << " ";
                    }
                    cout << endl;
                }
                printf("\nMatrix SGP k*n:\n");
                for (auto now : SGP) {
                    for (auto t : now) {
                        cout << t << " ";
                    }
                    cout << endl;
                }
                printf("\n(SGP,t) - public key\n((S,G,P) - private key\n\n\n");
                getchar();
                getchar();
                system("cls");
                break;
            }

            case 2: {
                system("cls");
                printf("Encryption process\n\n");

                printf("Message: ");
                for (auto now : m) {
                    for (auto t : now) {
                        cout << t << " ";
                    }
                    cout << endl;
                }
                printf("Binary error vector: ");
                for (auto now : z) {
                    for (auto t : now) {
                        cout << t << " ";
                    }
                    cout << endl;
                }
                printf("Encrypted message: ");
                for (auto now : c) {
                    for (auto t : now) {
                        cout << t << " ";
                    }
                    cout << endl;
                }
                getchar();
                getchar();
                system("cls");
                break;
            }
            case 3:
                system("cls");
                printf("Decryption process\n\n");
                printf("\nMatrix cP^-1: ");
                for (auto now : c_) {
                    for (auto t : now) {
                        cout << t << " ";
                    }
                    cout << endl;
                }
                printf("\nMatrix mSG: ");
                for (auto now : c2_) {
                    for (auto t : now) {
                        cout << t << " ";
                    }
                    cout << endl;
                }
                printf("\nMatrix mS: ");
                for (auto now : Gt) {
                    for (auto t : now) {
                        cout << t << " ";
                    }
                    cout << endl;
                }
                printf("\nDecrypted message m: ");
                for (auto now : m_) {
                    for (auto t : now) {
                        cout << t << " ";
                    }
                    cout << endl;
                }
                getchar();
                getchar();
                system("cls");
                break;

            case 4:

                system("cls");
                printf("\nExit\n");
                getchar();
                getchar();
                return 0;

            default:
                printf("\nError\n");
                getchar();
                getchar();
                system("cls");
                break;
        }
    } while (true);
*/
/*
    getchar();
    getchar();*/
    return 0;
}
