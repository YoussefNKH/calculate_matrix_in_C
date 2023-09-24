#include <stdio.h>
#include <stdlib.h>
void matxvect(){
	    /*declaration*/
    int N,i,j;

    printf("donner NXN du mat :");
    scanf("%d",&N);
    double **mat=(double**)malloc(N*sizeof(double*));
    double *vect=(double*)malloc(N*sizeof(double));
    double *result=(double*)malloc(N*sizeof(double));

    /*test du allocation*/
    if (mat==NULL||vect==NULL||result==NULL){
        printf("ERREUR D'ALLOCATION\n");
        return 1;
    }


    /*remplir du matrice*/
    printf("Donner les element du matrice\n");
    for(i=0;i<N;i++){
        mat[i]=(double*)malloc(N*sizeof(double));
        for(j=0;j<N;j++){
            printf("MATRICE [%d][%d] : ",i+1,j+1);
            scanf("%lf",&mat[i][j]);
        }
    }



    /*remplir du vecteur*/
    printf("Donner les Element du vect\n");
    for(i=0;i<N;i++){
        printf("VECT [%d]",i+1);
        scanf("%lf",vect+i);

    }


    /*La multiplication*/
    for(i=0;i<N;i++){
        *(result+i)=0;
        for(j=0;j<N;j++){
            result[i]+=mat[i][j]*vect[i];
        }
    }

    /*affichage du result*/

    printf("le resultat\n");
    for (i=0;i<N;i++)
    {
        printf("|%.2lf",result[i]);
    }
    printf("|\n");/*dernier colone*/


    /*libere ram*/

    for (i=0;i<N;i++){
        free(mat[i]);
    }
    free(mat);
    free(vect);
    free(result);
}
void mattiranxvect(){
	 int N, i, j;
    printf("Enter the size of the matrix and vector: ");
    scanf("%d", &N);

    double **mat = (double **)calloc(N, sizeof(double *));
    double *vect = (double *)calloc(N, sizeof(double));
    double *result = (double *)calloc(N, sizeof(double));

    if (!mat || !vect || !result) {
        printf("ERREUR D'ALLOCATION");
        return 1;
    }

    for (i = 0; i < N; i++) {
        mat[i] = (double *)calloc(N, sizeof(double));
        j=0;
        while(1){
            printf("\n Donner MAT[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &mat[i][j]);
            if(j==i){
                break;
            }
            j++;
        }
    }

    for (i = 0; i < N; i++) {
        printf("\nDonner VECT[%d]: ", i + 1);
        scanf("%lf", &vect[i]);
    }
    /*affichge du mat */

    for (i=0;i<N;i++){
        for(j=0;j<N;j++){
                    printf("\t MAT[%d][%d] : %lf |",i+1,j+1,mat[i][j]);

        }
        printf("\n");
    }

    for (i = 0; i < N; i++) {
            j=0;
        while(1) {
            result[i] += mat[i][j] * vect[j];
             if(j==i){
                break;
            }
            j++;
        }
    }

    printf("\nRESULTAT: ");
    for (i = 0; i < N; i++) {
        printf("%lf | ", result[i]);
    }
    printf("\n");

    for (i = 0; i < N; i++) {
        free(mat[i]);
    }
    free(mat);
    free(vect);
    free(result);

}
void matxmat(){
	/*declaration des var*/
int N,i,j,k ;

printf("donner le nbr du ligne et col  N : ");
scanf("%d",&N);


double **A=(double **)calloc(N,sizeof(double*));
double **B=(double **)calloc(N,sizeof(double*));
double **result=(double **)calloc(N,sizeof(double*));
/*TEST D'ALLOCATION DYNAMIQUE*/

if(!A||!B||!result){
    printf(" ERREUR D'ALLOCATION");
    return 1;
}

/*remplir A*/
for (i=0;i<N;i++){
        A[i]=(double*)calloc(N,sizeof(double));
    for (j=0;j<N;j++){
        printf("donner A[%d,%d]",i+1,j+1);
        scanf("%lf",&A[i][j]);
        printf("\n");
    }
}
/* remplir B*/
for (i=0;i<N;i++){
        B[i]=(double*)calloc(N,sizeof(double));
    for (j=0;j<N;j++){
        printf("donner B[%d,%d] :",i+1,j+1);
        scanf("%lf",&B[i][j]);
        printf("\n");
    }
}
/*faire la calcule */
for (i=0;i<N;i++){
    result[i]=(double*)calloc(N,sizeof(double));
    for (j=0;j<N;j++){
        for(k=0;k<N;k++){
                result[i][j]=result[i][j]+A[i][k]*B[k][j];
        }
    }
}
/*AFFICHAGE DU RES*/
for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        printf("\tRESULT[%d][%d]:%2.lf |",i+1,j+1,result[i][j]);
    }
    printf("\n");
}
 for (i=0;i<N;i++){
        free(A[i]);
    }
    free(A);

     for (i=0;i<N;i++){
        free(B[i]);
    }
    free(B);
     for (i=0;i<N;i++){
        free(result[i]);
    }
    free(result);

}


int main(){
    int choice;
    printf("******MENU**********\n");
	printf(" 1)MATRIX * VECT\n 2)MATRIX * MATRIX \n 3) LOWER, TRIANGULAR MATRIX\n");
	scanf("%d",&choice);
		switch (choice){
		case 1 :matxvect();
		case 2 :matxmat();
		case 3 :mattiranxvect();
		default :main();
	}
	return 0;
}
