#include <iostream>
#include<string.h>
using namespace std;

int main(){
  int a[100][100];
  int b[100][100];
  int c[100][100];

  int n,m,l;

  cin >> n >> m >> l;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
      cout << a[i][j] << endl;
    }
  }
  for(int i = 0; i < m; i++){
    for(int j = 0; j < l; j++){
      cin >> b[j][l];
      cout << b[j][l] << endl;

    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      for(int k = 0; k < l; k++){
        c[i][j] = a[i][j] * b[j][k];
      }
    }
  }


}
