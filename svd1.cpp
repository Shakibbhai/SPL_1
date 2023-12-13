#include<bits/stdc++.h>
#include "mo.cpp"
#define upper 0
#define lower 20
using namespace std;
int iter;
void eigenvalue(vector<vector<double>> A,vector<double> &eigen_values,vector<vector<double>> &eigen_vector);
void normalized_eigen_vector(vector<vector<double>> &eigen_vector);
void inverse_sigma(vector<vector<double>> sigma_mat,vector<vector<double>> &i_sigma_mat);
void pseudo_inverse(vector<vector<double>> right_sing,vector<vector<double>> sing,vector<vector<double>> left_sing,vector<vector<double>> &mat);
vector<vector<double>> eigen_vector;


vector<vector<double>>sigma1(int m,int n)
{

    int i,j,k;
    vector<vector<double>> mat,pseudo_in;

    //cout<<"Enter number of rows and columns: ";
    //cin>>m>>n;
    mat.resize(m,vector<double>(n));
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            cin >> mat[i][j];
        }
    }
    /*cout<<endl;
    cout<<"the generized matrix:"<<endl;
    for(i=0;i<mat.size();i++){
        for(j=0;j<mat[i].size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }*/
    vector<vector<double>> A,t_mat;
    vector<double> eigen_values;
    eigen_values.resize(n);
    transpose(mat,t_mat);
    cout<<endl;
    //cout<<"Transpose:"<<endl;
    //print_matrix(t_mat);
    multiplication(t_mat,mat,A);
    // cout<<"\nThe symmetric matrix:"<<endl;
    // for(i=0;i<A.size();i++){
    //     for(j=0;j<A[i].size();j++){
    //         cout<<A[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    make_identity(eigen_vector,n);
    eigenvalue(A,eigen_values,eigen_vector);
    // for(i=0;i<eigen_values.size();i++){
    //     printf("Eigenvectors for eigenvalue %.3lf:\n",eigen_values[i]);
    //     for(j=0;j<eigen_vector.size();j++){
    //         printf("%.3lf ",eigen_vector[j][i]);
    //     }
    //     cout<<"\n"<<endl;
    // }

    vector<vector<double>> t_eigen_vector;
    transpose(eigen_vector,t_eigen_vector);
    vector<double> sorted_eigen_values;
    sorted_eigen_values.resize(eigen_values.size());
    for(i=eigen_values.size()-1; i>=0; i--)
    {
        for(j=i-1; j>=0; j--)
        {
            if(eigen_values[i]>eigen_values[j])
            {
                double temp;
                temp=eigen_values[i];
                eigen_values[i]=eigen_values[j];
                eigen_values[j]=temp;
                swap_rows(t_eigen_vector,i,j);
            }
        }
    }
    transpose(t_eigen_vector,eigen_vector);
    cout<<endl;
    //cout<<"Orthogonal Matirx:\n";
    //print_matrix(A);
    normalized_eigen_vector(eigen_vector);
    // for(i=0;i<eigen_values.size();i++){
    //     printf("Eigenvectors for eigenvalue %.3lf:\n",eigen_values[i]);
    //     for(j=0;j<eigen_vector.size();j++){
    //         printf("%.3lf ",eigen_vector[j][i]);
    //     }
    //     cout<<"\n"<<endl;
    // }
    // cout<<endl;
    vector<vector<double>> sigma_mat;
    sigma_mat.resize(m,vector<double>(n));
    // sigma_matrix(sorted_eigen_values,sigma_mat,m,n);
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j)
            {
                sigma_mat[i][j]=sqrt(eigen_values[i]);
            }
            else
            {
                sigma_mat[i][j]=0;
            }
        }
    }
//  cout<<"Right singular matrix:"<<endl;
    // print_matrix(eigen_vector);
    vector<vector<double>> i_sigma_mat,temp,left_sing,ans,right_sing,temp1;
    inverse_sigma(sigma_mat,i_sigma_mat);
    cout<<endl;
    //  print_matrix(i_sigma_mat);
    multiplication(mat,eigen_vector,temp);
    multiplication(temp,i_sigma_mat,left_sing);
    cout<<"\nLeft singular matrix:"<<endl;

    print_matrix(left_sing);
    cout<<endl;

    cout<<"\nSigma matrix:"<<endl;
    print_matrix(sigma_mat);
    cout<<endl;

    cout<<"Right singular matrix:"<<endl;
    transpose(eigen_vector,right_sing);
    print_matrix(right_sing);

    //multiplication(left_sing,sigma_mat,temp1);
    //multiplication(temp1,right_sing,ans);
    cout<<endl;
    //print_matrix(temp);
    //cout<<"Answer:"<<endl;
    //print_matrix(ans);
    //pseudo_inverse(right_sing,sigma_mat,left_sing,pseudo_in);
    //cout<<"Pseudo Inverse:"<<endl;
    //print_matrix(pseudo_in);




    return sigma_mat;
}

vector<vector<double>>left1(int m, int n)
{

    int i,j,k;
    vector<vector<double>> mat,pseudo_in;

    //out<<"Enter number of rows and columns: ";
    //cin>>m>>n;
    mat.resize(m,vector<double>(n));
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            cin >> mat[i][j];
        }
    }
    /*cout<<endl;
    cout<<"the generized matrix:"<<endl;
    for(i=0;i<mat.size();i++){
        for(j=0;j<mat[i].size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }*/
    vector<vector<double>> A,t_mat;
    vector<double> eigen_values;
    eigen_values.resize(n);
    transpose(mat,t_mat);
    cout<<endl;
    //cout<<"Transpose:"<<endl;
    //print_matrix(t_mat);
    multiplication(t_mat,mat,A);
    // cout<<"\nThe symmetric matrix:"<<endl;
    // for(i=0;i<A.size();i++){
    //     for(j=0;j<A[i].size();j++){
    //         cout<<A[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    make_identity(eigen_vector,n);
    eigenvalue(A,eigen_values,eigen_vector);
    // for(i=0;i<eigen_values.size();i++){
    //     printf("Eigenvectors for eigenvalue %.3lf:\n",eigen_values[i]);
    //     for(j=0;j<eigen_vector.size();j++){
    //         printf("%.3lf ",eigen_vector[j][i]);
    //     }
    //     cout<<"\n"<<endl;
    // }

    vector<vector<double>> t_eigen_vector;
    transpose(eigen_vector,t_eigen_vector);
    vector<double> sorted_eigen_values;
    sorted_eigen_values.resize(eigen_values.size());
    for(i=eigen_values.size()-1; i>=0; i--)
    {
        for(j=i-1; j>=0; j--)
        {
            if(eigen_values[i]>eigen_values[j])
            {
                double temp;
                temp=eigen_values[i];
                eigen_values[i]=eigen_values[j];
                eigen_values[j]=temp;
                swap_rows(t_eigen_vector,i,j);
            }
        }
    }
    transpose(t_eigen_vector,eigen_vector);
    cout<<endl;
    //cout<<"Orthogonal Matirx:\n";
    //print_matrix(A);
    normalized_eigen_vector(eigen_vector);
    // for(i=0;i<eigen_values.size();i++){
    //     printf("Eigenvectors for eigenvalue %.3lf:\n",eigen_values[i]);
    //     for(j=0;j<eigen_vector.size();j++){
    //         printf("%.3lf ",eigen_vector[j][i]);
    //     }
    //     cout<<"\n"<<endl;
    // }
    // cout<<endl;
    vector<vector<double>> sigma_mat;
    sigma_mat.resize(m,vector<double>(n));
    // sigma_matrix(sorted_eigen_values,sigma_mat,m,n);
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j)
            {
                sigma_mat[i][j]=sqrt(eigen_values[i]);
            }
            else
            {
                sigma_mat[i][j]=0;
            }
        }
    }
//  cout<<"Right singular matrix:"<<endl;
    // print_matrix(eigen_vector);
    vector<vector<double>> i_sigma_mat,temp,left_sing,ans,right_sing,temp1;
    inverse_sigma(sigma_mat,i_sigma_mat);
    cout<<endl;
    //  print_matrix(i_sigma_mat);
    multiplication(mat,eigen_vector,temp);
    multiplication(temp,i_sigma_mat,left_sing);

    cout<<"\nLeft singular matrix:"<<endl;
    print_matrix(left_sing);
    cout<<endl;

    cout<<"\nSigma matrix:"<<endl;
    print_matrix(sigma_mat);
    cout<<endl;

    cout<<"Right singular matrix:"<<endl;
    transpose(eigen_vector,right_sing);
    print_matrix(right_sing);
    //multiplication(left_sing,sigma_mat,temp1);
    //multiplication(temp1,right_sing,ans);
    cout<<endl;
    //print_matrix(temp);
    //cout<<"Answer:"<<endl;
    //print_matrix(ans);
    //pseudo_inverse(right_sing,sigma_mat,left_sing,pseudo_in);
    //cout<<"Pseudo Inverse:"<<endl;
    //print_matrix(pseudo_in);




    return left_sing;
}

vector<vector<double>>right1(int m,int n)
{

    int i,j,k;
    vector<vector<double>> mat,pseudo_in;

    //cout<<"Enter number of rows and columns: ";
    //cin>>m>>n;
    mat.resize(m,vector<double>(n));
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            cin >> mat[i][j];
        }
    }
    /*cout<<endl;
    cout<<"the generized matrix:"<<endl;
    for(i=0;i<mat.size();i++){
        for(j=0;j<mat[i].size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }*/
    vector<vector<double>> A,t_mat;
    vector<double> eigen_values;
    eigen_values.resize(n);
    transpose(mat,t_mat);
    cout<<endl;
    //cout<<"Transpose:"<<endl;
    //print_matrix(t_mat);
    multiplication(t_mat,mat,A);
    // cout<<"\nThe symmetric matrix:"<<endl;
    // for(i=0;i<A.size();i++){
    //     for(j=0;j<A[i].size();j++){
    //         cout<<A[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    make_identity(eigen_vector,n);
    eigenvalue(A,eigen_values,eigen_vector);
    // for(i=0;i<eigen_values.size();i++){
    //     printf("Eigenvectors for eigenvalue %.3lf:\n",eigen_values[i]);
    //     for(j=0;j<eigen_vector.size();j++){
    //         printf("%.3lf ",eigen_vector[j][i]);
    //     }
    //     cout<<"\n"<<endl;
    // }

    vector<vector<double>> t_eigen_vector;

    transpose(eigen_vector,t_eigen_vector);

    vector<double> sorted_eigen_values;
    sorted_eigen_values.resize(eigen_values.size());
    for(i=eigen_values.size()-1; i>=0; i--)
    {
        for(j=i-1; j>=0; j--)
        {
            if(eigen_values[i]>eigen_values[j])
            {
                double temp;
                temp=eigen_values[i];
                eigen_values[i]=eigen_values[j];
                eigen_values[j]=temp;
                swap_rows(t_eigen_vector,i,j);
            }
        }
    }
    transpose(t_eigen_vector,eigen_vector);
    cout<<endl;
    //cout<<"Orthogonal Matirx:\n";
    //print_matrix(A);
    normalized_eigen_vector(eigen_vector);
    // for(i=0;i<eigen_values.size();i++){
    //     printf("Eigenvectors for eigenvalue %.3lf:\n",eigen_values[i]);
    //     for(j=0;j<eigen_vector.size();j++){
    //         printf("%.3lf ",eigen_vector[j][i]);
    //     }
    //     cout<<"\n"<<endl;
    // }
    // cout<<endl;
    vector<vector<double>> sigma_mat;

    sigma_mat.resize(m,vector<double>(n));
    // sigma_matrix(sorted_eigen_values,sigma_mat,m,n);
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j)
            {
                sigma_mat[i][j]=sqrt(eigen_values[i]);
            }
            else
            {
                sigma_mat[i][j]=0;
            }
        }
    }
//  cout<<"Right singular matrix:"<<endl;
    // print_matrix(eigen_vector);
    vector<vector<double>> i_sigma_mat,temp,left_sing,ans,right_sing,temp1;
    inverse_sigma(sigma_mat,i_sigma_mat);
    cout<<endl;
    //  print_matrix(i_sigma_mat);
    multiplication(mat,eigen_vector,temp);
    multiplication(temp,i_sigma_mat,left_sing);

    cout<<"\nLeft singular matrix:"<<endl;
    print_matrix(left_sing);
    cout<<endl;

    cout<<"\nSigma matrix:"<<endl;
    print_matrix(sigma_mat);
    cout<<endl;
    cout<<"Right singular matrix:"<<endl;
    transpose(eigen_vector,right_sing);
    print_matrix(right_sing);
    //multiplication(left_sing,sigma_mat,temp1);
    //multiplication(temp1,right_sing,ans);
    cout<<endl;
    //print_matrix(temp);
    //cout<<"Answer:"<<endl;
    //print_matrix(ans);
    //pseudo_inverse(right_sing,sigma_mat,left_sing,pseudo_in);
    //cout<<"Pseudo Inverse:"<<endl;
    //print_matrix(pseudo_in);




    return right_sing;
}




void eigenvalue(vector<vector<double>> A,vector<double> &eigen_values,vector<vector<double>> &eigen_vector)
{
    int inI,inJ,i,j;
    double theta;
    double max=max_off_diagonal_value(A,inI,inJ);
    vector<vector<double>> S,t_S,A_new,temp,temp_S;
    make_identity(S,A.size());
    if(A[inI][inI]==A[inJ][inJ])
    {
        theta=0.5*asin(1);
        if(A[inI][inI]<0)
        {
            theta=-theta;
        }
    }
    else
    {
        theta=0.5*atan((2*A[inI][inJ])/fabs(A[inI][inI]-A[inJ][inJ]));
    }
    S[inI][inJ]=-sin(theta);
    S[inJ][inI]=sin(theta);
    S[inI][inI]=cos(theta);
    S[inJ][inJ]=cos(theta);
    transpose(S,t_S);
    multiplication(t_S,A,temp);
    multiplication(temp,S,A_new);
    multiplication(eigen_vector,S,temp_S); /* */
    matrix_copy(temp_S,eigen_vector);
    if(!is_diagonal(A_new))
    {
        eigenvalue(A_new,eigen_values,eigen_vector);
    }
    else
    {
        for(i=0; i<A_new.size(); i++)
        {
            if(fabs(A_new[i][i])<10e-3)
            {
                A_new[i][i]=0;
            }
            eigen_values[i]=A_new[i][i];
        }
        for(j=0; j<eigen_vector.size(); j++)
        {
            for(i=0; i<eigen_vector.size(); i++)
            {
                eigen_vector[i][j]/=eigen_vector[eigen_vector.size()-1][j];
            }
        }

    }
}
void normalized_eigen_vector(vector<vector<double>> &eigen_vector)
{
    int i,j,k;
    double norm;
    for(i=0; i<eigen_vector.size(); i++)
    {
        norm=euclidean_norm_col(eigen_vector,i);
        for(j=0; j<eigen_vector.size(); j++)
        {
            eigen_vector[j][i]/=norm;
        }
    }
}
void inverse_sigma(vector<vector<double>> sigma_mat,vector<vector<double>> &i_sigma_mat)
{
    int i,j;
    i_sigma_mat.resize(sigma_mat[0].size(),vector<double>(sigma_mat.size()));
    if(sigma_mat.size()>sigma_mat[0].size())
    {
        transpose(sigma_mat,i_sigma_mat);
        for(i=0; i<i_sigma_mat.size(); i++)
        {
            i_sigma_mat[i][i]=1/i_sigma_mat[i][i];
        }
    }
    else
    {
        for(i=0; i<sigma_mat.size(); i++)
        {
            if(i<sigma_mat.size())
            {
                i_sigma_mat[i][i]=1/sigma_mat[i][i];
            }
        }
    }
}

void pseudo_inverse(vector<vector<double>> right_sing,vector<vector<double>> sing,vector<vector<double>> left_sing,vector<vector<double>> &mat)
{
    vector<vector<double>> in_sing,t_left_sing,temp,t_right_sing;
    for(int i=0; i<sing.size()&&i<sing[i].size(); i++)
    {
        sing[i][i]=1/sing[i][i];
    }
    transpose(right_sing,t_right_sing);
    transpose(sing,in_sing);
    transpose(left_sing,t_left_sing);
    multiplication(t_right_sing,in_sing,temp);
    multiplication(temp,t_left_sing,mat);
}
