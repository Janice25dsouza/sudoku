#include<iostream>
#include<random>

int i,j,p;
int a[9][9];

int numberGenerator(){
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> dist(1,9);
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
        p = numberGenerator();
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