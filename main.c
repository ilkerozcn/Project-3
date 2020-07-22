#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <math.h>
struct sehir
{
    int plaka;
    char isim[20];
    char bolge[3];
    int komsu[20];
    int komsusay;
    struct sehir * next;
    struct sehir * prev;
    struct komsu *yanlama;
};
typedef struct sehir sehirnode;
struct komsu
{
    int komsupl;
    struct komsu * nekst;

};
typedef struct komsu komsunode;

sehirnode  * ekle(sehirnode *r2,int y,char *name,char *region)
{
    sehirnode* bas=(sehirnode*)malloc(sizeof(sehirnode));
    bas=r2;
    sehirnode *ekl;
    ekl=(sehirnode*)malloc(sizeof(sehirnode));
    ekl->prev=NULL;
    ekl->next=NULL;
    strcpy(ekl->isim,name);
    strcpy(ekl->bolge,region);
    ekl->plaka=y;
    r2->prev=NULL;
    int j=1;
 while( j=1){
 if(r2->plaka==y || strcmp(r2->isim,name)==0 ){
    printf("Eklemek İstedğiniz Şehir Listede Var");
   // printf("sdasdasd");
    return bas;
    break;
 }

else{
  if(y<r2->plaka && y>r2->prev->plaka && y!=1)///ortaya ekleme
{
 ekl->next=r2;
 r2->prev->next=ekl;
 ekl->prev=r2->prev;
 r2->prev=ekl;
 /*while(r2->prev!=NULL)
 {
   r2=r2->prev;
   bas=r2;
 }*/
 return bas;
 break;
}
  else if(y<r2->plaka ){///başa ekleme
    r2->prev=ekl;
    ekl->next=r2;
    ekl->prev=NULL;
    return ekl;
    break;
 }

 else if(y>r2->plaka && r2->next==NULL)///sona ekleme
 {
  r2->next=ekl;
  ekl->prev=r2;
  ekl->next=NULL;
  return bas;
  break;
  }



}
r2=r2->next;
 }
}

sehirnode * sil(sehirnode *r1,char*name2){
    sehirnode *temp;
    sehirnode  *gez=r1;
    r1->prev=NULL;

while(r1->next!=NULL)
{
    if(strcmp(r1->isim,name2)==0)
    {
     if(r1->prev==NULL)
     {
         //printf("dsasdasd");
      sehirnode *gez1=r1->next;
       free(r1);
       gez1->prev=NULL;
printf("Basariyla silindi\n");

       return gez1;


     }
     else if(r1->prev!=NULL && r1->next!=NULL)
     {
      r1->prev->next=r1->next;
      r1->next->prev=r1->prev;
       printf("Basariyla silindi\n");
      return gez;

     }
     else if(r1->next==NULL)
     {
      r1->prev->next=NULL;
      r1->prev=NULL;
      printf("Basariyla silindi");
      return gez;
     }
    }
r1=r1->next;
}
}
void komsu_ekle(sehirnode *r,char *name){
    printf("KOMSU PLAKALARI:  ");
while(r!=NULL)
    {
        if(strcmp(r->isim,name)==0)
        {
            int temp;
           for(int i=0;i<r->komsusay;i++)
            printf("%d ",r->komsu[i]);
            printf("\n");
            printf("EKLENECEK KOMSU PLAKASINI YAZINIZ: \n");
            int a;
            scanf("%d",&a);
            r->komsu[r->komsusay]=a;
            r->komsusay=r->komsusay+1;//printf("%d",r->komsusay);
               for(int i=0;i<r->komsusay;i++){
            for(int k=0;k<r->komsusay-1;k++)
            {
                if((r->komsu[k])>(r->komsu[k+1])){
                    temp=r->komsu[k];
                    r->komsu[k]=r->komsu[k+1];
                    r->komsu[k+1]=temp;

                }

            }
        }
            break;
        }
        r=r->next;
    }
}
void komsu_sil(sehirnode *r,char *name){
    printf("KOMSU PLAKALARI:  \n");
    int x;
    int a=0;
int t=1;
while(r!=NULL)
    {
        if(strcmp(r->isim,name)==0)
        {
           for(int i=0;i<r->komsusay;i++)
            printf("%d ",r->komsu[i]);
            printf("\n");
            printf("SILINECEK KOMSU PLAKASINI YAZINIZ: \n");
            scanf("%d",&x);
            while(1){

                if(r->komsu[a]==x)
                    break;
            a++;
            }
            for(int i=0;i<r->komsusay;i++){

		if(i>=a){
			r->komsu[i]=r->komsu[i+1];
            }
            }
            r->komsusay=r->komsusay-1;
            break;
        }
        r=r->next;
    }




}
void listele(sehirnode *r,int a)
{
    for(int i=0; i<a-1; i++)
    {
        printf("Plaka: %d Sehir Ad: %s  Bolge: %s Komsu Sayisi: %d\n",r->plaka,r->isim,r->bolge,r->komsusay);
        printf("Komsu Plakalari:  ");
        for(int j=0; j<(r->komsusay); j++)
            printf("%d ",r->komsu[j]);
        printf("\n");
        r=r->next;
    }

}
void bolge_listele(sehirnode *r,char *bolge,int a){

    for(int i=0; i<a-1;i++){
        if(strcmp(r->bolge,bolge)==0)
            printf("Plaka: %d Sehir Ad: %s  Bolge: %s Komsu Sayisi: %d\n",r->plaka,r->isim,r->bolge,r->komsusay);
        r=r->next;

    }}
void komsuyagore_listele(sehirnode *r,int x,int a){
    for(int i=0; i<a-1;i++){
        if((r->komsusay)>x)
            printf("Plaka: %d Sehir Ad: %s  Bolge: %s Komsu Sayisi: %d\n",r->plaka,r->isim,r->bolge,r->komsusay);
        r=r->next;

    }



}
int komsu_atama(sehirnode *a,char *name)
{

    while(a!=NULL)
    {
        if(strcmp(a->isim,name)==0)
        {
            return a->plaka;
        }
        a=a->next;
    }


}
void isim_arama(sehirnode *r,char *name)
{   sehirnode * fonk=r;
int kod=0;
   // printf("%s",name);
    while(r!=NULL)
    {
        if(strcmp(r->isim,name)==0 )
        {
            printf("Aranan Sehir Listede Var\n");
            printf("Plaka :%d\t",r->plaka);
            printf("Sehir :%s\t",r->isim);
            printf("Bolge :%s\t",r->bolge);
            printf("Komsularinin Bilgileri:  ");
            for(int i=0;i<r->komsusay;i++)
                printf("%d ",r->komsu[i]);
                kod=1;
            break;


        }




       /* else{
         printf("Sehir Listede Yok");
         printf("Eklemek İçin 1 e Basınız");
         int secim;
         scanf("%d",&secim);
         if(secim==1)
         {



         }



        }*/
        r=r->next;
    }
    if(kod=0){
    printf("Sehir Listede Yok");
         printf("Eklemek İçin 1 e Basınız");
         int secim;
         scanf("%d",&secim);
         if(secim==1)
         {
          int eklplk2;
          char eklada[20];
          char eklblg[20];
          printf("EKLEMEK ISTEDIGINIZ SEHRIN PLAKA ISIM VE BOLGE BILGILERINI GIRINIZ");
          scanf("%d",&eklplk2);
          scanf("%s",&eklada);
          scanf("%s",&eklblg);
          fonk=ekle(fonk,eklplk2,eklada,eklblg);



         }}
}
void plaka_arama(sehirnode *r,int x){
    sehirnode * fonk=r;
    int kod=0;
  while(r!=NULL)
    {
        if(r->plaka==x )
        {
            printf("Aranan Sehir Listede Var\n");
            printf("Plaka :%d\t",r->plaka);
            printf("Sehir :%s\t",r->isim);
            printf("Bolge :%s\t",r->bolge);
            printf("Komsularinin Plakalari: ");
            for(int i=0;i<r->komsusay;i++)
                printf("%d ",r->komsu[i]);
                kod=1;
            break;


        }
       /* else{
         printf("Sehir Listede Yok");
         printf("Eklemek İçin 1 e Basınız");
         int secim;
         scanf("%d",&secim);
         if(secim==1)
         {



         }



        }*/
        r=r->next;
    }if(kod==0){
printf("Sehir Listede Yok");
         printf("Eklemek İçin 1 e Basınız");
         int secim;
         scanf("%d",&secim);
         if(secim==1)
         {
          int eklplk2;
          char eklada[20];
          char eklblg[20];
          printf("EKLEMEK ISTEDIGINIZ SEHRIN PLAKA ISIM VE BOLGE BILGILERINI GIRINIZ");
          scanf("%d",&eklplk2);
          scanf("%s",&eklada);
          scanf("%s",&eklblg);
          fonk=ekle(fonk,eklplk2,eklada,eklblg);



         }}
}
    int main()
    {   int as;
        FILE*cikti=fopen("cikti.txt","w");
    int temp;
    int count=0;
    int j;
    char str1[20];
    komsunode *komsu1;
    komsu1=(komsunode*)malloc(sizeof(komsunode));
    sehirnode*sehir2;
    sehir2=(sehirnode*)malloc(sizeof(sehirnode));
    sehirnode * sehir1;
    sehir1=(sehirnode*)malloc(sizeof(sehirnode));
    sehirnode* root;
    root=(sehirnode*)malloc(sizeof(sehirnode));
    sehirnode* root2;
    root2=(sehirnode*)malloc(sizeof(sehirnode));
    sehirnode *sehir12;
    sehirnode* son;
    son=(sehirnode*)malloc(sizeof(sehirnode));
    sehirnode * iter;
    iter=(sehirnode*)malloc(sizeof(sehirnode));
    sehir1->prev=NULL;
    sehir1->next=NULL;
    int tmp;
    char * pch;
    char *ph;
    char str[100];
    FILE *s =fopen("sehirler.txt","r");
    int komsusayi;
    fscanf(s,"%s",str);
    // trim(str);
    komsusayi=0;
    pch = strtok (str,",");
    sehir2->plaka=atoi(pch);
    pch = strtok (NULL, ",");
    strcpy(sehir2->isim,pch);
    pch = strtok (NULL, ",");
    strcpy(sehir2->bolge,pch);
    //printf("%d  %s  %s \n",sehir2->plaka,sehir2->isim,sehir2->bolge);
    while (pch != NULL)
    {
        pch = strtok (NULL, ",");
        if(pch==NULL)
            break;

        //  printf("%s ",pch);


        komsusayi++;
    }
    // printf("%d  \n",komsusayi);
    sehir2->komsusay=komsusayi;
    root=sehir2;
    sehir2->next=(sehirnode*)malloc(sizeof(sehirnode));
    sehir2=sehir2->next;




    // sehir1->komsu=(komsunode*)malloc(sizeof(komsunode));
    for(int i=1; i<81; i++)
    {
        fscanf(s,"%s",str);
        //trim(str);
        komsusayi=0;
        pch = strtok (str,",");
        sehir2->plaka=atoi(pch);
        pch = strtok (NULL, ",");
        strcpy(sehir2->isim,pch);
        pch = strtok (NULL, ",");
        strcpy(sehir2->bolge,pch);
    while (pch !=NULL)
        {
            j=0;
            pch = strtok (NULL, ",");

            if(pch==NULL)
                break;
            komsusayi++;

        }

        sehir2->komsusay=komsusayi;

        sehir2->next=(sehirnode*)malloc(sizeof(sehirnode));
        sehir2=sehir2->next;

    }
    fseek(s, 0, SEEK_SET);

    root2=sehir1;
    sehir1->prev=(sehirnode*)malloc(sizeof(sehirnode));
    sehir1->prev=NULL;
    root2->prev=NULL;

    for(int i=1; i<82; i++)
    {
        fscanf(s,"%s",str);
        sehir1->yanlama=(komsunode*)malloc(sizeof(komsunode));
        komsusayi=0;
        pch = strtok (str,",");
        sehir1->plaka=atoi(pch);
        pch = strtok (NULL, ",");
        strcpy(sehir1->isim,pch);
        pch = strtok (NULL, ",");
        strcpy(sehir1->bolge,pch);
        j=0;





        while (pch !=NULL)
        {

            pch = strtok (NULL, ",");

            if(pch==NULL)
                break;
            komsusayi++;


            sehir1->komsu[j]=komsu_atama(root,pch);
            as=sehir1->komsu[j];
            sehir1->yanlama->komsupl= as;
            j++;
          //  printf("%d ",sehir1->yanlama->komsupl);
            sehir1->yanlama->nekst=(komsunode*)malloc(sizeof(komsunode));
            sehir1->yanlama=sehir1->yanlama->nekst;
        }
        sehir1->komsusay=komsusayi;
        for(int i=0;i<(komsusayi);i++){
            for(int k=0;k<(komsusayi)-1;k++)
            {
                if((sehir1->komsu[k])>(sehir1->komsu[k+1])){
                    temp=sehir1->komsu[k];
                    sehir1->komsu[k]=sehir1->komsu[k+1];
                    sehir1->komsu[k+1]=temp;

                }

            }
        }
        for(int a=0;a<(sehir1->komsusay);a++){
           // printf("%d ",sehir1->komsu[a]);


        sehir1->next=(sehirnode*)malloc(sizeof(sehirnode));

        sehir12=(sehirnode*)malloc(sizeof(sehirnode));
        sehir12=sehir1;
        sehir1=sehir1->next;
        sehir1->prev=sehir12;
        sehir1->next=NULL;
        son=sehir1;

        count++;
    }}

    iter=root;
    for(int i=1; i<81; i++)
    {
        iter=iter->next;


        son=iter;
    }

    //root->sehirbilgileri
    //root2->komsu plakaları

        //bolge_listele(root2,root2->next->bolge,count);
        //printf("**\n");
        //komsuyagore_listele(root2,5,count);

   //  root2=sil(root2,"Karabuk");
        sehirnode *yaz=root2;
        sehirnode *kom=root2;
        /*  while(yaz!=NULL)
        {
       //  printf("%s\n",yaz->isim);
         yaz=yaz->next;
        }*/
//printf("***\n");
        sehirnode * yaz2=root2;
      //  yaz2=ekle(root2,82,"Musul","KA");

     /*   while(yaz2!=NULL)
       {
       //  printf("%s\n",yaz2->isim);
         yaz2=yaz2->next;
        }*/
//kom->yanlama->komsupl=1;
printf("SECIM YAPINIZ\n");
printf("1) SEHIR SIL\n");
printf("2) SEHIR EKLE\n");
printf("3) KOMSU EKLE\n");
printf("4) KOMSU SIL\n");
printf("5) BOLGELERE GORE SEHIR ARA\n");
printf("6) KOMSU SAYILARINA GORE SEHIR ARAMA\n");
printf("7) PLAKAYA GORE SEHIR ARAMA\n");
printf("8) ISME GORE SEHIR ARAMA\n");
printf("0) CIKIS");
int secim2;
char silme[20];
char eklead[20];
char ekleblg[20];
char arablg[20];
int ekleplk;

while(secim2!=0){scanf("%d",&secim2);
if(secim2==1)
{
 printf("SILINECEK SEHRIN ISMINI GIRINIZ:  ");
 scanf("%s",&silme);
 root2=sil(root2,silme);
printf("\n0) CIKIS");
}
if(secim2==2)
{
  printf("EKLENECEK OLAN SEHRIN PLAKASINI ISMINI VE BOLGESINI GIRINIZ:  ");
  scanf("%d",&ekleplk);
  scanf("%s",&eklead);
  scanf("%s",&ekleblg);
  root2=ekle(root2,ekleplk,eklead,ekleblg);
printf("\n0) CIKIS");
}
if(secim2==3)
{
    printf("KOMSU EKLENECEK SEHRIN ISMINI GIRINIZ:  ");
    char ad1[20];
    scanf("%s",&ad1);
    komsu_ekle(root2,ad1);
    printf("\n0) CIKIS");
}
if(secim2==4)
{
    printf("KOMSU SILINECEK SEHRIN ISMINI GIRINIZ:  ");
    char ad1[20];
    scanf("%s",&ad1);
    komsu_sil(root2,ad1);
    printf("\n0) CIKIS");
}
if(secim2==5)
{
 printf("ILLERI LISTELENECEK BOLGENIN KODUNU GIRINIZ:  ");
 scanf("%s",&arablg);
 bolge_listele(root2,arablg,count);
 printf("\n0) CIKIS");
}
if(secim2==6)
{
 printf("KOMSU SAYILARINI GIRINIZ:  ");
 int k;
 scanf("%d",&k);
 komsuyagore_listele(root2,k,count);
 printf("\n0) CIKIS");
}
if(secim2==7){
        int l;
    printf("Arancak sehrin plakasi:  ");
    scanf("%d",&l);

    plaka_arama(root2,l);
printf("\n0) CIKIS");

}
if(secim2==8){
    char ara[20];
    printf("Arancak sehrin adi:  ");
    scanf("%s",&ara);
    isim_arama(root2,ara);
printf("\n0) CIKIS");

}




}
while(yaz!=NULL)
        {
       fprintf(cikti,"%d,%s,%s",yaz->plaka,yaz->isim,yaz->bolge);
       for(int i=0;i<(yaz->komsusay);i++){
        fprintf(cikti," -> %d ",yaz->komsu[i]);
     //   printf("\n");
        }fprintf(cikti,"\n");
        fprintf(cikti,"    |     \n");
        fprintf(cikti,"    V     \n");
         yaz=yaz->next;
        }


    return 0;
}
