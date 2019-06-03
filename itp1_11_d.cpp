#include <iostream>
using namespace std;

class Dice{
private:
  int d[6];
public:
  Dice();
  void CreateDice(int n1, int n2, int n3, int n4, int n5, int n6);
  void disp();
  int get_sum();
  void  Roll_The_Dice(int top, int front);
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
int Dice::get_sum(){
  return d[0]+d[1]+d[2]+d[3]+d[4]+d[5];
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
  int n[6],num,h[128];
  bool same = false;
  cin >> num;
  Dice dice[128];

  for(int i = 0; i < num; i++){
    for(int j = 0; j < 6; j++){
      cin >> n[j];
    }
    dice[i].CreateDice(n[0],n[1],n[2],n[3],n[4],n[5]);
  }

  for(int i = 0; i < num-1; i++){
    for(int j = 0; j < 5; j++){
      h[i] = dice[i].get_dice_surface(j);
      h[i+1] = dice[i].get_dice_surface(j+1);
      if( h[i] != h[i+1] ){
        dice[0].Roll_The_Dice(h[i],h[i+1]);
        dice[i+1].Roll_The_Dice(h[i],h[i+1]);
      }
      if( dice[0].compare_dice(dice[i+1]) ){
        same = true;
      }
    }
  }

  if(same){
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
