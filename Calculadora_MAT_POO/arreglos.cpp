#include<iostream>
const int MAX=100; //Màximo tamaño de nuestro arreglo.

void leerMatriz(int matriz[MAX][MAX],int filas, int columnas){
    std::cout<<"Introduzca los elementos de la matriz ("<<filas<<"x"<<columnas<<"):\n";
    for (int i=0;i<filas;++i){
        for (int j=0;j<columnas;++j){
            std::cout<<"Elemento A["<<i<<"]["<<j<<"]=";
            std::cin>>matriz[i][j];
        }
    }

}

void mostrarMatriz(int matriz[MAX][MAX],int filas, int columnas){
    std::cout<<"La matriz es: \n";
    for (int i=0;i<filas;++i){
        for (int j=0;j<columnas;++j){
            std::cout<<matriz[i][j]<<"\t";
        }
        std::cout<<std::endl;
    }

}

void sumaMatrices(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int filas, int columnas){
    for (int i=0;i<filas;++i){
        for (int j=0;j<columnas;++j){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}

void restaMatrices(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int filas, int columnas){
    for (int i=0;i<filas;++i){
        for (int j=0;j<columnas;++j){
            C[i][j]=A[i][j]-B[i][j];
        }
    }
}

void productoMatrices(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int filasA, int columnasA,int filasB,int columnasB){
    for (int i=0;i<filasA;++i){
        for (int j=0;j<columnasB;++j){
            C[i][j]=0;
                for(int k=0;k<columnasA;++k){
                    C[i][j]+=A[i][k]*A[k][j];
                }
        }
    }
}



int main(){
    int filasA, columnasA,filasB, columnasB;
    int A[MAX][MAX],B[MAX][MAX],C[MAX][MAX];

    std::cout<<"Introduzca el nùmero de filas y columnas de la matriz A:"<<std::endl;
    std::cin>> filasA >> columnasA;

    std::cout<<"Introduzca el nùmero de filas y columnas de la matriz B:"<<std::endl;
    std::cin>> filasB >> columnasB;

    leerMatriz(A,filasA,columnasA);
    leerMatriz(B,filasB,columnasB);

    //Operaciones
    if (filasA==filasB && columnasA==columnasB){
        //Suma de matrices
        sumaMatrices(A,B,C,filasA,columnasA);
        mostrarMatriz(C,filasA,columnasA);
        //Resta de matrices
        restaMatrices(A,B,C,filasA,columnasA);
        mostrarMatriz(C,filasA,columnasA);
    }else{
        std::cout<<"Las matrices no son del mismo orden."<<std::endl;
    }

    if(columnasA==filasB){
        //Multiplicaciòn de matrices
        productoMatrices(A,B,C,filasA,columnasA,filasB,columnasB);
        std::cout<<"La multiplicaciòn de matrices es:\n";
        mostrarMatriz(C,filasA,columnasB);
    }else{
        std::cout<<"las matrices no se pueden multiplicar estudieee..\n";
    }
    return 0;
}       