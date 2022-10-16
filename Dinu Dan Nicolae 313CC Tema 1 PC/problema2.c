#include <stdio.h>
#include <math.h>

typedef struct pion//declaram un tip de date struct care va retine pentru fiecare pion coordonatele x,y si daca are sau nu pereche 
{
    int x,y,per; //declaram campurile: x - randul pionului, y - coloana pionului, per - daca pionul are sau nu pereche
}pion;

int DS(struct pion v[],int k,int n,int m) //cautam numarul de perechi pentru un singur pion pe directia dreapta sus
{
    int i=v[k].x,j=v[k].y,nr=0; 
    i--;
    j++;
    while (i>=0 && j<m) //cat timp pozitia in care cautam se afla in matrice
    {
        for(k=0;k<n;k++)
            if(v[k].x==i && v[k].y==j) //verificam daca exista vreun pion in pozitia in care am ajuns
            {
                nr++; //incrementam numarul de perechi gasite
                v[k].per=1; //retinem ca pionul are macar o perechi
            }
        i--; //incrementam sau decrementam valoare lui i si j in functie de directia in care cautam
        j++;  
    }
    return nr; //returnam numarul de perechi gasite
}

int DJ(struct pion v[],int k,int n,int m) //cautam numarul de perechi pentru un singur pion pe directia dreapta jos
{
    int i=v[k].x,j=v[k].y,nr=0;;
    i++;
    j++;
    while (i<m && j<m) //cat timp pozitia in care cautam se afla in matrice
    {
        for(k=0;k<n;k++)
            if(v[k].x==i && v[k].y==j) //verificam daca exista vreun pion in pozitia in care am ajuns
            {
                nr++; //incrementam numarul de perechi gasite
                v[k].per=1; //retinem ca pionul are macar o pereche
            }
                
        i++; //incrementam sau decrementam valoare lui i si j in functie de directia in care cautam
        j++;  
    }
    return nr; //returnam numarul de perechi gasite
}

int perechi(struct pion v[],int k,int n,int m) //calculam numarul total de perechi ale unui pion
{
    int nr=0;
    nr+=DS(v,k,n,m); //adunam numarul de perechi gasite pe directiile dreapta sus si dreapta jos
    nr+=DJ(v,k,n,m);
    return nr;
}

int CDS(struct pion v[],int k,int n,int m,int i,int j) //verificam daca exista vreo pereche pe directia dreapta sus incepand cu o pozitie anume
{
    int ck=k;
    i--;
    j++;
    while (i>=0 && j<m) 
    {
        for(k=0;k<n;k++)
            if(ck!=k && v[k].x==i && v[k].y==j) //verificam daca exista vreun pion in pozitia curenta
                return 1; //daca exista returnam 1, semnificand faptul ca am gasit o pereche
        i--; 
        j++;  
    }
    return 0;
}

int CDJ(struct pion v[],int k,int n,int m,int i,int j) //verificam daca exista vreo pereche pe directia dreapta jos incepand cu o pozitie anume
{
    int ck=k;
    i++;
    j++;
    while (i<m && j<m)
    {
        for(k=0;k<n;k++)
            if(ck!=k && v[k].x==i && v[k].y==j) //verificam daca exista vreun pion in pozitia curenta
                return 1; //daca exista returnam 1, semnificand faptul ca am gasit o pereche
        i++; 
        j++;  
    }
    return 0;
}

int CSS(struct pion v[],int k,int n,int m,int i,int j) //verificam daca exista vreo pereche pe directia stanga sus incepand cu o pozitie anume
{
    int ck=k;
    i--;
    j--;
    while (i>=0 && j>=0)
    {
        for(k=0;k<n;k++)
            if(ck!=k && v[k].x==i && v[k].y==j) //verificam daca exista vreun pion in pozitia curenta
                return 1; //daca exista returnam 1, semnificand faptul ca am gasit o pereche
        i--;
        j--;  
    }
    return 0;
}

int CSJ(struct pion v[],int k,int n,int m,int i,int j) //verificam daca exista vreo pereche pe directia stanga jos incepand cu o pozitie anume
{
    int ck=k;
    i++;
    j--;
    while (i<m && j>=0)
    {
        for(k=0;k<n;k++)
            if(ck!=k && v[k].x==i && v[k].y==j) //verificam daca exista vreun pion in pozitia curenta
                return 1; //daca exista returnam 1, semnificand faptul ca am gasit o perechie
        i++;
        j--;  
    }
    return 0;
}

int checkmoves(struct pion v[],int k,int n, int m) //verificam toate pozitiile in care se poate muta un pion
{
    int i=v[k].x,j=v[k].y,d,ok=1;
    int ci=i,cj=j; //retinem coordonatele initiale ale pionului pentru care cautam
    i--; //vom cauta in directia dreapta sus
    j++; 
    while(i>=0 && j<m && ok) //cat timp pozitia in care cautam este inca in matrice si nu am gasit alt pion
    {
        for(d=0;d<n;d++)
            if(v[d].x==i && v[d].y==j) //verificam daca in pozitia in care cautam exista deja un pion
                ok=0; //daca exista nu mai cautam in directia asta
        if(ok && !CDS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j) && !CSS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j)) //daca in poizita in care am ajuns nu exista deja un pion si nu exista perechi pe diagonalele acesteia 
           return 1; //am gasit o mutare posibila si returnam 1
        i--; //incrementam sau decrementam valoare lui i si j in functie de directia in care cautam
        j++;
    }
    i=ci; //i revine la valoarea initiala
    j=cj; //j revine la valoarea initiala
    i++; //vom cauta in directia dreapta jos
    j++; 
    ok=1; //resetam valoarea variabilei ok
    while(i<m && j<m && ok)
    {
        for(d=0;d<n;d++)
            if(v[d].x==i && v[d].y==j)
                ok=0;
        if(ok && !CDS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j) && !CSS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j))
            return 1;
        i++;
        j++;
    }
    i=ci;
    j=cj;
    i--; //cautam in directia stanga sus
    j--;
    ok=1;
    while(i>=0 && j>=0 && ok)
    {
        for(d=0;d<n;d++)
            if(v[d].x==i && v[d].y==j)
                ok=0;
        if(ok && !CDS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j) && !CSS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j))
            return 1;
        i--;
        j--;
    }
    i=ci;
    j=cj;
    i++; //cautam in directia stanga jos
    j--;
    ok=1;
    while(i<m && j>=0 && ok)
    {
        for(d=0;d<n;d++)
            if(v[d].x==i && v[d].y==j)
                ok=0;
        if(ok && !CDS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j) && !CSS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j))
            return 1;
        i++;
        j--;
    }
    i=ci;
    j=cj;
    i++; //cautam in jos
    ok=1;
    while(i<m && ok) 
    {
        for(d=0;d<n;d++)
            if(v[d].x==i && v[d].y==j)
                ok=0;
        if(ok && !CDS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j) && !CSS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j))
            return 1;
        i++;
    }
    i=ci;
    j=cj;
    i--; //cautam in sus
    ok=1;
    while(i>=0 && ok) 
    {
        for(d=0;d<n;d++)
            if(v[d].x==i && v[d].y==j)
                ok=0;
        if(ok && !CDS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j) && !CSS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j))
            return 1;
        i--;
    }
    i=ci;
    j=cj;
    j++; //cautam la dreapta
    ok=1;
    while(j<m && ok) 
    {
        for(d=0;d<n;d++)
            if(v[d].x==i && v[d].y==j)
                ok=0;
        if(ok && !CDS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j) && !CSS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j))
            return 1;
        j++;
    }
    i=ci;
    j=cj;
    j--; //cautam la stanga
    ok=1;
    while(j>=0 && ok) 
    {
        for(d=0;d<n;d++)
            if(v[d].x==i && v[d].y==j)
                ok=0;
        if(ok && !CDS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j) && !CSS(v,k,n,m,i,j) && !CDJ(v,k,n,m,i,j))
            return 1;
        j--;
    }
    return 0;
}

int main(void)
{
    int M,N,i,nr_per=0,ok;
    struct pion p[201];
    scanf("%d\n%d", &M,&N);
    for(i=0;i<N;i++)
        p[i].per=0; //initializeaza campul per cu 0
    for(i=0;i<N;i++)
        scanf("%d %d", &p[i].x,&p[i].y);
    for(i=0;i<N;i++)
        nr_per+=perechi(p,i,N,M); //calculam numarul de perechi pentru pionul i si il adunam la numarul de perechi total
    printf("%d\n",nr_per);
    if(nr_per==1) //daca cerinta 2 este aplicabila 
    {
        ok=0; //variabila in care retinem 1 daca exista o mutare posibila si 0 daca nu
        for(i=0;i<N && ok==0;i++)
        {
            if(p[i].per && checkmoves(p,i,N,M)) //daca pionul are pereche si exista o mutare posibila 
            {
                printf("DA\n"); //afisam "DA" si retinem in ok ca am gasit o mutare posibila
                ok=1;
            }
        }
        if(!ok) //daca inca nu am gasit o mutare posibila
            printf("NU\n"); //afisam "NU"
    }
    else 
        printf("NU\n"); //cerita 2 nu e aplicabila deci afisam "NU"
    return 0;
}