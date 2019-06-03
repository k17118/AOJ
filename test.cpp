#include <iostream>
#include <cmath>
using namespace std;

class Dice{
private:
  int d[6];
public:
  Dice();
  void CreateDice(int n1, int n2, int n3, int n4, int n5, int n6);
  void disp();
  void Roll_The_Dice(int top, int front);
  int get_dice_surface(int n);
  bool compare_dice(Dice dice);
};

Dice::Dice(){
  for(int i = 0; i < 6; i++){
    d[i] = 0;
  }
}
void Dice::CreateDice(int n1, int n2, int n3, int n4, int n5, int n6){
  d[0] = n1;
  d[1] = n2;
  d[2] = n3;
  d[3] = n4;
  d[4] = n5;
  d[5] = n6;
}
void Dice::disp(){
  for(int i = 0; i < 6; i++){
    cout << d[i] << " ";
  }
  cout << endl;
}
void Dice::Roll_The_Dice(int top, int front){
  int tmp;
  int i = 0, count = 0;
  while(true){
    for(i = 0; i < 4; i++){
      if(d[0] == top){
        break;
      }
      tmp  = d[0];
      d[0] = d[4];
      d[4] = d[5];
      d[5] = d[1];
      d[1] = tmp;
    }
    if(d[1] == front && d[0] == top){
      break;
    }
    tmp  = d[3];
    d[3] = d[1];
    d[1] = d[2];
    d[2] = d[4];
    d[4] = tmp;
    i = 0;
    count++;
    if(count >= 3){
      break;
    }
  }
}
int Dice::get_dice_surface(int n){
  return d[n];
}
bool Dice::compare_dice(Dice dice){
  int count = 0;
  for(int i = 0; i < 6; i++){
    if(d[i] == dice.d[i]){
      count++;
    }
  }
  if(count == 6){
    return true;
  } else {
    return false;
  }
}

int main(){
  int n[6],num,h[6];
  int count = 0;
  cin >> num;
  Dice dice[num];

  for(int j = 0; j < num; j++){
    for(int i = 0; i < 6; i++){
      cin >> n[i];
    }
    Dice dice[j];
    dice[j].CreateDice(n[0],n[1],n[2],n[3],n[4],n[5]);
  }

  for(int i = 0; i < num-1; i++){
    for(int j = 0; j < num-1; j++){
      dice[i+1].Roll_The_Dicel_the_Dice(dice[i].get_dice_surface(j),dice[i].get_dice_surface(j+1));
    }
  }

  // for(int i = 0; i < num-1; i++){
  //   for(int j = 0; j < 5; j++){
  //     if((h[j] = dice[i].get_dice_surface(i)) != (h[j+1] = dice[i].get_dice_surface(i+1))){
  //       dice[i].Roll_The_Dice(h[j],h[j+1]);
  //       dice[i+1].Roll_The_Dice(h[j],h[j+1]);
  //       dice[i].disp();
  //       dice[i+1].disp();
  //     }
      // if(!dice[i].compare_dice(dice[i+1])){
      //   count++;
      // }
      // dice[i].disp();
      // dice[i+1].disp();
  //   }
  // }

  if(count == num-1){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  cout << count << endl;
}
