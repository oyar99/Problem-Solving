#include <iostream>
#include <vector>

#pragma GCC optmize("03")


using namespace std;

const int SUDOKU_GRID_SIZE = 9;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int N;
    cin >> N;

    for (int k = 0; k < N;++k) {

        int matrix [SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE];

        for (int i = 0; i < SUDOKU_GRID_SIZE;++i) {
            for (int j = 0; j < SUDOKU_GRID_SIZE;++j) {
                int p; cin >> p;
                matrix[i][j] = p;
            }
        }

        bool maybe = true;
        for (int i = 0; i < SUDOKU_GRID_SIZE;++i) {
            vector<int> row(SUDOKU_GRID_SIZE);
            for (int j = 0; j < SUDOKU_GRID_SIZE;++j) {
                if (row[matrix[i][j] - 1] >= 1) { 
                    maybe = false;
                    break;
                }
                row[matrix[i][j] - 1] += 1;
            }

            for (int j = 0; j < SUDOKU_GRID_SIZE;++j) {
                if(row[j] == 0) {
                    maybe = false;
                    break;
                }
            }


            if (!maybe) break;
        }




        if (maybe) {

            for (int i = 0; i < SUDOKU_GRID_SIZE;++i) {
                vector<int> col(SUDOKU_GRID_SIZE);
                for (int j = 0; j < SUDOKU_GRID_SIZE;++j) {
                    if (col[matrix[j][i] - 1] >= 1) { 
                        maybe = false;
                        break;
                    }
                    col[matrix[j][i] - 1] += 1;
                }

                for (int j = 0; j < SUDOKU_GRID_SIZE;++j) {
                    if(col[j] == 0) {
                        maybe = false;
                        break;
                    }
                }


                if (!maybe) break;
            }


            if (maybe) {

                for (int m = 0; m < SUDOKU_GRID_SIZE; m+=3) {
                    for (int n = 0; n < SUDOKU_GRID_SIZE; n+=3) {
                        vector<int> sub(SUDOKU_GRID_SIZE);
                        for (int i = 0; i < 3;++i) {
                            for (int j = 0; j < 3;++j) {
                                if (sub[matrix[i+m][n+j] - 1] >= 1) {
                                    maybe = false;
                                    break;
                                }

                                sub[matrix[i+m][n+j] - 1] += 1; 
                            }

                            if (!maybe) break;
                        }

                        for (int i = 0; i < SUDOKU_GRID_SIZE; ++i) {
                            if (sub[i] == 0) {
                                maybe = false;
                                break;
                            }
                        }

                        if (!maybe) break;
                    }

                    if (!maybe) break;
                }
            }
        }

        cout << "Instancia " << k+1 << endl;
        if (!maybe) cout << "NAO" << endl;
        else cout << "SIM" << endl;

        cout << endl;

    }

    return 0;
}
