#include <stdio.h>
#include <string.h>

typedef struct perechi //definim tipul de date "perechi"
{
    char cuv1[51]; //retinem primul cuvant al perechii
    char cuv2[51]; //retinem al doilea cuvant al perechii
    double grad; //retinem gradul perechii
}perechi;

void swap(struct perechi *p1, struct perechi *p2) //facem o functie pentru interschimbarea valorilor a doua perechi
{
    struct perechi aux; //declaram valoarea auxiliara pentru a realiza interschimbarea
    aux.grad=p1->grad;  //interschimbam grad cu grad, cuv1 cu cuv1 si cuv2 cu cuv2
    strcpy(aux.cuv1,p1->cuv1);
    strcpy(aux.cuv2,p1->cuv2);
    p1->grad=p2->grad;
    strcpy(p1->cuv1,p2->cuv1);
    strcpy(p1->cuv2,p2->cuv2);
    p2->grad=aux.grad;
    strcpy(p2->cuv1,aux.cuv1);
    strcpy(p2->cuv2,aux.cuv2);
}

void sort_grad(struct perechi p[], int N) //facem o functie pentru a sorta perechiile descrescator dupa grad
{
    int i,ok;
    do //sortam perechiile in fuctie de grad, folosind un "do while" alaturi de un contor "ok"
    {
        ok=1;
        for(i=0;i<N-1;i++)
            if(p[i].grad<p[i+1].grad) 
            {
                swap(&p[i],&p[i+1]);
                ok=0;
            }
                
    }while(!ok);
}

void sort_lexi(struct perechi p[], int N) //facem o functie pentru a sorta perechiile descrescator lexicografic
{
    int i,ok;
    do
    {
        ok=1;
        for(i=0;i<N-1;i++)
            if(p[i].grad==p[i+1].grad && strcmp(p[i].cuv1,p[i+1].cuv1)<0) //daca au acelasi grad si sunt in ordine lexicografica gresita, interschimbam perechiile
            {
                swap(&p[i],&p[i+1]);
                ok=0;
            }
                
    }while(!ok);
}

int is_anagram(char *s1, char *s2) //verificam daca doua siruri de caractere primite ca parametru sunt anagrame
{
    int v1[27]={0},v2[27]={0},i; //declaram doi vectori de frecventa care vor contoriza aparitiile caraterelor in siruri
    if(strlen(s1)!=strlen(s2)) //verificam egalitatea de lungime dintre siruri pentru conditia de a fi anagrame
        return 0;
    else 
    {
        for(i=0;i<strlen(s1);i++) 
            v1[(int)s1[i]-97]++; //incrementam valoarea pozitiei caracterului din alfabet in vectorul de frecventa
        for(i=0;i<strlen(s2);i++) 
            v2[(int)s2[i]-97]++;
        for(i=0;i<27;i++) //verificam daca exista aparitii diferite in cei doi vectori de frecventa
            if(v1[i]!=v2[i])
                return 0;
        return 1;
    }  
}

double compute_grade(char *s1, char *s2) //calculam gradul a doua siruri primite ca parametru
{
    int caract_dif=0,i;
    if(!is_anagram(s1,s2)) //verificam gradul -1
        return -1;
    else
        {
            for(i=0;i<strlen(s1);i++) //parcurgem pozitie cu pozitie si verificam caracterele diferite pentru a le stabili numarul
                if(s1[i]!=s2[i])
                    caract_dif++;
            return (float)caract_dif/(float)strlen(s1); //returnam valoarea gradului
        }
}

int main (void)
{
    int N,i;
    struct perechi p[1001];
    scanf("%d", &N);
    for(i=0;i<N;i++) 
    {
        scanf("%s %s", p[i].cuv1,p[i].cuv2); //citim cuvintele asociate unei perechi
        p[i].grad=compute_grade(p[i].cuv1,p[i].cuv2); //calculam gradul perechii respective
    }
    sort_grad(p,N); //apelam functia de sortare in functie de grad
    sort_lexi(p,N); //apelam functia de sortare lexicografica
    for(i=0;i<N;i++)
        printf("%s %s\n", p[i].cuv1,p[i].cuv2); //afisam perechile de cuvinte in ordinea ceruta
    return 0;
}