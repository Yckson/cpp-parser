#include <bits/stdc++.h>



using namespace std;


int main (int argc, char* argv[]){

    vector<int> vetor = {2, 1, 5, 6, 9, 10};
    //Este é um comentário de teste

    cout << "[ ";
    for (int c : vetor){
        cout << c << ' ';
    }

    cout << "]" << endl;

    sort(vetor.begin(), vetor.end());

    cout << "[ ";
    for (int c : vetor){
        cout << c << ' ';
    }
    cout << "]" << endl;


    for (int i = 0; i < argc; i++) cout << "Teste" << endl;
    int tmp = 5;
    while (tmp--) cout << "Teste" << endl;

    if (tmp < argc) cout << "x" << endl;
    else cout << "y" << endl;


    return 0;
}
