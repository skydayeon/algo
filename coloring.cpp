//
//  main.cpp
//  coloring
//
//  Created by DaYeon on 2016. 11. 21..
//  Copyright © 2016년 SWDY. All rights reserved.
//

#include <iostream>
using namespace std;

bool promising(int i);
void m_coloring(int i,int m);


 
 int W[25][25] ={
 {0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	1,	0,	0,	1,	0,	0,	0,	0},
 {0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0},
 {0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0},
 {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0},
 {0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	1,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
 {1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1,	0,	1,	0,	0,	0,	0,	0,	0,	1},
 {0,	0,	0,	0,	1,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0},
 {0,	0,	0,	0,	1,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
 {0,	0,	1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	1},
 {0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
 {0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	1,	0,	1},
 {0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0},
 {0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,	1,	1,	0,	1,	0},
 {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	0},
 {1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0},
 {1,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1,	0},
 {0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	1},
 {1,	1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
 {0,	0,	0,	1,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0},
 {0,	0,	0,	1,	0,	0,	1,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	1,	0,	1,	0,	0,	0,	0},
 {1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	1,	1,	0,	0,	0,	1,	0,	0,	0,	1,	0},
 {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0},
 {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1,	0,	0,	1,	0,	0,	0,	0,	1,	0,	1,	0},
 {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	1,	0,	0,	0,	0,	1,	0,	1,	0,	0},
 {0,	0,	0,	0,	0,	1,	0,	0,	1,	0,	1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0}
 };


//int W[4][4] = {{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
int n = 25;
int m = 2;


int* vcolor = new int[n];
int num = 0;

int main(){
    while(1){
    cout<<m<<"가지 색상으로 칠할 경우 가능한 조합수 :"<<endl;
    m_coloring(0,m);
    if(num==0)
    {
        cout<<m<<"가지 색으로 칠할 수 없습니다."<<endl<<endl;
        m++;
    }
    else{
        
        cout<<m<<"가지 색상이 최소 색의 개수입니다."<<endl;
        return 0;
    }
    
  }
 
}
    




void m_coloring(int i,int m){
    int color = 0;
    
    if(promising(i)) {
        if(i==n)
        {
            num++;
            
            cout<<num<<endl;
            for(int i = 0; i<n ; i++){
                
               // cout<<i+1<<"번째 구의 색(번호) : "<<vcolor[i]<<endl;
            }
           
        } else {
            for(color = 1 ; color <= m ; color++){
                vcolor[i] = color;
                m_coloring(i + 1,m);
            }
        }
    }
    
}

bool promising(int i){
    int j;
    bool swi;
    
    swi = true;
    j = 1;
    
    while( j < i && swi){
        if(W[i-1][j-1] && vcolor[i-1] == vcolor[j-1])
            swi = false;
        j++;
    }
    return swi;
    
}
