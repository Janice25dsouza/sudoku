#include<iostream>
#include<random>

int i,j,p,row,col,v;
int a[9][9],m[9][9];

int numberGenerator(int v1,int v2){
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> dist(v1,v2);
    return dist(eng);
}

int isValid(int val){ // to check if values generated ar valid
    int x,y;
    for(x=0;x<j;x++){
        if(val==a[i][x]){
            return 0;
        }
    }
    for(x=0;x<i;x++){
        if(val==a[x][j]){
            return 0;
        }
    }
    for(x=i;x<(i+3);x++){
        for(y=j;y<(j+3);y++){
            if(val==a[x][y]){
                return 0;
            } 
        }
        if(x!=(i+2)){
            y=j;
        }   
    }
    return 1;
}

int randomVal(){
    while(1){
        p = numberGenerator(1,9);
        if(isValid(p)){
            return p;
        }    
    }
}

void boardValue(){ //to assign values to the board locations
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            a[i][j]=randomVal();
        } 
    }
}

void decider(){ //to decide if a value has to be printed or not
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            int val = numberGenerator(1,4);
            if(val == 1){
                m[i][j]=1;
            }
        }
    }
}

void printBoard(){
    std::cout<<" ---+---+---+---+---+---+---+---+---\n";
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            std::cout<<" | ";
            if(m[i][j]==1){
                std::cout<<a[i][j];
            }
            std::cout<<" | ";
            if(j==8){
                std::cout<<"\n";
                std::cout<<" ---+---+---+---+---+---+---+---+---\n";
            }
        }
    }  
}

bool checkOnes(){
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(m[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            m[i][j]=0;
        }
        j=0;
    }
    boardValue();
    decider();
    std::cout<<"Your game starts here: \n";
    std::cout<<"Note: the values of the rows and columns range from 0 to 8\n";
    while(checkOnes()){
        printBoard();
        std::cout<<"Enter the row:\n";
        std::cin>>row;
        std::cout<<"Enter the column:\n";
        std::cin>>col;
        std::cout<<"Enter the value:\n";
        std::cin>>v;
        if(i<0 || i>8 || j<0 || j>8 || v<1 || v>9){
            std::cout<<"Invalid entries\n";
        }
        else{
            if(a[i][j]==1){
                m[i][j]=1;
                std::cout<<"You've entered a correct value!!!\n";
            }
            else{
                std::cout<<"Invalid entry";
            }
        } 
    }
    std::cout<<"Game Over!!!\n"; 
}