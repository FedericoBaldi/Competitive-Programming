#include <iostream>
using namespace std;
void printCard(int row, int col);

int main(){
    int cases;
    cin >> cases;
    for (int index = 0; index < cases; index++){
        int row,col;
        cin >> row;
        cin >> col;
        cout << "Case #" << index + 1 << ":" << endl;
        printCard(row, col);
    }
    return 0;    
}

void printCard(int row, int col){
    for (int indexR = 0; indexR < row * 2 + 1; indexR++){
        for (int indexC = 0; indexC < col * 2 + 1; indexC++){
            if (indexR < 2 && indexC < 2){
                cout << ".";
            }
            else if (indexC % 2 == 0){
                if (indexR % 2 == 0){
                    cout << "+";
                }
                else{
                    cout << "|";
                }
            }
            else{
                if (indexR % 2 == 0){
                    cout << "-";
                }
                else{
                    cout << ".";
                }
            }
        }
        cout << endl;
    }
}