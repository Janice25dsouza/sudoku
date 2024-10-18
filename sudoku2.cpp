#include<iostream>
#include<random>

int i,j,k,a[9][9],m[9][9],val,n;
int count=22;

void printBoard(){
    std::cout<<" ---+---+---+---+---+---+---+---+---\n";
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            std::cout<<"|";
            if(a[i][j]!=0){
                std::cout<<" "<<a[i][j]<<" ";
            }
            else{
                std::cout<<"   ";
            }
            if(j==8){
                std::cout<<"|";
                std::cout<<"\n";
                std::cout<<" ---+---+---+---+---+---+---+---+---\n";
            }
        }
    }  
}

int numberGenerator(int v1,int v2){
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> dist(v1,v2);
    return dist(eng);
}

void enterVals(){
    while(count!=0){
        i=numberGenerator(0,8);
        j=numberGenerator(0,8);
        if(m[i][j]==0){
            a[i][j]=numberGenerator(1,9);
            m[i][j]=1;
            count--;
        }
    }
}

//for initial validity check
int isValid(){                      
    k=1;
    while(k!=10){
        //for rows
        for(i=0;i<9;i++){            
            count=0;
            for(j=0;j<9;j++){
                if(a[i][j]==k){
                    count++;
                }
                if(count>1){
                    a[i][j]=numberGenerator(1,9);
                    return 1;
                }
            }
        }
        //for columns
        for(j=0;j<9;j++){           
            count=0;
            for(i=0;i<9;i++){
                if(a[i][j]==k){
                    count++;
                }
                if(count>1){
                    a[i][j]=numberGenerator(1,9);
                    return 1;
                }
            }
        }
        //for 3x3 boxes
        int indexval=0;
        int counter=0;
        while(counter!=3){
            j=indexval;
            for(i=0;i<9;i++){
                for(j;j<=indexval+2;j++){
                    if(a[i][j]==k){
                        count++;
                    }
                    if(count>1){
                        a[i][j]=numberGenerator(1,9);
                        return 1;
                    }
                    if((i==2||i==5||i==8)&&(j==(indexval+2))){
                        count=0;
                    }
                }
            }
            indexval+=3;
            counter++;
        }
        

        k++;
    }
    return 0;    
}

int main(){
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            m[i][j]=0;
            a[i][j]=0;
        }
    }
    enterVals();
    int p=1;
    while(p==1){
        p=isValid();
    }
    std::cout<<"NOTE: Enter x to validate your answers\n";
    printBoard();
}