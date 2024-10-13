#include<iostream>
#include<random>

int i,j,p;
int a[9][9],m[9][9];

int numberGenerator(int v1,int v2){
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> dist(v1,v2);
    return dist(eng);
}

void boardValue(){ //to assign values to the board locations
    for(i=0;i<9;i++){
        for(j=0;j<9;j++)
            a[i][j]=randomVal();
    }
}

int randomVal(){
    while(1){
        p = numberGenerator(1,9);
        if(isValid(p))
            return p;
    }
}

int isValid(int val){ // to check if values generated ar valid
    int x,y;
    for(x=0;x<j;x++){
        if(val==a[i][x])
            return 0;
    }
    for(x=0;x<i;x++){
        if(val==a[x][j])
            return 0;
    }
    for(x=i;x<(i+3);x++){
        for(y=j;y<(j+3);y++){
            if(val==a[x][y])
                return 0;
        }
        if(x!=(i+2))
            y=j;
    }
    return 1;
}

void decider(){ //to decide if a value has to be printed or not
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            int val = numberGenerator(1,4);
            if(val == 1)
                m[i][j]=1;
        }
    }
}

void printBoard(){
    cout<<" ---+---+---+---+---+---+---+---+---\n";
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            cout<<" | ";
            if(m[i][j]==1)
                cout<<a[i][j];
            cout<<" | ";
            if(j==8){
                cout<<"\n";
                cout<<" ---+---+---+---+---+---+---+---+---\n";
            }
        }
    }  
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
    cout<<"Your game starts here: \n";
    printBoard();
    
}