#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;


double poisson(double mu, int k) {
    double P = pow(mu, k)*exp(-mu)/tgamma(k+1);
    return P;
}

double prob(double mu,vector<int> daten) {
    double like = 1;

    for(int k : daten) {
        like *= poisson(mu,k);
    }
    return like; 
}

int main() {
    using namespace std;
    ofstream fout("likelihood.txt");
    ofstream fout1("nll.txt");
    ofstream fout2("deltanll.txt");

    double mu = 3.11538;
    double like;

    vector<int> daten;

    ifstream fin("datensumme.txt");
    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        daten.push_back(n_i);

    }
    fin.close();

    like = prob(mu, daten);

    cout << like << endl;


    double mu_loop = 3;

    while( mu_loop < 3.25) {
        fout << mu_loop << " " << prob(mu_loop,daten) << endl;
        fout1 << mu_loop << " " << -2*log(prob(mu_loop,daten)) << endl;
        fout2 << mu_loop << " " << -2*log(prob(mu_loop,daten)) + 2*log(prob(3.11538,daten)) << endl;

        mu_loop += 0.01;
    }

    //cout << sqrt(3.11538)/sqrt(234) << endl; // Uncertainty on sample mean
}
