#include <stdio.h>
#include <string.h>

void dec_to_bin (int n, char *s) //transformam un numar din baza 10 in baza 2
{
    int i;
    for(i=0;n>0;i++)
    {
        s[7-i]=(char)(n%2+48); 
        n/=2;
    }
}

int bin_to_dec(char s[]) //transformam un numar din baza 2 in baza 10
{
    int b=1,n=0,r,i=7;
    while(i>=0)
    {
        r=(int)(s[i]-48);
        n+=r*b;
        b=b*2;
        i--;
    }
    return n;
}

void trans_mat(int A[][8], int AT[][8]) //calculam matricea transpusa
{
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++) 
            AT[i][j]=A[j][i]; //matricea transpusa va avea liniile matricei A in locul coloanelor
}

void mult_mat(int A[][8], int B[][8], int C[][8]) //calculam inmultirea a doua matrici
{
    int i,j,k;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            for(k=0;k<8;k++)
            C[i][j]=C[i][j]||(A[i][k]&&B[k][j]); //folosind logica booleana, "+" va deveni "||"(sau), iar "*" va deveni "&&"(si)
        }
    }
}

int sum_X_0(int m[][8]) //calculam scorul unei matrici date ca parametru
{
    int i,j,scor=0,st,nr;
    //calculam punctajul pentru al doilea cadran
    nr=0;
    for(i=0;i<4;i++) //calculam scorul pentru cele 4 linii
    {
        st=0;
        for(j=0;j<4;j++)
            if(m[i][j]==1)
                st++; //numaram cate valori avem pe linie 
        if(st==4) //daca avem 4 valori de 1 incrementam scorul
            nr++;
    }
    scor+=nr;
    nr=0;
    for(j=0;j<4;j++) //calculam scorul pentru cele 4 coloane
    {
        st=0;
        for(i=0;i<4;i++)
            if(m[i][j]==1)
                st++; //numaram cate valori avem pe coloane
        if(st==4) //daca avem 4 valori de 1 incrementam scorul
            nr++;
    }
    scor+=nr;
    nr=0;
    st=0;
    for(i=0;i<4;i++) //calculam scorul pentru diagonala principala
        if(m[i][i]==1)
            st++; //numaram cate valori de 1 avem
    if(st==4) //daca avem 4 valori de 1 incrementam scorul
        nr++;
    scor+=nr;
    nr=0;
    st=0;
    for(i=0;i<4;i++) //calculam scorul pentru diagonala secundara
        if(m[i][3-i]==1)
            st++; //numaram cate valori de 1 avem
    if(st==4) //daca avem 4 valori de 1 incrementam scorul
        nr++;
    scor+=nr;
    //calculam punctajul pentru primul cadran
    nr=0;
    for(i=0;i<4;i++) //calculam scorul pentru cele 4 linii
    {
        st=0;
        for(j=4;j<8;j++)
            if(m[i][j]==1)
                st++;
        if(st==4)
            nr++;
    }
    scor+=nr;
    nr=0;
    for(j=4;j<8;j++) //calculam scorul pentru cele 4 coloane
    {
        st=0;
        for(i=0;i<4;i++)
            if(m[i][j]==1)
                st++;
        if(st==4)
            nr++;
    }
    scor+=nr;
    nr=0;
    st=0;
    for(i=0;i<4;i++) //calculam scorul pentru diagonala principala
        if(m[i][i+4]==1)
            st++;
    if(st==4)
        nr++;
    scor+=nr;
    nr=0;
    st=0;
    for(i=0;i<4;i++) //calculam scorul pentru diagonala secundare
        if(m[i][7-i]==1)
            st++;
    if(st==4)
        nr++;
    scor+=nr;
    //calculam punctajul pentru al treilea cadran
    nr=0;
    for(i=4;i<8;i++) //calculam scorul pentru cele 4 linii
    {
        st=0;
        for(j=0;j<4;j++)
            if(m[i][j]==1)
                st++;
        if(st==4)
            nr++;
    }
    scor+=nr;
    nr=0;
    for(j=0;j<4;j++) //calculam scorul pentru cele 4 coloane
    {
        st=0;
        for(i=4;i<8;i++)
            if(m[i][j]==1)
                st++;
        if(st==4)
            nr++;
    }
    scor+=nr;
    nr=0;
    st=0;
    for(i=4;i<8;i++) //calculam scorul pentru diagonala principala
        if(m[i][i-4]==1)
            st++;
    if(st==4)
        nr++;
    scor+=nr;
    nr=0;
    st=0;
    for(i=4;i<8;i++) //calculam scorul pentru diagonala secundara
        if(m[i][7-i]==1)
            st++;
    if(st==4)
        nr++;
    scor+=nr;
    //calculam punctajul pentru al patrulea cadran
    nr=0;
    for(i=4;i<8;i++) //calculam scorul pentru cele 4 linii
    {
        st=0;
        for(j=4;j<8;j++)
            if(m[i][j]==1)
                st++;
        if(st==4)
            nr++;
    }
    scor+=nr;
    nr=0;
    for(j=4;j<8;j++) //calculam scorul pentru cele 4 coloane
    {
        st=0;
        for(i=4;i<8;i++)
            if(m[i][j]==1)
                st++;
        if(st==4)
            nr++;
    }
    scor+=nr;
    nr=0;
    st=0;
    for(i=4;i<8;i++) //calculam scorul pentru diagonala principala
        if(m[i][i]==1)
            st++;
    if(st==4)
        nr++;
    scor+=nr;
    nr=0;
    st=0;
    for(i=4;i<8;i++) //calculam scorul pentru diagonala secundara
        if(m[i][11-i]==1)
            st++;
    if(st==4)
        nr++;
    scor+=nr;
    return scor; //returnam punctajul total obtinut pentru matricea data ca parametru
}



int main (void)
{
    int A[8][8],AT[8][8],A2[8][8],v[8]={0},i,j,X[8][8];
    char s[9];
    for(i=0;i<8;i++)
        scanf("%d", &v[i]);
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
        {
            A2[i][j]=0; //initializam matricile A2 si X cu 0
            X[i][j]=0; 
        }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++) 
            s[j]='0'; //golim sirul de caractere pentru a retine cu succes numarul n in format binar
        dec_to_bin(v[i],s); //transformam numere din baza 10 in baza 2 si le dispunem pe cate o linie din matrice
        for(j=0;j<8;j++)
            A[i][j]=(int)(s[j]-48); 
    }
    trans_mat(A,AT); //apelam functia de transpunere a unei matrici
    mult_mat(A,AT,X); //apelam functia de inmultire a doua matrici pentru a afla A*AT
    mult_mat(A,A,A2); //apelam functia de inmultire a doua matrici pentru a afla A*A
    int scor1=sum_X_0(X); //apelam functia de calcul a scorului pentru fiecare matrice
    int scor2=sum_X_0(A2);
    int scor3=sum_X_0(A);
    //afisam matricea care are scorul cel mai mare cu randurile convertite la decimal
    if(scor3 >= scor1 && scor3 >= scor2) 
            for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                    s[j]=(char)(A[i][j]+48);
                printf("%d\n", bin_to_dec(s));
            }
    else if(scor1>=scor2 && scor1 >= scor3)
        for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                    s[j]=(char)(X[i][j]+48);
                printf("%d\n", bin_to_dec(s));
            }
    else if(scor2 >= scor1 && scor2 >= scor3)
    {
        for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                    s[j]=(char)(A2[i][j]+48);
                printf("%d\n", bin_to_dec(s));
            }
    }
    return 0;
}