// TS:O(n) SC:O(1)
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int nPayers(vector<int> deliciousness);

int main(){
    int cases;
    cin >> cases;
    for (int index = 0; index < cases; index++){
        int nPancakes;
        cin >> nPancakes;
        vector<int> deliciousness;
        for (int indexP = 0; indexP < nPancakes; indexP++){
            int del;
            cin >> del;
            deliciousness.push_back(del);
        }
        cout << "Case #" << index + 1 << ": ";
        int payers = nPayers(deliciousness);
        cout << payers;
        cout << endl;
    }
    return 0;
}

int nPayers(vector<int> deliciousness){
    int curDel = 0;
    int nPay = 0;
    int size = deliciousness.size();
    for (int index = 0; index < size; index++){
        if (deliciousness[0] < deliciousness[deliciousness.size()-1]){
            if (deliciousness[0] >= curDel){
                curDel = deliciousness[0];
                nPay++;
            }
            deliciousness.erase(deliciousness.begin());
        }
        else{
            if (deliciousness[deliciousness.size()-1] >= curDel){
                curDel = deliciousness[deliciousness.size()-1];
                nPay++;
            }
            deliciousness.pop_back();
        }
    }
    return nPay;
}