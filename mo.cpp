
#include<bits/stdc++.h>
using namespace std;
#define EPS 10e-6
void addition(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3);
void subtraction(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3);
void transpose(vector<vector<double>> &mat1,vector<vector<double>> &mat2);
void multiplication(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3);
double determinant(vector<vector<double>> &mat);
double max_off_diagonal_value(vector<vector<double>> mat1,int &inI,int &inJ);
bool is_diagonal(vector<vector<double>> &mat1);
double off_diagonal_sq_sum(vector<vector<double>> mat);
void make_identity(vector<vector<double>> &mat,int size);
void matrix_copy(vector<vector<double>> mat1,vector<vector<double>> &mat2);
void sub_matrix(vector<vector<double>> mat,int I,int J,vector<vector<double>> &sub_mat);
void inverse_matrix(vector<vector<double>> mat,vector<vector<double>> &in_mat);
void print_matrix(vector<vector<double>> mat);
void print_aug_matrix(vector<vector<double>> mat,vector<vector<double>> aug_mat);
double euclidean_norm_col(vector<vector<double>> mat,int col);
void sigma_matrix(vector<double> eigen_value,vector<vector<double>> &mat,int row,int col);
void swap_rows(vector<vector<double>> &mat,int I,int J);
// int main(){
//     int m1,m2,n1,n2,inI,inJ;
//     vector<vector<double>> mat1,mat2,mat3;
//     cout<<"Enter the dimension of the 1st matrix: ";
//     cin>>m1>>n1;
//     // cout<<"Enter the dimension of the 2nd matrix: ";
//     // cin>>m2>>n2;
//     int i,j;
//     mat1.resize(m1,vector<double>(n1));

//     //mat2.resize(m2,vector<double>(n2));


//     printf("Enter matrix-1:\n");
//     for(i=0;i<m1;i++){
//         for(j=0;j<n1;j++){
//             cin>>mat1[i][j];
//         }
//     }
//     vector<vector<double>> mat_cpy,iden;
//     matrix_copy(mat1,mat_cpy);
//     cout<<"After copying:"<<endl;
//     for(i=0;i<mat_cpy.size();i++){
//         for(j=0;j<mat_cpy[i].size();j++){
//             cout<<mat_cpy[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     make_identity(iden,3);

//     cout<<endl;
//     cout<<"Identical:"<<endl;
//     for(i=0;i<iden.size();i++){
//         for(j=0;j<iden[i].size();j++){
//             cout<<iden[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     vector<int> maxIn;
// //     transpose(mat1,mat2);
// //     multiplication(mat1,mat2,mat3);
// //     printf("Enter matrix-2:\n");
// //     for(i=0;i<m2;i++){
// //         for(j=0;j<n2;j++){
// //             cin>>mat2[i][j];
// //         }
// //     }

// //     addition(mat1,mat2,mat3);
// //     subtraction(mat1,mat2,mat3);
// //     transpose(mat1,mat2);
// //     cout<<"After subtracition:\n";
// //     for(i=0;i<m1;i++){
// //         for(j=0;j<n1;j++){
// //             cout<<mat3[i][j]<<" ";
// //         }
// //         cout<<endl;
// //     }
// //     multiplication(mat1,mat2,mat3);
// //     cout<<"After multiplication:"<<endl;
// //     for(i=0;i<mat3.size();i++){
// //         for(j=0;j<mat3[i].size();j++){
// //             cout<<mat3[i][j]<<" ";
// //         }
// //         cout<<endl;
// //     }
// //    cout<<determinant(mat1)<<endl;
// //     if(is_diagonal(mat1)){
// //         cout<<"Yes"<<endl;
// //     }
// //     else{
// //         cout<<"No"<<endl;
// //    }

//    cout<<max_off_diagonal_value(mat1,inI,inJ)<<endl;
//    cout<<inI<<" "<<inJ<<endl;
//    cout<<off_diagonal_sq_sum(mat_cpy)<<endl;
//    return 0;

// }
void addition(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3)
{
    mat3.resize(mat1.size(),vector<double>(mat1[0].size()));
    for(int i=0; i<mat1.size(); i++)
    {
        for(int j=0; j<mat1[i].size(); j++)
        {
            mat3[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
}
void subtraction(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3)
{
    mat3.resize(mat1.size(),vector<double>(mat1[0].size()));
    for(int i=0; i<mat1.size(); i++)
    {
        for(int j=0; j<mat1[i].size(); j++)
        {
            mat3[i][j]=mat1[i][j]-mat2[i][j];
        }
    }
}
void transpose(vector<vector<double>> &mat1,vector<vector<double>> &mat2)
{
    mat2.resize(mat1[0].size(),vector<double>(mat1.size()));
    for(int i=0; i<mat1.size(); i++)
    {
        for(int j=0; j<mat1[i].size(); j++)
        {
            mat2[j][i]=mat1[i][j];
        }
    }
}

void multiplication(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3)
{
    int i,j,k;
    if(mat1[0].size()!=mat2.size())
    {
        cout<<"Dimension doesn't match for multiplication!"<<endl;
        return;
    }
    mat3.resize(mat1.size(),vector<double> (mat2[0].size()));
    for(i=0; i<mat1.size(); i++)
    {
        for(j=0; j<mat2[0].size(); j++)
        {
            for(k=0; k<mat2.size(); k++)
            {
                mat3[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    for(i=0; i<mat3.size(); i++)
    {
        for(j=0; j<mat3.size(); j++)
        {
            if(fabs(mat3[i][j])<EPS)
            {
                mat3[i][j]=0;
            }
        }
    }
}

double determinant(vector<vector<double>> &mat)
{
    int i,j,k,n=mat.size();
    if(!n)
    {
        return 0;
    }
    if(n==1)
    {
        return mat[0][0];
    }
    if(n==2)
    {
        return mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
    }
    double det=0;
    for(i=0; i<n; i++)
    {
        vector<vector<double>> sub_mat;
        // sub_mat.resize(n-1,vector<double>(n-1));
        // int sub_row=0,sub_col;
        // for(j=1;j<n;j++){
        //     sub_col=0;
        //     for(k=0;k<n;k++){
        //         if(k!=i){
        //             sub_mat[sub_row][sub_col]=mat[j][k];
        //             sub_col++;
        //         }
        //     }
        //     sub_row++;
        // }
        sub_matrix(mat,0,i,sub_mat);
        det+=mat[0][i]*pow(-1,i)*determinant(sub_mat);
    }
    return det;
}

double max_off_diagonal_value(vector<vector<double>> mat1,int &inI,int &inJ)
{
    int i,j;
    double max=0;
    inI=0;
    inJ=1;
    for(i=0; i<mat1.size(); i++)
    {
        for(j=0; j<mat1[i].size(); j++)
        {
            if(i!=j&&fabs(mat1[i][j])>fabs(max))
            {
                max=mat1[i][j];
                //    cout<<i<<j<<endl;
                inI=i;
                inJ=j;
            }
        }
    }
    return max;
}

bool is_diagonal(vector<vector<double>> &mat1)
{
    int i,j;
    for(i=0; i<mat1.size(); i++)
    {
        for(j=0; j<mat1.size(); j++)
        {
            if(i!=j)
            {
                if(mat1[i][j])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

double off_diagonal_sq_sum(vector<vector<double>> mat)
{
    double sq;
    int i,j;
    for(i=0; i<mat.size(); i++)
    {
        for(j=0; j<mat[i].size(); j++)
        {
            if(i!=j)
            {
                sq+=pow(mat[i][j],2);
            }
        }
    }
    return sq;
}

void make_identity(vector<vector<double>> &mat,int size)
{
    mat.resize(size,vector<double>(size));
    int i,j;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(i!=j)
            {
                mat[i][j]=0;
            }
            else
            {
                mat[i][j]=1;
            }
        }
    }
}

void matrix_copy(vector<vector<double>> mat1,vector<vector<double>> &mat2)
{
    mat2.resize(mat1.size(),vector<double>(mat1[0].size()));
    int i,j;
    for(i=0; i<mat1.size(); i++)
    {
        for(j=0; j<mat1[i].size(); j++)
        {
            mat2[i][j]=mat1[i][j];
        }
    }
}
void sub_matrix(vector<vector<double>> mat,int I,int J,vector<vector<double>> &sub_mat)
{
    sub_mat.resize(mat.size()-1,vector<double>(mat.size()-1));
    int i,j,k,sub_row=0,sub_col;
    for(i=0; i<mat.size(); i++)
    {
        if(i!=I)
        {
            sub_col=0;
            for(j=0; j<mat[i].size(); j++)
            {
                if(j!=J)
                {
                    sub_mat[sub_row][sub_col++]=mat[i][j];
                }
            }
            sub_row++;
        }
    }
}
void inverse_matrix(vector<vector<double>> mat,vector<vector<double>> &in_mat)
{
    int i,j,k,n=mat.size(),cur,pre,p;
    double m;
    make_identity(in_mat,n);
    for(i=0; i<n-1; i++)
    {
        for(p=i; p<n; p++)
        {
            if(!(fabs(mat[p][i])<EPS))
            {
                break;
            }
        }
        if(p==n)
        {
            cout<<"Solution doessn't exist!"<<endl;
            return;
        }
        if(fabs(mat[i][i])<EPS)
        {
            vector<double> temp,in_temp;
            temp.resize(n);
            in_temp.resize(n);
            for(j=0; j<n; j++)
            {
                temp[j]=mat[i][j];
                in_temp[j]=in_mat[i][j];
            }
            for(j=0; j<n; j++)
            {
                in_mat[i][j]=in_mat[p][j];
            }
            for(j=0; j<n; j++)
            {
                in_mat[p][j]=in_temp[j];
            }
        }
        for(j=i+1; j<n; j++)
        {
            m=mat[j][i]/mat[i][i];
            for(k=0; k<n; k++)
            {
                mat[j][k]-=m*mat[i][k];
                if(fabs(mat[j][k])<EPS)
                {
                    mat[j][k]=0;
                }
                in_mat[j][k]-=m*in_mat[i][k];
                if(fabs(in_mat[j][k])<EPS)
                {
                    in_mat[j][k]=0;
                }
            }
        }
    }
    if(fabs(mat[n-1][n-1])<EPS)
    {
        cout<<"Solution doesn't exist"<<endl;
        return;
    }
    for(i=n-1; i>0; i--)
    {
        for(j=i-1; j>=0; j--)
        {
            m=mat[j][i]/mat[i][i];
            for(k=0; k<n; k++)
            {
                mat[j][k]-=m*mat[i][k];
                if(fabs(mat[j][k])<EPS)
                {
                    mat[j][k]=0;
                }
                in_mat[j][k]-=m*in_mat[i][k];
                if(fabs(in_mat[j][k])<EPS)
                {
                    in_mat[j][k]=0;
                }
            }
        }
    }
    for(i=0; i<n; i++)
    {
        m=mat[i][i];
        for(j=0; j<n; j++)
        {
            mat[j][i]/=m;
            in_mat[i][j]/=m;
        }
    }
}
void print_matrix(vector<vector<double>> mat)
{
    for(int i=0; i<mat.size(); i++)
    {
        for(int j=0; j<mat[i].size(); j++)
        {
            printf("%.3lf\t",mat[i][j]);
        }
        cout<<endl;
    }
}
void print_aug_matrix(vector<vector<double>> mat,vector<vector<double>> aug_mat)
{
    int i,j;
    for(i=0; i<mat.size(); i++)
    {
        for(j=0; j<mat[i].size(); j++)
        {
            printf("%.3lf\t",mat[i][j]);
        }
        cout<<"| ";
        for(j=0; j<aug_mat[i].size(); j++)
        {
            printf("%.3lf\t",aug_mat[i][j]);
        }
        cout<<endl;
    }
    cout<<endl;
}
double euclidean_norm_col(vector<vector<double>> mat,int col)
{
    double norm=0;
    int i,j;
    for(i=0; i<mat.size(); i++)
    {
        norm+=mat[i][col]*mat[i][col];
    }
    return sqrt(norm);
}
void sigma_matrix(vector<double> eigen_value,vector<vector<double>> &mat,int row,int col)
{
    int i,j;
    mat.resize(row,vector<double>(col));
    for(i=0; i<mat.size(); i++)
    {
        for(j=0; j<mat[i].size(); j++)
        {
            mat[i][j]=0;
        }
    }
    for(i=0; i<mat.size(); i++)
    {
        mat[i][i]=sqrt(eigen_value[i]);
    }
}
void swap_rows(vector<vector<double>> &mat,int I,int J)
{
    vector<double> temp;
    temp.resize(mat[0].size());
    int i,j;
    for(i=0; i<mat[I].size(); i++)
    {
        temp[i]=mat[I][i];
    }
    for(i=0; i<mat[I].size(); i++)
    {
        mat[I][i]=mat[J][i];
    }
    for(i=0; i<mat[I].size(); i++)
    {
        mat[J][i]=temp[i];
    }
}
