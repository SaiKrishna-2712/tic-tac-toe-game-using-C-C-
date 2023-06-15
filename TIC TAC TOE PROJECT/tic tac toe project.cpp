#include <bits/stdc++.h>
void display(char a[3][3]){
    std::cout<<"                     |      |      "                           <<std::endl;
    std::cout<<"                 "<<a[0][0]<<"   |  "<<a[0][1]<<"   |  "<<a[0][2]<<"   "<<std::endl;
    std::cout<<"               ______|______|______"                           <<std::endl;
    std::cout<<"                     |      |      "                           <<std::endl;
    std::cout<<"                 "<<a[1][0]<<"   |  "<<a[1][1]<<"   |  "<<a[1][2]<<"   "<<std::endl;
    std::cout<<"               ______|______|______"                           <<std::endl;
    std::cout<<"                     |      |      "                           <<std::endl;
    std::cout<<"                 "<<a[2][0]<<"   |  "<<a[2][1]<<"   |  "<<a[2][2]<<"   "<<std::endl;
    std::cout<<"                     |      |      "                           <<std::endl;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void win(char a[3][3],bool *ch){
    if((a[0][0]==a[0][1]&&a[0][0]==a[0][2])||(a[0][0]==a[1][0]&&a[0][0]==a[2][0])||(a[0][0]==a[1][1]&&a[0][0]==a[2][2])){
        switch(a[0][0]){
            case 'X':
            std::cout<<"PLAYER 1 WON THE GAME"<<std::endl;
            *ch =0;
            break;
            case 'O':
            std::cout<<"PLAYER 2 WON THE GAME"<<std::endl;
            *ch =0;
            break;
        }
    }
    if((a[1][1]==a[0][1]&&a[1][1]==a[2][1])||(a[1][1]==a[1][0]&&a[1][1]==a[1][2])||(a[1][1]==a[0][2]&&a[1][1]==a[2][0])){
        switch(a[1][1]){
            case 'X':
            std::cout<<"PLAYER 1 WON THE GAME"<<std::endl;
            *ch =0;
            break;
            case 'O':
            std::cout<<"PLAYER 2 WON THE GAME"<<std::endl;
            *ch =0;
            break;
        }
    }
    if((a[2][2]==a[2][0]&&a[2][2]==a[2][1])||(a[2][2]==a[1][2]&&a[2][2]==a[0][2])){
        switch(a[0][0]){
            case 'X':
            std::cout<<"PLAYER 1 WON THE GAME"<<std::endl;
            *ch =0;
            break;
            case 'O':
            std::cout<<"PLAYER 2 WON THE GAME"<<std::endl;
            *ch =0;
            break;
        }
    }

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(){
    char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    std::cout<<"  ~~~~~~~~~~ T I C  -  T A C  -  T O E ~~~~~~~~~~\n";
    std::cout<<"    PLAYER 1 - [X]\n";
    std::cout<<"    PLAYER 2 - [O]\n";
    display(a);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

   bool check=1;
   int chance =0,choice;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

   while(check){
       int i,j;
       if(chance%2==0){
           std::cout<<"    PLAYER 1's turn : ";
           std::cin>>choice;

         if(choice%3==0){
               j=2;
               i=choice/3-1;
           }
           else{
               j=choice%3-1;
               i=choice/3;
           }
           if(a[i][j]!='X'&&a[i][j]!='O'){
           a[i][j]='X';
           }
           else{
            std::cout<<"                 TRY ANOTHER CHOICE"<<std::endl;
            chance--;
           }
           std::cout<<std::endl;
           display(a);
           if(chance>=2){
               win(a,&check);
           }
       }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

       else{
           std::cout<<"    PLAYER 2's turn : ";
           std::cin>>choice;
           if(choice%3==0){
               j=2;
               i=choice/3-1;
           }
           else{
               j=choice%3-1;
               i=choice/3;
           }
           if(a[i][j]!='X'&&a[i][j]!='O'){
           a[i][j]='O';
           }
           else{
            std::cout<<"                TRY ANOTHER CHOICE"<<std::endl;
            chance--;
           }
           std::cout<<std::endl;
           display(a);
           if(chance>=2){
               win(a,&check);
           }
       }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

       ++chance;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

       if(chance==9){
           check=0;
       }

       }

    return 0;
}