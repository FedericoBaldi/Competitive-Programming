#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int possibleDices(vector<int> dices);

int main(){
    int cases;
    cin >> cases;
    for (int index = 0; index < cases; index++){
        int nDice;
        cin >> nDice;
        vector<int> dices;
        for (int indexP = 0; indexP < nDice; indexP++){
            int dice;
            cin >> dice;
            dices.push_back(dice);
        }
        cout << "Case #" << index + 1 << ": ";
        int maxStraight = possibleDices(dices);
        cout << maxStraight;
        cout << endl;
    }
    return 0;
}

int possibleDices(vector<int> dices){
    int maxStraight = 0;
    sort(dices.begin(), dices.end());
    for (int index = 0; index < dices.size(); index++){
        if (dices[index] > maxStraight){
            maxStraight++;
        }
    }
    return maxStraight;
}