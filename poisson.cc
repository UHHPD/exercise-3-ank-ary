#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double poisson(double mu, int k) {
    double P = pow(mu, k)*exp(-mu)/tgamma(k+1);
    return 0;
}

int main() {
    using namespace std;
    vector<int> zaehler(11);
    
    ifstream fin("datensumme.txt");
    ofstream fout("hist.txt");
    ofstream fout1("histpoi.txt");

    int n_i;
    double mu = 3.11538;

    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        zaehler[n_i] +=1;
    }
    fin.close();

    for(unsigned int k = 0 ; k < zaehler.size() ; ++k){
        cout << k << ":" << zaehler[k] << endl;
        fout << k << " " << zaehler[k] << endl;
        fout1 << k << " " << zaehler[k] << zaehler[k]*poisson(mu,k) << endl;
    }

}