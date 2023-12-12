#include <iostream>
using namespace std;

char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='x';
int row,column;
bool tie=0;
string n1,n2;

void board()
{
 cout<<"    |    |  "<<endl;
 cout<<"  "<<arr[0][0]<<" |  "<<arr[0][1]<<" |  "<<arr[0][2]<<"  "<<endl;
 cout<<"____|____|____"<<endl;
 cout<<"    |    |  "<<endl;
 cout<<"  "<<arr[1][0]<<" |  "<<arr[1][1]<<" |  "<<arr[1][2]<<"  "<<endl;
 cout<<"____|____|____"<<endl;
 cout<<"    |    |  "<<endl;
 cout<<"  "<<arr[2][0]<<" |  "<<arr[2][1]<<" |  "<<arr[2][2]<<"  "<<endl;
 cout<<"    |    |  "<<endl;
}

void display(){
  int digit;
  if (turn=='x'){
    cout<<"Enter the position you want to play "<<n1<<endl;
    cin>>digit;
  }
  if(turn=='o'){
    cout<<"Enter the position you want to play "<<n2<<endl;
    cin>>digit;
  }
  if(digit>=1 && digit<=9){
  if(digit==1){
    row=0;
    column=0;
  }
  else if(digit==2){
    row=0;
    column=1;
  }
  else if(digit==3){
    row=0;
    column=2;
  }
  else if(digit==4){
    row=1;
    column=0;
  }
  else if(digit==5){
    row=1;
    column=1;
  }
  else if(digit==6){
    row=1;
    column=2;
  }
 else if(digit==7){
    row=2;
    column=0;
  }
 else if(digit==8){
    row=2;
    column=1;
  }
  else if(digit==9){
    row=2;
    column=2;
  }
  if(turn=='x' && arr[row][column]!='x' && arr[row][column]!='o'){
    arr[row][column]='x';
    turn='o';
  }
  else if(turn=='o' && arr[row][column]!='x' && arr[row][column]!='o'){
    arr[row][column]='o';
    turn='x';
  }
  else{
    cout<<"This is an occupied space!!"<<endl;
    display();
  } }
  else{
    cout<<"INVALID MOVE !!!"<<endl;
    display();
  }
}
bool windraw(){
    for(int i=0;i<3;i++){
      if(arr[i][0]==arr[i][1] && arr[i][0]==arr[i][2] || arr[0][i]==arr[1][i] && arr[0][i]==arr[2][i]){
        return 1;
      }
      if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] || arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0]){
        return 1;
      }
    }  
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(arr[i][j]!='x' && arr[i][j]!='o'){
          return 0;
        }
      }
    }
    tie=1;
    return 1;
}
void resetgame(){
  for (int i = 0; i < 3; i++) {
   
       for (int j = 0; j < 3; j++) {
         arr[i][j] = '0' + (i * 3 + j + 1);
          }
}
turn='x';
tie=0;
}

int main(){
  cout<<"*********Tic Tac Toe Game*********"<<endl;
  cout<<endl;
  cout<<"Enter first player name: ";
  cin>>n1;
  cout<<"Enter the second player name: ";
  cin>>n2;
  cout<<n1<<" will play first as x"<<endl;
  cout<<n2<<" will play second as o"<<endl;
  
  bool rematch=1;
  while(rematch){
    resetgame();
  while(!windraw()){
    board();    
    display();
    windraw();
  }
  if(turn=='x'&& tie == 0){
    cout<<n2<<" wins!"<<endl;
  }
  else if(turn=='o'&& tie ==0){
    cout<<n1<<" wins!"<<endl;
  }
  else{
    cout<<"It's a draw"<<endl;
  }
  cout<<"Do you want to play again?"<<endl;
  cout<<"1 for yes , 0 for no"<<endl;
  cin>>rematch;
  }
  };