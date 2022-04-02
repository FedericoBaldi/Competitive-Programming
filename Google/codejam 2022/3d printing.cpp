#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

vector<int> checkPrinters(vector<vector<int>> printers);

int main(){
    int cases;
    cin >> cases;
    for (int index = 0; index < cases; index++){
        vector<vector<int>> printers(3); // 3 printers
        for (int indexP = 0; indexP < 3; indexP++){
            int C, M, Y, K;
            cin >> C;
            printers[indexP].push_back(C);
            cin >> M;
            printers[indexP].push_back(M);
            cin >> Y;
            printers[indexP].push_back(Y);
            cin >> K;
            printers[indexP].push_back(K);
        }
        cout << "Case #" << index + 1 << ": ";
        vector<int> color = checkPrinters(printers);
        if (color.empty()){
            cout << "IMPOSSIBLE";
        }
        else{
            for (int indexC = 0; indexC < color.size(); indexC++){
                cout << color[indexC] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

vector<int> checkPrinters(vector<vector<int>> printers){
    vector<int> color(4, 0);
    int colorSum = 0;
    int index = 0;
    while (colorSum < 1e6 && index < 4){ // 4 colors
        int minColor = min(min(printers[0][index], printers[1][index]), printers[2][index]);
        if (colorSum + minColor > 1e6){
            minColor = 1e6 - colorSum;
        }
        colorSum += minColor;
        color[index] = minColor;
        index++;
    }
    if (colorSum < 1e6){
        color.clear();
    }
    return color;
}