
#include<bits/stdc++.h>
#include "svd1.cpp"
using namespace std;
vector<vector<double>>Sigma_R,Sigma_G,Sigma_B, U_R,U_G,U_B,V_R,V_G,V_B, t_sigma_R,t_sigma_G, t_sigma_B,t_V_R,
 t_V_G, t_V_B, vrt, vgt, vbt, m1,m2,m3,m4,m5,m6,R1,G1,B1;
vector<vector<double>>leftCol(vector<vector<double>>&mtx, int k){
    int row=mtx.size();
    int col=k;
    vector<vector<double>>mtx1(row,vector<double>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            mtx1[i][j]=mtx[i][j];
            cout<<mtx1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return mtx1;
}

//vector<vector<vector<double>>>color;

vector<vector<double>>RED1(){
//vector<vector<double>>Sigma_R,Sigma_G,Sigma_B, U_R,U_G,U_B,V_R,V_G,V_B, t_sigma_R,t_sigma_G, t_sigma_B,t_V_R,
// t_V_G, t_V_B, vrt, vgt, vbt, m1,m2,m3,m4,m5,m6,R1,G1,B1;
    Sigma_R=sigma1(3,3);
    U_R=left1(3,3);
    V_R=right1(3,3);

    Sigma_G=sigma1(3,3);
    U_G=left1(3,3);
    V_G=right1(3,3);

    Sigma_B=sigma1(3,3);
    U_B=left1(3,3);
    V_B=right1(3,3);
int width=3, height=3;
double compressionRatio = 0.9;

// Calculate the total energy (sum of squared singular values)
double totalEnergy_R = 0.0;
double totalEnergy_G = 0.0;
double totalEnergy_B = 0.0;

// Iterate over the singular values and accumulate the squared values
for (int i = 0; i < min(height, width); ++i) {
    totalEnergy_R += Sigma_R[i][i] * Sigma_R[i][i];
    totalEnergy_G += Sigma_G[i][i] * Sigma_G[i][i];
    totalEnergy_B += Sigma_B[i][i] * Sigma_B[i][i];
}

// Calculate the target energy based on the compression ratio
double targetEnergy_R = compressionRatio * totalEnergy_R;
double targetEnergy_G = compressionRatio * totalEnergy_G;
double targetEnergy_B = compressionRatio * totalEnergy_B;

// Initialize counters
int k_R = 0;
int k_G = 0;
int k_B = 0;
double currentEnergy_R = 0.0;
double currentEnergy_G = 0.0;
double currentEnergy_B = 0.0;

// Find the number of singular values (k) to keep
while (currentEnergy_R < targetEnergy_R && k_R < min(height, width)) {
    currentEnergy_R += Sigma_R[k_R][k_R] * Sigma_R[k_R][k_R];
    ++k_R;
}

while (currentEnergy_G < targetEnergy_G && k_G < min(height, width)) {
    currentEnergy_G += Sigma_G[k_G][k_G] * Sigma_G[k_G][k_G] ;
    ++k_G;
}

while (currentEnergy_B < targetEnergy_B && k_B < min(height, width)) {
    currentEnergy_B += Sigma_B[k_B][k_B] * Sigma_B[k_B][k_B];
    ++k_B;
}

cout<<k_R<<" : "<<k_G<<" : "<<k_B<<endl;
cout<<" t sigma_R: "<<endl;
t_sigma_R=leftCol(Sigma_R,k_R);
cout<<" t sigma_G: "<<endl;
t_sigma_G=leftCol(Sigma_G,k_G);
cout<<" t sigma_B: "<<endl;
t_sigma_B=leftCol(Sigma_B,k_B);


//void transpose(vector<vector<double>> &mat1,vector<vector<double>> &mat2);
//void multiplication(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3);


cout<<" t V_R: "<<endl;
t_V_R=leftCol(V_R,k_R);
transpose(t_V_R, vrt);
cout<<" t V_G: "<<endl;
t_V_G=leftCol(V_G,k_G);
transpose(t_V_G, vgt);
cout<<" t V_B: "<<endl;
t_V_B=leftCol(V_B,k_B);
transpose(t_V_B, vbt);

//void print_matrix(vector<vector<double>> mat);

multiplication(U_R, t_sigma_R,m1);
multiplication(m1,vrt,R1);
cout<<"Red: "<<endl;
print_matrix(R1);
multiplication(U_G, t_sigma_G,m2);
multiplication(m2,vgt,G1);
cout<<"Green: "<<endl;
print_matrix(G1);
multiplication(U_B, t_sigma_B,m3);
multiplication(m3,vbt,B1);
cout<<"Blue: "<<endl;
print_matrix(B1);

return R1;
}

vector<vector<double>>GREEN1(){
    return G1;

}

vector<vector<double>>BLUE1(){
  return B1;
}
